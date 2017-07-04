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
#include "./constants.hpp"

namespace Core {
    using namespace std;
    
    const double MemoizedTrigonometry::novalue = -666.666;
    
    MemoizedTrigonometry::MemoizedTrigonometry()
    : Trigonometry()
    {
        for (int i=0;i<TRIGO_TABLE_SIZE;i++) {
            double r = radian(i);
            this->cost[i] = ::cos(r);
            this->sint[i] = ::sin(r);
        }
    }
    
    MemoizedTrigonometry::~MemoizedTrigonometry() {
    }
    
    int MemoizedTrigonometry::index(double r) {
        double fm = fmod(abs(r), TAU)/TAU;
        int i = fm*TRIGO_TABLE_SIZE;
        return i;
    }
    
    double MemoizedTrigonometry::radian(int i) {
        double r = (double)i;
        return TAU * r/TRIGO_TABLE_SIZE;
    }
    
    double MemoizedTrigonometry::sin(double r) {
        int i = this->index(r);
        double v = this->sint[i];
        if (v == novalue) {
            double r2 = radian(i);
            this->sint[i] = ::sin(r2);
            return this->sint[i];
        }
        return v;
    }
    
    double MemoizedTrigonometry::cos(double r) {
        int i = this->index(r);
        double v = this->cost[i];
        if (v == novalue) {
            double r2 = radian(i);
            this->cost[i] = ::cos(r2);
            return this->cost[i];
        }
        return v;
    }
}
