//
//  Injector.cpp
//  kitt
//
//  Created by Marco Hernandez on 1/07/17.
//  Copyright © 2017 Marco Hernandez. All rights reserved.
//

#include "Injector.hpp"
#include "./TrigonometryFactory.hpp"

namespace Core {
    Injector *Injector::instance = NULL;
    
    Injector::Injector() {
        trigonometry = TrigonometryFactory::create(TRIGO_TYPE);
    }
    
    Injector::~Injector() {
        delete trigonometry;
    }
    
    Injector *Injector::get() {
        if (instance== NULL) {
            instance = new Injector();
        }
        return instance;
    }
    
    Trigonometry *Injector::getTrigonometry() {
        return trigonometry;
    }
}
