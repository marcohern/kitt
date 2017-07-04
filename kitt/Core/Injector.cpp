//
//  Injector.cpp
//  kitt
//
//  Created by Marco Hernandez on 1/07/17.
//  Copyright © 2017 Marco Hernandez. All rights reserved.
//

#include "Injector.hpp"
#include "./TrigonometryFactory.hpp"
#include "./TimeFactory.hpp"

namespace Core {
    Injector *Injector::instance = NULL;
    
    Injector::Injector() {
        trigonometry = TrigonometryFactory::create(TRIGO_TYPE);
        time = TimeFactory::create();
    }
    
    Injector::~Injector() {
        delete trigonometry;
        delete time;
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
    
    Time *Injector::getTime() {
        return time;
    }
}
