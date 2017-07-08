//
//  Vector2DRenderable.hpp
//  kitt
//
//  Created by Marco Hernandez on 8/07/17.
//  Copyright © 2017 Marco Hernandez. All rights reserved.
//

#ifndef Vector2DRenderable_hpp
#define Vector2DRenderable_hpp

#include <stdio.h>
#include "../Core/Vector2D.hpp"
#include "Renderable.hpp"

namespace Graphics {
    using namespace Core;
    
    class Vector2DRenderable : public Renderable {
    public:
        void render();
    };
}
#endif /* Vector2DRenderable_hpp */
