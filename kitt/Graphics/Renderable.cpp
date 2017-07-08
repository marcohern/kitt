//
//  Renderable.cpp
//  kitt
//
//  Created by Marco Hernandez on 8/07/17.
//  Copyright © 2017 Marco Hernandez. All rights reserved.
//

#include "Renderable.hpp"

namespace Graphics
{
    
    Renderable::Renderable()
    : Areable() {
        
    }
    
    Renderable::Renderable(const Vector2D &location)
    : Areable(location, Vector2D(0,0)) {
        
    }
    
    Renderable::Renderable(const Vector2D &location, const Vector2D &size,const Vector2D &pivot)
    : Areable(location, size, pivot) {
        
    }
    Renderable::Renderable(Renderer *renderer, Time *time, Trigonometry *trigo)
    : Areable(trigo, time) {
        
    }
    Renderable::Renderable(const Vector2D &location,Renderer *renderer, Time *time, Trigonometry *trigo)
    : Areable(location, Vector2D(0,0,trigo), trigo, time) {
        
    }
    Renderable::Renderable(const Vector2D &location, const Vector2D &size,const Vector2D &pivot,Renderer *renderer, Time *time, Trigonometry *trigo)
    : Areable(location, size, pivot, trigo, time) {
        
    }
    
    Renderable::~Renderable() {
        Areable::~Areable();
    }
}
