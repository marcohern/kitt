//
//  Directable.cpp
//  kitt
//
//  Created by Marco Hernandez on 3/07/17.
//  Copyright © 2017 Marco Hernandez. All rights reserved.
//

#include "Directable.hpp"
#include "TimeInjector.hpp"

namespace Core {
    using namespace Exceptions;

	Directable::Directable()
		: Placeable(), Animateable(TimeInjector::inject()), direction() {
	}
	Directable::Directable(double x, double y)
		: Placeable(x, y), Animateable(TimeInjector::inject()), direction() {
	}
	Directable::Directable(double x, double y, double dx, double dy)
		: Placeable(x, y), Animateable(TimeInjector::inject()), direction(dx, dy) {
	}
	Directable::Directable(const Vector2D &loc)
		: Placeable(loc), Animateable(TimeInjector::inject()), direction() {
	}
	Directable::Directable(const Vector2D &loc, const Vector2D &dir)
		: Placeable(loc), Animateable(TimeInjector::inject()), direction(dir) {
	}
    
    Directable::Directable(Trigonometry *trigo, Time *time)
		: Placeable(trigo), Animateable(time), direction(trigo) {
    }
    Directable::Directable(double x, double y, Trigonometry *trigo, Time *time)
		: Placeable(x,y,trigo), Animateable(time), direction(trigo) {
    }
    Directable::Directable(double x, double y, double dx, double dy, Trigonometry *trigo, Time *time)
		: Placeable(x, y, trigo), Animateable(time), direction(dx, dy, trigo) {
    }
    Directable::Directable(const Vector2D &loc, Trigonometry *trigo, Time *time)
		: Placeable(loc,trigo), Animateable(time), direction(trigo) {
    }
    Directable::Directable(const Vector2D &loc, const Vector2D &dir, Trigonometry *trigo, Time *time)
		: Placeable(loc,trigo), Animateable(time), direction(dir, trigo) {
    }
    
    Directable::~Directable() {
        Placeable::~Placeable();
    }
    
    Vector2D Directable::getDirection() {
        return this->direction;
    }
    
    void Directable::setDirection(double dx, double dy) {
        this->direction.set(dx, dy);
    }
    
    void Directable::setDirection(const Core::Vector2D &dir) {
        this->direction.set(dir);
    }

	void Directable::addDirection(double dx, double dy) {
		this->direction.add(dx, dy);
	}

	void Directable::addDirection(const Vector2D &v) {
		this->direction.add(v);
	}

	void Directable::update() {
		location.add(time->getDelta() * direction);
	}
}
