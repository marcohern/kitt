//
//  New.hpp
//  kitt
//
//  Created by Marco Hernandez on 1/07/17.
//  Copyright © 2017 Marco Hernandez. All rights reserved.
//

#ifndef New_hpp
#define New_hpp

#include <stdio.h>
#include "Vector2D.hpp"
#include "Injector.hpp"

namespace Core {
    class New {
        Injector *injector;
        State *state;
    public:
        New();
        
        Vector2D vector2d();
        Vector2D vector2d(double x, double y);
        Vector2D vector2d(const Vector2D &v);
    };
}
#endif /* New_hpp */
