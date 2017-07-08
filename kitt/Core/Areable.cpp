//
//  Areable.cpp
//  kitt
//
//  Created by Marco Hernandez on 8/07/17.
//  Copyright © 2017 Marco Hernandez. All rights reserved.
//

#include "Areable.hpp"

namespace Core {
    Areable::Areable()
    : Core::Rotateable(), size(), pivot() {
        
    }
    
    Areable::Areable(const Vector2D &location, const Vector2D &size)
    : Core::Rotateable(location), size(size), pivot() {
        
    }
    
    Areable::Areable(const Vector2D &location, const Vector2D &size, const Vector2D &pivot)
    : Core::Rotateable(location), size(size), pivot(pivot) {
        
    }
    
    Areable::Areable(Trigonometry *trigo, Time *time)
    : Core::Rotateable(trigo, time), size(), pivot() {
        
    }
    
    Areable::Areable(const Vector2D &location, const Vector2D &size, Trigonometry *trigo, Time *time)
    : Core::Rotateable(location, trigo, time), size(size), pivot(){
        
    }
    
    Areable::Areable(const Vector2D &location, const Vector2D &size, const Vector2D &pivot, Trigonometry *trigo, Time *time)
    : Core::Rotateable(location, trigo, time), size(size), pivot(pivot){
        
    }
    
    Areable::~Areable() {
        Rotateable::~Rotateable();
    }
    
    Vector2D Areable::getSize() const {
        return this->size;
    }
    Vector2D Areable::getPivot() const {
        return this->pivot;
    }
    
    void Areable::setSize(double w, double h) {
        this->size.set(w, h);
    }
    
    void Areable::setPivot(double px, double py) {
        this->pivot.set(px,py);
    }
    
    void Areable::setSize(const Vector2D &size) {
        this->size.set(size);
    }
    void Areable::setPivot(const Vector2D &pivot) {
        this->pivot.set(pivot);
    }
    
    Vector2D Areable::getPivotLocation() {
        pivotloc.set(location);
        pivotloc.add(pivot);
        return pivotloc;
    }
    
    Vector2D Areable::getPivotDisplacement(const Vector2D &displacement) {
        pivotloc.set(Placeable::getDisplacement(displacement));
        pivotloc.add(pivot);
        return pivotloc;
    }
    
    double Areable::getArea() const {
        return size.getX() * size.getY();
    }
}
