//
//  TimeFactory.hpp
//  kitt
//
//  Created by Marco Hernandez on 2/07/17.
//  Copyright © 2017 Marco Hernandez. All rights reserved.
//

#ifndef TimeFactory_hpp
#define TimeFactory_hpp

#include <stdio.h>
#include "Time.hpp"

namespace Core {
    class TimeFactory {
    public:
        static Time *create();
    };
}
#endif /* TimeFactory_hpp */
