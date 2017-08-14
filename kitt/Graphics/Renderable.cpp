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
    : Transformable() {
    }
    
    Renderable::Renderable(const Vector2D &location)
		: Transformable(location) {    
    }

	Renderable::Renderable(const Vector2D &location, const Vector2D &size) 
		: Transformable(location, size) {
	}
    
    Renderable::Renderable(const Vector2D &location, const Vector2D &size,const Vector2D &areaPivot)
		: Transformable(location, size, areaPivot) {
  
    }

	Renderable::Renderable(const Vector2D &location, const Vector2D &size, const Vector2D &areaPivot, const Vector2D &rotatePivot)
		: Transformable(location, size, areaPivot, rotatePivot) {

	}

    Renderable::Renderable(Trigonometry *trigo)
		: Transformable(trigo) {
        
    }
    Renderable::Renderable(const Vector2D &location, Trigonometry *trigo)
		: Transformable(location, trigo) {
        
    }

	Renderable::Renderable(const Vector2D &location, const Vector2D &size, Trigonometry *trigo)
		: Transformable(location, size, trigo) {

	}

	Renderable::Renderable(const Vector2D &location, const Vector2D &size, const Vector2D &areaPivot, Trigonometry *trigo)
		: Transformable(location, size, areaPivot, trigo) {

	}

	Renderable::Renderable(const Vector2D &location, const Vector2D &size, const Vector2D &areaPivot, const Vector2D &rotatePivot, Trigonometry *trigo)
		: Transformable(location, size, areaPivot, rotatePivot, trigo) {

	}
    
    Renderable::~Renderable() {
		Transformable::~Transformable();
    }

	void Renderable::render(Renderer *render, Camera *camera) {
		Vector2D location = camera->getLocation();
		render->animation(location, current);
	}
}
