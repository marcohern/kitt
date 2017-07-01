//
//  State.cpp
//  kitt
//
//  Created by Marco Hernandez on 1/07/17.
//  Copyright © 2017 Marco Hernandez. All rights reserved.
//

#include "State.hpp"

namespace Core {
    State::State() {
        trigonometry = new Trigonometry();
    }
    
    State::~State() {
        delete trigonometry;
    }
    
    Trigonometry *State::getTrigonometry() {
        return this->trigonometry;
    }
}
