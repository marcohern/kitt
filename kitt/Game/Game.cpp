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
#include "../Content/FileReader.hpp"
#include "../Graphics/SdlWindow.hpp"

#include "../Core/TrigonometryFactory.hpp"
#include "../Exceptions/KittException.hpp"

namespace Game {
	using namespace Core;
	using namespace Content;
	using namespace Graphics;
	using namespace Exceptions;
    
	Game::Game() {
        
    }
    
	Game::~Game() {
        delete trigonometry;
        delete time;
		delete reader;
		delete window;
    }

	void Game::init() {
		if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) < 0)
		{
			throw KittException("Unable to initialize SDL.");
		}
		trigonometry = TrigonometryFactory::create(TRIGO_TYPE);
		time = TimeFactory::create();
		reader = new FileReader();
		window = new SdlWindow(TITLE, 800, 600, false);
		renderer = window->getRenderer();
	}

	void Game::update() {

	}

	void Game::draw() {
		SDL_Rect rect;
		rect.w = 200;
		rect.h = 200;
		rect.x = window->w() / 2 - (rect.w / 2);
		rect.y = window->h() / 2 - (rect.h / 2);
		SdlRenderer *r = (SdlRenderer*)renderer;
		SDL_SetRenderDrawColor(r->getRenderer(), 0x00, 0x00, 0xFF, 0xff);
		SDL_RenderClear(r->getRenderer());

		SDL_SetRenderDrawColor(r->getRenderer(), 0xff, 0xff, 0x00, 0xff);
		SDL_RenderFillRect(r->getRenderer(), &rect);
		SDL_RenderPresent(r->getRenderer());
	}

	void Game::onevent(SDL_Event *ev) {
		switch (ev->type)
		{
		case SDL_QUIT:
			running = false;
			break;

		case SDL_KEYDOWN:
		{
			if (ev->key.keysym.sym == SDLK_ESCAPE)
			{
				running = false;
			}
		}
		}
	}

	void Game::run() {
		this->init();

		SDL_Event ev;
		running = true;

		while (running)
		{
			if (SDL_PollEvent(&ev) != 0) {
				onevent(&ev);
			}
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

	Vector2D Game::createVector2D() {
		return Vector2D(trigonometry);
	}

	Vector2D Game::createVector2D(double x, double y) {
		return Vector2D(x, y, trigonometry);
	}

	Vector2D Game::createVector2D(const Vector2D &v) {
		return Vector2D(v, trigonometry);
	}
}
