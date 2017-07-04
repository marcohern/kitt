//
//  TrigonometryFactory.hpp
//  kitt
//
//  Created by Marco Hernandez on 2/07/17.
//  Copyright © 2017 Marco Hernandez. All rights reserved.
//

#ifndef TrigonometryFactory_hpp
#define TrigonometryFactory_hpp

#include <stdio.h>
#include "./Trigonometry.hpp"
#include "../constants.hpp"

namespace Core {
    class TrigonometryFactory {
    public:
        static Trigonometry* create(const int &type);
        
    };
}
#endif /* TrigonometryFactory_hpp */
