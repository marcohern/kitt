//
//  Placeable.cpp
//  kitt
//
//  Created by Marco Hernandez on 11/07/17.
//  Copyright © 2017 Marco Hernandez. All rights reserved.
//

#include "Placeable.hpp"
#include "../Core/Vector2D.hpp"
#include "../Core/Trigonometry.hpp"

namespace Behaviors {
    using namespace Core;
    
    Placeable::Placeable() : location() {
    }
    
    Placeable::Placeable(double x, double y) : location(x,y) {
    }
    
    Placeable::Placeable(const Vector2D& v) : location(v) {
    }
    
    Placeable::~Placeable() {
        
    }
    
    Vector2D Placeable::getLocation() const {
        return this->location;
    }
    
    Vector2D Placeable::getDisplacement(const Vector2D &displacement) const {
        Vector2D d(location);
        d.sub(displacement);
        return d;
    }
    
    Vector2D Placeable::getDisplacement(double dx, double dy) const {
        Vector2D d(location);
        d.sub(dx,dy);
        return d;
    }
    
    void Placeable::setLocation(double x, double y) {
        this->location.set(x, y);
    }
    
    void Placeable::setLocation(const Vector2D &v) {
        this->location.set(v);
    }
    
    void Placeable::addLocation(double dx, double dy) {
        this->location.add(dx, dy);
    }
    
    void Placeable::addLocation(const Vector2D &v) {
        this->location.add(v);
    }
    
}
