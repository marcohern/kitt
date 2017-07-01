//
//  RealtimeTrigonometry.cpp
//  kitt
//
//  Created by Marco Hernandez on 1/07/17.
//  Copyright © 2017 Marco Hernandez. All rights reserved.
//

#include <math.h>
#include "RealtimeTrigonometry.hpp"

namespace Core {
    
    RealtimeTrigonometry::RealtimeTrigonometry()
    : Trigonometry(){
    }
    
    RealtimeTrigonometry::~RealtimeTrigonometry()
    {
    }
    
    double RealtimeTrigonometry::sin(double r) {
        return ::sin(r);
    }
    
    double RealtimeTrigonometry::cos(double r) {
        return ::cos(r);
    }
}
