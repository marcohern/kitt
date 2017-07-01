//
//  Trigonometry.cpp
//  kitt
//
//  Created by Marco Hernandez on 1/07/17.
//  Copyright © 2017 Marco Hernandez. All rights reserved.
//

#include <math.h>
#include <iostream>
#include <iomanip>
#include "MemoizedTrigonometry.hpp"

namespace Core {
    using namespace std;
    MemoizedTrigonometry::MemoizedTrigonometry()
    : Trigonometry()
    {
    }
    
    MemoizedTrigonometry::~MemoizedTrigonometry() {
        this->sint.clear();
        this->cost.clear();
    }
    
    double MemoizedTrigonometry::sin(double r) {
        auto v = this->sint.find(r);
        if (v == this->sint.end()) {
            this->sint[r] = ::sin(r);
            return this->sint[r];
        }
        return v->second;
    }
    
    double MemoizedTrigonometry::cos(double r) {
        auto v = this->cost.find(r);
        if (v == this->cost.end()) {
            this->cost[r] = ::cos(r);
            return this->cost[r];
        }
        return v->second;
    }
}
