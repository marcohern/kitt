//
//  Time.cpp
//  kitt
//
//  Created by Marco Hernandez on 2/07/17.
//  Copyright © 2017 Marco Hernandez. All rights reserved.
//


#include "Time.hpp"

namespace Core {
    Time::Time() {
        this->setStart(0.0);
    }
    
    Time::~Time() {
        
    }
    
    void Time::setStart(double start){
        this->start = start;
        this->prev = start;
        this->now = start;
        this->delta = 0.0;
    }
    
    void Time::setNow(double now) {
        this->prev = this->now;
        this->now = now;
        this->delta = this->now - this->prev;
        if (this->delta < 0) {
            this->delta = 0;
        }
    }
    
    double Time::getStart() {
        return this->start;
    }
    
    double Time::getNow() {
        return this->now;
    }
    
    double Time::getDelta() {
        return this->delta;
    }
    
    
}
