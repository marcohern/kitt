//
//  Directable.cpp
//  kitt
//
//  Created by Marco Hernandez on 18/07/17.
//  Copyright © 2017 Marco Hernandez. All rights reserved.
//

#include "Directable.hpp"

namespace Behaviors {
    using namespace Core;
    
    Directable::Directable()
    : Placeable(), direction()
    { }
    
    Directable::Directable(double x, double y)
    : Placeable(x, y), direction()
    { }
    
    Directable::Directable(const Vector2D &v)
    : Placeable(v), direction()
    { }
    
    Directable::Directable(Trigonometry *trigo)
    : Placeable(trigo), direction()
    { }
    
    Directable::Directable(double x, double y, Trigonometry *trigo)
    : Placeable(x, y, trigo), direction()
    { }
    
    Directable::Directable(const Vector2D &v, Trigonometry *trigo)
    : Placeable(v, trigo), direction()
    { }
    
    Directable::~Directable() {
        Placeable::~Placeable();
    }
    
    Vector2D Directable::getDirection() const {
        return direction;
    }
    
    void Directable::setDirection(double dx, double dy) {
        direction.set(dx, dy);
    }
    
    void Directable::setDirection(const Vector2D &v) {
        direction.set(v);
    }
    
    void Directable::addDirection(const Vector2D &v) {
        direction.add(v);
    }
    
    void Directable::updateLocation(double interval) {
        _direction.set(direction);
        _direction.multiply(interval);
        location.add(_direction);
    }
}
