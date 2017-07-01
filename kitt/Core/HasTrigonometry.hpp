//
//  HasTrigonometry.hpp
//  kitt
//
//  Created by Marco Hernandez on 1/07/17.
//  Copyright © 2017 Marco Hernandez. All rights reserved.
//

#ifndef HasTrigonometry_hpp
#define HasTrigonometry_hpp

#include <stdio.h>

#include "./Trigonometry.hpp"

namespace Core {
    class HasTrigonometry {
    protected:
        Trigonometry *trigo = NULL;
    public:
        HasTrigonometry(Trigonometry *trigo);
    };
}

#endif /* HasTrigonometry_hpp */
