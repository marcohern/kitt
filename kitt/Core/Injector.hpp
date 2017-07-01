//
//  Injector.hpp
//  kitt
//
//  Created by Marco Hernandez on 1/07/17.
//  Copyright © 2017 Marco Hernandez. All rights reserved.
//

#ifndef Injector_hpp
#define Injector_hpp

#include <stdio.h>
#include "./State.hpp"

namespace Core {
    class Injector {
    private:
        static Injector *instance;
        State *state;
        
        Injector();
        
    public:
        ~Injector();
        static Injector *get();
        
        State *getState();
    };
}
#endif /* Injector_hpp */
