//
//  Rotateable.cpp
//  kitt
//
//  Created by Marco Hernandez on 25/07/17.
//  Copyright © 2017 Marco Hernandez. All rights reserved.
//

#include "Rotateable.hpp"

namespace Behaviors {
    Rotateable::Rotateable()
    : Behaviors::Angleable(), rotationRate(0.0) {}
    
    Rotateable::Rotateable(double radians)
    : Behaviors::Angleable(radians), rotationRate(0.0) {}
    
    Rotateable::Rotateable(double px, double py)
    : Behaviors::Angleable(px, py), rotationRate(0.0) {}
    
    Rotateable::Rotateable(const Vector2D &pivot)
    : Behaviors::Angleable(pivot), rotationRate(0.0) {}
    
    Rotateable::Rotateable(double px, double py, double radians)
    : Behaviors::Angleable(px, py, radians), rotationRate(0.0) {}
    
    Rotateable::Rotateable(const Vector2D &pivot, double radians)
    : Behaviors::Angleable(pivot, radians), rotationRate(0.0) {}
    
    Rotateable::~Rotateable() {
        Angleable::~Angleable();
    }
    void Rotateable::setRotationRate(double rate) {
        rotationRate = rate;
    }
    
    void Rotateable::addRotationRate(double rate) {
        rotationRate += rate;
    }
    
    double Rotateable::getRotationRate() const {
        return rotationRate;
    }
    
    void Rotateable::updateAngle(double interval) {
        angle += rotationRate * interval;
    }
}
