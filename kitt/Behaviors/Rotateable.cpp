//
//  Rotateable.cpp
//  kitt
//
//  Created by Marco Hernandez on 23/07/17.
//  Copyright © 2017 Marco Hernandez. All rights reserved.
//

#include "Rotateable.hpp"

namespace Behaviors {
    Rotateable::Rotateable()
    : angle(0), rotatePivot() {}
    
    Rotateable::Rotateable(double radians)
    : angle(radians), rotatePivot() {}
    
    Rotateable::Rotateable(double px, double py)
    : angle(0), rotatePivot(px, py) {}
    
    Rotateable::Rotateable(const Vector2D &pivot)
    : angle(0), rotatePivot(pivot) {}
    
    Rotateable::Rotateable(double px, double py, double radians)
    : angle(radians), rotatePivot(px, py) {}
    
    Rotateable::Rotateable(const Vector2D &pivot, double radians)
    : angle(radians), rotatePivot(pivot) {}
    
    Rotateable::Rotateable(Trigonometry *trigo)
    : angle(0), rotatePivot(trigo) {}
    
    Rotateable::Rotateable(double radians, Trigonometry *trigo)
    : angle(radians), rotatePivot(trigo) {}
    
    Rotateable::Rotateable(double px, double py, Trigonometry *trigo)
    : angle(0), rotatePivot(px, py, trigo) {}
    
    Rotateable::Rotateable(const Vector2D &pivot, Trigonometry *trigo)
    : angle(0), rotatePivot(pivot, trigo) {}
    
    Rotateable::Rotateable(double px, double py, double radians, Trigonometry *trigo)
    : angle(radians), rotatePivot(px, py, trigo) {}
    
    Rotateable::Rotateable(const Vector2D &pivot, double radians, Trigonometry *trigo)
    : angle(radians), rotatePivot(pivot, trigo) {}
    
    
    Rotateable::~Rotateable() {
        
    }
    
    void Rotateable::setAngle(double radians) {
        angle = radians;
    }
    
    void Rotateable::setRotatePivot(double px, double py) {
        rotatePivot.set(px, py);
    }
    
    void Rotateable::setRotatePivot(const Vector2D &pivot) {
        rotatePivot.set(pivot);
    }
    
    double Rotateable::getAngle() const {
        return angle;
    }
    
    Vector2D Rotateable::getRotatePivot() const {
        return rotatePivot;
    }
    
    void Rotateable::addAngle(double radians) {
        angle += radians;
    }
    
    double Rotateable::getAngleDisplacement(double radians) const {
        return radians - angle;
    }
    
    Vector2D Rotateable::getRotatePivotDisplacement(double radians) const {
        return getRotatePivotDisplacement(radians, 1.0);
    }
    
    Vector2D Rotateable::getRotatePivotDisplacement(double radians, double zoom) const {
        Vector2D d(rotatePivot);
        d.multiply(zoom);
        return d;
    }
}
