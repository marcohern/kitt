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
#include "../Core/Areable.hpp"
#include "Renderer.hpp"

namespace Graphics {
    using namespace Core;
    
    class Renderable : public Areable {
    protected:
        Renderer *renderer;
        
    public:
        Renderable();
        Renderable(const Vector2D &location);
        Renderable(const Vector2D &location, const Vector2D &size,const Vector2D &pivot);
        Renderable(Renderer *renderer, Time *time, Trigonometry *trigo);
        Renderable(const Vector2D &location,Renderer *renderer, Time *time, Trigonometry *trigo);
        Renderable(const Vector2D &location, const Vector2D &size,const Vector2D &pivot,Renderer *renderer, Time *time, Trigonometry *trigo);
        
        virtual ~Renderable();
        
        virtual void render() = 0;
    };
}
#endif /* Renderable_hpp */
