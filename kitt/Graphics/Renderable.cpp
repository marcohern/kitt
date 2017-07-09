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
    Renderable::Renderable(Renderer *renderer, Trigonometry *trigo)
    : Areable(trigo) {
        
    }
    Renderable::Renderable(const Vector2D &location,Renderer *renderer, Trigonometry *trigo)
    : Areable(location, Vector2D(0,0,trigo), trigo) {
        
    }
    Renderable::Renderable(const Vector2D &location, const Vector2D &size,const Vector2D &pivot,Renderer *renderer, Trigonometry *trigo)
    : Areable(location, size, pivot, trigo) {
        
    }
    
    Renderable::~Renderable() {
        Areable::~Areable();
    }
}
