//
//  Renderable.hpp
//  kitt
//
//  Created by Marco Hernandez on 8/07/17.
//  Copyright © 2017 Marco Hernandez. All rights reserved.
//

#ifndef Renderable_hpp
#define Renderable_hpp

#include <stdio.h>
#include "../Behaviors/Transformable.hpp"
#include "../Core/Camera.hpp"
#include "Animation.hpp"
#include "Renderer.hpp"
#include "Color.hpp"

namespace Graphics {
    using namespace Core;
	using namespace Behaviors;
    
    class Renderable : public Transformable {
	private:
		Animation *current;
		RendererFlip flip;
		int blendAdd;
		Color tint;

		bool translucent;
		bool renderSwitch;
		double translucentInterval;
		double translucentTime;
		double renderInterval;
		bool active;

        
    public:
        Renderable();
        Renderable(const Vector2D &location);
		Renderable(const Vector2D &location, const Vector2D &size);
        Renderable(const Vector2D &location, const Vector2D &size,const Vector2D &areaPivot);
		Renderable(const Vector2D &location, const Vector2D &size, const Vector2D &areaPivot, const Vector2D &rotatePivot);

        Renderable(Trigonometry *trigo);
        Renderable(const Vector2D &location, Trigonometry *trigo);
		Renderable(const Vector2D &location, const Vector2D &size, Trigonometry *trigo);
        Renderable(const Vector2D &location, const Vector2D &size,const Vector2D &areaPivot, Trigonometry *trigo);
		Renderable(const Vector2D &location, const Vector2D &size, const Vector2D &areaPivot, const Vector2D &rotatePivot, Trigonometry *trigo);
        
        virtual ~Renderable();
        
		virtual void render(Renderer *render, Camera *camera);
		virtual void update(double interval);

		void setTranslucent(double time);
		void setAnimation(Animation *animation);
		void clearAnimation();

		bool isTranslucent() const;

		void activate();
		void deactivate();
		bool isActive() const;

		void setFlip(RendererFlip flip);
		RendererFlip getFlip() const;
		void clearFlip();

		void setTint(const Color &tint);
		Color getTint() const;

		void setBlendAdd(int blendAdd);
		int getBlendAdd() const;
		void activateDefaultBlendAdd();
		void clearBlendAadd();

    };
}
#endif /* Renderable_hpp */
