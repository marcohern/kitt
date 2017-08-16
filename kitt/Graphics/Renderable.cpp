//
//  Renderable.cpp
//  kitt
//
//  Created by Marco Hernandez on 8/07/17.
//  Copyright © 2017 Marco Hernandez. All rights reserved.
//

#include "Renderable.hpp"
#include "../constants.hpp"

namespace Graphics
{
    
    Renderable::Renderable()
		: Transformable()
		, current(NULL), renderSwitch(true), translucent(false), renderInterval(0.0), translucentInterval(0.0), translucentTime(0.0) {
    }
    
    Renderable::Renderable(const Vector2D &location)
		: Transformable(location)
		, current(NULL), renderSwitch(true), translucent(false), renderInterval(0.0), translucentInterval(0.0), translucentTime(0.0) {
    }

	Renderable::Renderable(const Vector2D &location, const Vector2D &size) 
		: Transformable(location, size)
		, current(NULL), renderSwitch(true), translucent(false), renderInterval(0.0), translucentInterval(0.0), translucentTime(0.0) {
	}
    
    Renderable::Renderable(const Vector2D &location, const Vector2D &size,const Vector2D &areaPivot)
		: Transformable(location, size, areaPivot)
		, current(NULL), renderSwitch(true), translucent(false), renderInterval(0.0), translucentInterval(0.0), translucentTime(0.0) {
  
    }

	Renderable::Renderable(const Vector2D &location, const Vector2D &size, const Vector2D &areaPivot, const Vector2D &rotatePivot)
		: Transformable(location, size, areaPivot, rotatePivot)
		, current(NULL), renderSwitch(true), translucent(false), renderInterval(0.0), translucentInterval(0.0), translucentTime(0.0) {

	}

    Renderable::Renderable(Trigonometry *trigo)
		: Transformable(trigo)
		, current(NULL), renderSwitch(true), translucent(false), renderInterval(0.0), translucentInterval(0.0), translucentTime(0.0) {
        
    }
    Renderable::Renderable(const Vector2D &location, Trigonometry *trigo)
		: Transformable(location, trigo)
		, current(NULL), renderSwitch(true), translucent(false), renderInterval(0.0), translucentInterval(0.0), translucentTime(0.0) {
        
    }

	Renderable::Renderable(const Vector2D &location, const Vector2D &size, Trigonometry *trigo)
		: Transformable(location, size, trigo)
		, current(NULL), renderSwitch(true), translucent(false), renderInterval(0.0), translucentInterval(0.0), translucentTime(0.0) {

	}

	Renderable::Renderable(const Vector2D &location, const Vector2D &size, const Vector2D &areaPivot, Trigonometry *trigo)
		: Transformable(location, size, areaPivot, trigo)
		, current(NULL), renderSwitch(true), translucent(false), renderInterval(0.0), translucentInterval(0.0), translucentTime(0.0) {

	}

	Renderable::Renderable(const Vector2D &location, const Vector2D &size, const Vector2D &areaPivot, const Vector2D &rotatePivot, Trigonometry *trigo)
		: Transformable(location, size, areaPivot, rotatePivot, trigo)
		, current(NULL), renderSwitch(true), translucent(false), renderInterval(0.0), translucentInterval(0.0), translucentTime(0.0) {

	}
    
    Renderable::~Renderable() {
		Transformable::~Transformable();
    }

	void Renderable::render(Renderer *render, Camera *camera) {
		if (renderSwitch) {
			Vector2D location = this->getDisplacement(camera->getLocation());
			Vector2D area = this->getScaledArea();
			render->animation(
				location,
				area,
				this->getRotatePivot(),
				this->getAngleDegrees(),
				false,
				false,
				this->current
			);
		}
	}

	void Renderable::update(double interval) {
		renderInterval += interval;
		translucentInterval += interval;
		if (translucent) {
			if (renderInterval > ANIM_TRANSLUCENT_INTERVAL) {
				renderInterval -= ANIM_TRANSLUCENT_INTERVAL;
				renderSwitch = (renderSwitch) ? false : true;
			}
			if (translucentInterval > translucentTime) {
				translucent = false;
			}
		}
		else {
			renderSwitch = true;
		}
		current->update(interval);
		this->updateTransform(interval);
	}

	void Renderable::setTranslucent(double time) {
		translucent = true;
		translucentInterval = 0.0;
		translucentTime = time;

		renderSwitch = false;
		renderInterval = 0.0;
	}

	void Renderable::setAnimation(Animation *animation) {
		current = animation;
	}

	void Renderable::clearAnimation() {
		current = NULL;
	}
}
