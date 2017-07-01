//
//  Injector.cpp
//  kitt
//
//  Created by Marco Hernandez on 1/07/17.
//  Copyright © 2017 Marco Hernandez. All rights reserved.
//

#include "Injector.hpp"

namespace Core {
    Injector *Injector::instance = NULL;
    
    Injector::Injector() {
        state = new State();
    }
    
    Injector *Injector::get() {
        if (instance== NULL) {
            instance = new Injector();
        }
        return instance;
    }
    
    State *Injector::getState() {
        return state;
    }
}
