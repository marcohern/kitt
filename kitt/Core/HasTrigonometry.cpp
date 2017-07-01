//
//  HasTrigonometry.cpp
//  kitt
//
//  Created by Marco Hernandez on 1/07/17.
//  Copyright © 2017 Marco Hernandez. All rights reserved.
//

#include "HasTrigonometry.hpp"
#include "../Exceptions/NullReferenceException.hpp"

namespace Core
{
    using namespace Exceptions;
    
    void HasTrigonometry::setTrigonometry(Trigonometry *trigo) {
        if (trigo==NULL) throw NullReferenceException("Vector not allowed to function without Trigonometry");
        this->trigo = trigo;
    }
}
