//
//  Directable.cpp
//  kitt
//
//  Created by Marco Hernandez on 3/07/17.
//  Copyright © 2017 Marco Hernandez. All rights reserved.
//

#include "_Directable.hpp"
#include "TimeInjector.hpp"


namespace Core {

	Directable::Directable()
		: Placeable(), Animateable(), direction() {
	}
	Directable::Directable(double x, double y)
		: Placeable(x, y), Animateable(), direction() {
	}
	Directable::Directable(double x, double y, double dx, double dy)
		: Placeable(x, y), Animateable(), direction(dx, dy) {
	}
	Directable::Directable(const Vector2D &loc)
		: Placeable(loc), Animateable(), direction() {
	}
	Directable::Directable(const Vector2D &loc, const Vector2D &dir)
		: Placeable(loc), Animateable(), direction(dir) {
	}
    
    Directable::Directable(Trigonometry *trigo)
		: Placeable(trigo), Animateable(), direction(trigo) {
    }
    Directable::Directable(double x, double y, Trigonometry *trigo)
		: Placeable(x,y,trigo), Animateable(), direction(trigo) {
    }
    Directable::Directable(double x, double y, double dx, double dy, Trigonometry *trigo)
		: Placeable(x, y, trigo), Animateable(), direction(dx, dy, trigo) {
    }
    Directable::Directable(const Vector2D &loc, Trigonometry *trigo)
		: Placeable(loc,trigo), Animateable(), direction(trigo) {
    }
    Directable::Directable(const Vector2D &loc, const Vector2D &dir, Trigonometry *trigo)
		: Placeable(loc,trigo), Animateable(), direction(dir, trigo) {
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

	void Directable::update(double interval) {
		location.add(interval * direction);
	}
}
