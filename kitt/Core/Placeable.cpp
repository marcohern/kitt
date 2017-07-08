//
//  Placeable.cpp
//  kitt
//
//  Created by Marco Hernandez on 3/07/17.
//  Copyright © 2017 Marco Hernandez. All rights reserved.
//

#include "Placeable.hpp"

namespace Core {
	Placeable::Placeable()                    : location() {}
	Placeable::Placeable(double x, double y ) : location(x, y) {}
	Placeable::Placeable(const Vector2D &v  ) : location(v) {}
    Placeable::Placeable(Trigonometry *trigo) : location(trigo) {}
    Placeable::Placeable(double x, double y, Trigonometry *trigo) : location(x,y,trigo) {}
    Placeable::Placeable(const Vector2D &v, Trigonometry *trigo) : location(v,trigo) {}

    Placeable::~Placeable() {}
    
    void Placeable::addLocation(double dx, double dy) {
        this->location.add(dx, dy);
    }
    
    void Placeable::addLocation(const Vector2D &v) {
        this->location.add(v);
    }
    
    Vector2D Placeable::getLocation() const {
        return this->location;
    }
    
    Vector2D Placeable::getDisplacement(const Vector2D &displacement, double zoom) const {
        Vector2D d(displacement);
        d.sub(location);
        d.divide(zoom);
        return d;
    }
    
    Vector2D Placeable::getDisplacement(const Vector2D &displacement) const {
        Vector2D d(displacement);
        d.sub(location);
        return d;
    }
    
    void Placeable::setLocation(double x, double y) {
        this->location.set(x, y);
    }
    
    void Placeable::setLocation(const Core::Vector2D &v) {
        this->location.set(v);
    }
}
