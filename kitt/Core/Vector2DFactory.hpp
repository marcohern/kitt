//
//  Vector2DFactory.hpp
//  kitt
//
//  Created by Marco Hernandez on 2/07/17.
//  Copyright © 2017 Marco Hernandez. All rights reserved.
//

#ifndef Vector2DFactory_hpp
#define Vector2DFactory_hpp

#include <stdio.h>
#include "./Vector2D.hpp"

namespace Core {
    class Vector2DFactory {
    public:
        static Vector2D create();
        static Vector2D create(double x, double y);
        static Vector2D create(const Vector2D &v);
    };
}

#endif /* Vector2DFactory_hpp */
