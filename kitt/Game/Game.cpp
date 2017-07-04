//
//  Injector.cpp
//  kitt
//
//  Created by Marco Hernandez on 1/07/17.
//  Copyright © 2017 Marco Hernandez. All rights reserved.
//

#include "Game.hpp"

#include "../Core/Trigonometry.hpp"
#include "../Core/TimeFactory.hpp"
#include "../Core/Vector2D.hpp"
#include "../Content/IReader.hpp"
#include "../Content/FileReader.hpp"
#include "../Graphics/SdlWindow.hpp"

#include "../Core/TrigonometryFactory.hpp"

namespace Game {
	using namespace Core;
	using namespace Content;
	using namespace Graphics;
    
	Game::Game() {
        trigonometry = TrigonometryFactory::create(TRIGO_TYPE);
        time = TimeFactory::create();
		reader = new FileReader();
		window = new SdlWindow(TITLE, 640, 480, false);
    }
    
	Game::~Game() {
        delete trigonometry;
        delete time;
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
