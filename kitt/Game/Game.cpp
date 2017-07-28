//
//  Injector.cpp
//  kitt
//
//  Created by Marco Hernandez on 1/07/17.
//  Copyright © 2017 Marco Hernandez. All rights reserved.
//

#include "Game.hpp"

#include "../Core/Trigonometry.hpp"
#include "../Core/Vector2D.hpp"
#include "../Content/IReader.hpp"
#include "../Content/SdlFileReader.hpp"
#include "../Graphics/SdlWindow.hpp"
#include "../Input/SdlSignalManager.hpp"

#include "../Core/TimeInjector.hpp"
#include "../Exceptions/KittException.hpp"
#include "../constants.hpp"

namespace Game {
	using namespace Core;
	using namespace Content;
	using namespace Graphics;
	using namespace Input;
	using namespace Exceptions;
    
	Game::Game()
	{
        
    }
    
	Game::~Game() {
		delete signalm;
        delete time;
		delete reader;
		delete window;
		delete font;
    }

	void Game::init() {
		signalm = new SdlSignalManager();
        v1.setLocation(500,250);
        v1.setDirection(20, 40);
        v1.setRotationRate(TAU);
		v1.setRotateDirection(true);
		time = TimeInjector::inject();
		window = new SdlWindow(TITLE, 1280, 720, false);
		renderer = window->getRenderer();
		reader = new SdlFileReader("/content", renderer, false);
		font = reader->readSurface("/fonts/courier.bmp");
	}

	void Game::update() {
        v1.updateTransform(time->getDelta());
		Signal *signals = signalm->getSignals();
		onevent(signals);
		
	}

	void Game::draw() {
		renderer->clear();

		renderer->texture(Vector2D(0,0),font);
        renderer->vector2d(v1.getLocation(), Color::White, v1.getDirection());
		renderer->present();
	}

	void Game::onevent(Signal *signals) {
		if (signals[0].quit) {
			running = false;
		}
	}

	void Game::run() {
		this->init();

		running = true;
		while (running)
		{
			time->update();
			update();
			draw();
		}
	}
    
    Time *Game::getTime() {
        return time;
    }

	IReader *Game::getReader() {
		return reader;
	}
}
