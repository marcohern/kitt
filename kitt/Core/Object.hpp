//
//  Object.hpp
//  kitt
//
//  Created by Marco Hernandez on 30/06/17.
//  Copyright © 2017 Marco Hernandez. All rights reserved.
//

#ifndef Object_hpp
#define Object_hpp

#include <string>
#include <stdio.h>

namespace Core {
    using namespace std;
    
    class Object {
    public:
        virtual string toString();
    };
}

#endif /* Object_hpp */
