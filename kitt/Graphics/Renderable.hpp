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
#include "Animation.hpp"
#include "Renderer.hpp"

namespace Graphics {
    using namespace Core;
	using namespace Behaviors;
    
    class Renderable : public Transformable {
        
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
        
        virtual void render(Renderer *render) = 0;
    };
}
#endif /* Renderable_hpp */
