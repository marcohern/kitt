//
//  Scalable.cpp
//  kitt
//
//  Created by Marco Hernandez on 22/07/17.
//  Copyright © 2017 Marco Hernandez. All rights reserved.
//

#include "Scalable.hpp"

namespace Behaviors {
    Scalable::Scalable() : scale(1,1) {}
    Scalable::Scalable(double s) : scale(s,s) {}
    Scalable::Scalable(double sx, double sy) : scale(sx,sy) {}
    Scalable::Scalable(const Vector2D &scale) : scale(scale) {}
    
    Scalable::Scalable(Trigonometry *trigo)
    : scale(1,1, trigo)
    {}
    
    Scalable::Scalable(double s, Trigonometry *trigo)
    : scale(s,s, trigo)
    {}
    
    Scalable::Scalable(double sx, double sy, Trigonometry *trigo)
    : scale(sx,sy, trigo)
    {}
    
    Scalable::Scalable(const Vector2D &scale, Trigonometry *trigo)
    : scale(scale, trigo)
    {}
    
    Scalable::~Scalable() {
        
    }
    
    void Scalable::setScale(double s) {
        this->scale.set(s,s);
    }
    
    void Scalable::setScale(double sx, double sy) {
        this->scale.set(sx,sy);
    }
    
    void Scalable::setScale(const Core::Vector2D &scale) {
        this->scale.set(scale);
    }
    
    Vector2D Scalable::getScale() const {
        return scale;
    }
    
    double Scalable::getScaleX() const {
        return scale.getX();
    }
    
    double Scalable::getScaleY() const {
        return scale.getY();
    }
    
    void Scalable::addScale(double ds) {
        scale.add(ds,ds);
    }
    
    void Scalable::addScale(double dx, double dy) {
        scale.add(dx, dy);
    }
    
    void Scalable::addScale(const Core::Vector2D &delta) {
        scale.add(delta);
    }
    
    Vector2D Scalable::getZoomScale(double zoom) const {
        Vector2D zooms(scale);
        zooms.multiply(zoom);
        return zooms;
    }
}
