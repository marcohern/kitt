//
//  Injector.cpp
//  kitt
//
//  Created by Marco Hernandez on 1/07/17.
//  Copyright © 2017 Marco Hernandez. All rights reserved.
//

#include "Injector.hpp"
#include "../Core/TrigonometryFactory.hpp"
#include "../Core/Trigonometry.hpp"
#include "../Core/TimeFactory.hpp"
#include "../Core/Vector2D.hpp"
#include "../Content/IReader.hpp"
#include "../Content/FileReader.hpp"

namespace Game {
	using namespace Core;
	using namespace Content;

    Injector *Injector::instance = NULL;
    
    Injector::Injector() {
        trigonometry = TrigonometryFactory::create(TRIGO_TYPE);
        time = TimeFactory::create();
		reader = new FileReader();
    }
    
    Injector::~Injector() {
        delete trigonometry;
        delete time;
    }
    
    Injector *Injector::get() {
        if (instance== NULL) {
            instance = new Injector();
        }
        return instance;
    }
    
    Trigonometry *Injector::getTrigonometry() {
        return trigonometry;
    }
    
    Time *Injector::getTime() {
        return time;
    }

	IReader *Injector::getReader() {
		return reader;
	}

	Vector2D Injector::createVector2D() {
		return Vector2D(trigonometry);
	}

	Vector2D Injector::createVector2D(double x, double y) {
		return Vector2D(x, y, trigonometry);
	}

	Vector2D Injector::createVector2D(const Vector2D &v) {
		return Vector2D(v, trigonometry);
	}
}
