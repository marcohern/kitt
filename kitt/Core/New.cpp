//
//  New.cpp
//  kitt
//
//  Created by Marco Hernandez on 1/07/17.
//  Copyright © 2017 Marco Hernandez. All rights reserved.
//


#include "New.hpp"
#include "Injector.hpp"

namespace Core {
    New::New() {
        this->injector = Injector::get();
        this->trigonometry = this->injector->getTrigonometry();
    }
    Vector2D New::vector2d() {
        return Vector2D(trigonometry);
    }
    
    Vector2D New::vector2d(double x, double y) {
        return Vector2D(x,y,trigonometry);
    }
    
    Vector2D New::vector2d(const Vector2D &v) {
        return Vector2D(v,trigonometry);
    }
}
