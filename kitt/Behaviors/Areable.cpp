//
//  Areable.cpp
//  kitt
//
//  Created by Marco Hernandez on 26/07/17.
//  Copyright © 2017 Marco Hernandez. All rights reserved.
//

#include "Areable.hpp"

namespace Behaviors {
    using namespace Core;
    
    Areable::Areable()
    : area(), areaPivot() {}
    
    Areable::Areable(double w, double h)
    : area(w,h),areaPivot() {}
    
    Areable::Areable(double w, double h, double px, double py)
    : area(w,h), areaPivot(px, py) {}
    
    Areable::Areable(const Vector2D &area)
    : area(area), areaPivot() {}
    
    Areable::Areable(const Vector2D &area, const Vector2D &pivot)
    : area(area), areaPivot(pivot) {}
    
    Areable::Areable(Trigonometry *trigo)
    : area(trigo), areaPivot(trigo) {}
    
    Areable::Areable(double w, double h, Trigonometry *trigo)
    : area(w,h, trigo),areaPivot(trigo) {}
    
    Areable::Areable(double w, double h, double px, double py, Trigonometry *trigo)
    : area(w,h, trigo), areaPivot(px, py, trigo) {}
    
    Areable::Areable(const Vector2D &area, Trigonometry *trigo)
    : area(area,trigo), areaPivot(trigo) {}
    
    Areable::Areable(const Vector2D &area, const Vector2D &pivot, Trigonometry *trigo)
    : area(area,trigo), areaPivot(pivot, trigo) {}
    
    Areable::~Areable() {
        
    }
    
    void Areable::setWidth(double w) {
        area.setX(w);
    }
    
    void Areable::setHeight(double h) {
        area.setY(h);
    }
    
    void Areable::setAreaVector(double w, double h) {
        area.set(w, h);
    }
    
    void Areable::setAreaVector(const Vector2D &area) {
        this->area.set(area);
    }
    
    void Areable::setAreaPivot(double px, double py) {
        areaPivot.set(px, py);
    }
    
    void Areable::setAreaPivot(const Vector2D &pivot) {
        areaPivot.set(pivot);
    }
    
    double Areable::getWidth() const {
        return area.getX();
    }
    
    double Areable::getHeight() const {
        return area.getY();
    }
    
    Vector2D Areable::getAreaVector() const {
        return area;
    }
    
    double Areable::getArea() const {
        return area.getX() * area.getY();
    }
    
    Vector2D Areable::getAreaPivot() const {
        return areaPivot;
    }
    
    Vector2D Areable::getPivotLocation(Vector2D location) const {
        Vector2D l(location);
        l.add(areaPivot);
        return l;
    }
}
