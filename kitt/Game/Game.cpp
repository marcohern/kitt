//
//  Injector.cpp
//  kitt
//
//  Created by Marco Hernandez on 1/07/17.
//  Copyright © 2017 Marco Hernandez. All rights reserved.
//

#include "Game.hpp"

#include "../SDL.h"

#include "../Core/Trigonometry.hpp"
#include "../Core/TimeFactory.hpp"
#include "../Core/Vector2D.hpp"
#include "../Content/IReader.hpp"
#include "../Graphics/SdlFileReader.hpp"
#include "../Graphics/SdlWindow.hpp"
#include "../Input/SdlSignalManager.hpp"

#include "../Core/TrigonometryFactory.hpp"
#include "../Exceptions/KittException.hpp"


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
        delete trigonometry;
        delete time;
		delete reader;
		delete window;
		delete font;
		delete v1;
    }

	void Game::init() {
		if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) < 0)
		{
			throw KittException("Unable to initialize SDL.");
		}
		signalm = new SdlSignalManager();
		trigonometry = TrigonometryFactory::create(TRIGO_TYPE);
		v1 = new Vector2D(100,200,trigonometry);
		time = TimeFactory::create();
		window = new SdlWindow(TITLE, 1280, 720, false, trigonometry);
		renderer = window->getRenderer();
		reader = new SdlFileReader("/content", renderer, false);
		font = reader->readSurface("/fonts/courier.bmp");
	}

	void Game::update() {
		Signal *signals = signalm->getSignals();
		onevent(signals);
		
	}

	void Game::draw() {
		renderer->clear();

		renderer->texture(0,0,font);
		renderer->vector2d(300, 250, 0xFFFFFFFF, *v1);
		v1->rotate(time->getDelta()*0.4);

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
    
    Trigonometry *Game::getTrigonometry() {
        return trigonometry;
    }
    
    Time *Game::getTime() {
        return time;
    }

	IReader *Game::getReader() {
		return reader;
	}
}
