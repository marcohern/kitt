//
//  Trigonometry.cpp
//  kitt
//
//  Created by Marco Hernandez on 1/07/17.
//  Copyright © 2017 Marco Hernandez. All rights reserved.
//

#include <math.h>
#include "Trigonometry.hpp"

namespace Core {
    
    Trigonometry::Trigonometry() {
    }
    
    Trigonometry::~Trigonometry() {
        this->sint.clear();
        this->cost.clear();
    }
    
    double Trigonometry::sin(double r) {
        auto v = this->sint.find(r);
        if (v == this->sint.end()) {
            this->sint[r] = ::sin(r);
            return this->sint[r];
        }
        return v->second;
    }
    
    double Trigonometry::cos(double r) {
        auto v = this->cost.find(r);
        if (v == this->cost.end()) {
            this->cost[r] = ::cos(r);
            return this->cost[r];
        }
        return v->second;
    }
}
