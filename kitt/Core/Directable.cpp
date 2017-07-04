//
//  Directable.cpp
//  kitt
//
//  Created by Marco Hernandez on 3/07/17.
//  Copyright © 2017 Marco Hernandez. All rights reserved.
//

#include "Directable.hpp"
#include "../Exceptions/NullReferenceException.hpp"

namespace Core {
    using namespace Exceptions;
    
    void Directable::setTime(Time *time) {
        if (time==NULL) throw NullReferenceException("Time for Directable cannot be null.");
        this->time = time;
    }
    
    Directable::Directable(Trigonometry *trigo, Time *time)
    : Placeable(trigo), direction(trigo), delta(trigo) {
        this->setTime(time);
    }
    Directable::Directable(double x, double y, Trigonometry *trigo, Time *time)
    : Placeable(x,y,trigo), direction(trigo), delta(trigo) {
        this->setTime(time);
    }
    Directable::Directable(double x, double y, double dx, double dy, Trigonometry *trigo, Time *time)
    : Placeable(x, y, trigo), direction(dx, dy, trigo), delta(trigo) {
        this->setTime(time);
    }
    
    Directable::Directable(const Vector2D &loc, Trigonometry *trigo, Time *time)
    : Placeable(loc,trigo), direction(trigo), delta(trigo) {
        this->setTime(time);
    }
    
    Directable::Directable(const Vector2D &loc, const Vector2D &dir, Trigonometry *trigo, Time *time)
    : Placeable(loc,trigo), direction(dir, trigo), delta(trigo) {
        this->setTime(time);
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
    
    void Directable::updateLocation() {
        this->delta.add(direction.getX() * time->getDelta(), direction.getY() * time->getDelta());
        this->addLocation(this->delta);
    }
}
