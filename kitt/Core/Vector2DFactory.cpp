//
//  Vector2DFactory.cpp
//  kitt
//
//  Created by Marco Hernandez on 2/07/17.
//  Copyright © 2017 Marco Hernandez. All rights reserved.
//

#include "Vector2DFactory.hpp"
#include "./TrigonometryFactory.hpp"
#include "./Trigonometry.hpp"
#include "./Injector.hpp"

namespace Core{
    Vector2D create(const int &trigoType) {
        Trigonometry *t = Injector::get()->getTrigonometry();
        return Vector2D(t);
    }
}
