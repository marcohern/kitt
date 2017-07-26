//
//  Angleable.cpp
//  kitt
//
//  Created by Marco Hernandez on 23/07/17.
//  Copyright © 2017 Marco Hernandez. All rights reserved.
//

#include "Angleable.hpp"

namespace Behaviors {
    Angleable::Angleable()
    : angle(0), rotatePivot() {}
    
    Angleable::Angleable(double radians)
    : angle(radians), rotatePivot() {}
    
    Angleable::Angleable(double px, double py)
    : angle(0), rotatePivot(px, py) {}
    
    Angleable::Angleable(const Vector2D &pivot)
    : angle(0), rotatePivot(pivot) {}
    
    Angleable::Angleable(double px, double py, double radians)
    : angle(radians), rotatePivot(px, py) {}
    
    Angleable::Angleable(const Vector2D &pivot, double radians)
    : angle(radians), rotatePivot(pivot) {}
    
    Angleable::Angleable(Trigonometry *trigo)
    : angle(0), rotatePivot(trigo) {}
    
    Angleable::Angleable(double radians, Trigonometry *trigo)
    : angle(radians), rotatePivot(trigo) {}
    
    Angleable::Angleable(double px, double py, Trigonometry *trigo)
    : angle(0), rotatePivot(px, py, trigo) {}
    
    Angleable::Angleable(const Vector2D &pivot, Trigonometry *trigo)
    : angle(0), rotatePivot(pivot, trigo) {}
    
    Angleable::Angleable(double px, double py, double radians, Trigonometry *trigo)
    : angle(radians), rotatePivot(px, py, trigo) {}
    
    Angleable::Angleable(const Vector2D &pivot, double radians, Trigonometry *trigo)
    : angle(radians), rotatePivot(pivot, trigo) {}
    
    
    Angleable::~Angleable() {
        
    }
    
    void Angleable::setAngle(double radians) {
        angle = radians;
    }
    
    void Angleable::setRotatePivot(double px, double py) {
        rotatePivot.set(px, py);
    }
    
    void Angleable::setRotatePivot(const Vector2D &pivot) {
        rotatePivot.set(pivot);
    }
    
    double Angleable::getAngle() const {
        return angle;
    }
    
    Vector2D Angleable::getRotatePivot() const {
        return rotatePivot;
    }
    
    void Angleable::addAngle(double radians) {
        angle += radians;
    }
    
    double Angleable::getAngleDisplacement(double radians) const {
        return radians - angle;
    }
    
    Vector2D Angleable::getRotatePivotDisplacement(double radians) const {
        return getRotatePivotDisplacement(radians, 1.0);
    }
    
    Vector2D Angleable::getRotatePivotDisplacement(double radians, double zoom) const {
        Vector2D d(rotatePivot);
        d.multiply(zoom);
        return d;
    }
}
