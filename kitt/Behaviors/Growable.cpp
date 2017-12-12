//
//  Growable.cpp
//  kitt
//
//  Created by Marco Hernandez on 23/07/17.
//  Copyright © 2017 Marco Hernandez. All rights reserved.
//

#include "Growable.hpp"

namespace Behaviors
{
    using namespace Core;
    
    Growable::Growable()
    : Scalable(), growthRate() {
        
    }
    
    Growable::~Growable() {
        Scalable::~Scalable();
    }
    
    void Growable::setGrowthRate(double g) {
        growthRate.set(g, g);
    }
    
    void Growable::setGrowthRate(const Vector2D &g) {
        growthRate.set(g);
    }
    
    Vector2D Growable::getGrowthRate() const {
        return growthRate;
    }
    
    double Growable::getGrowthRateX() const {
        return growthRate.getX();
    }
    
    double Growable::getGrowthRateY() const {
        return growthRate.getY();
    }
    
    void Growable::addGrowth(double ds) {
        growthRate.add(ds, ds);
    }
    
    void Growable::addGrowth(const Vector2D &d) {
        growthRate.add(d);
    }
    
    void Growable::multiplyGrowth(double ms) {
        growthRate.multiply(ms);
    }
    
    void Growable::updateScale(double interval) {
        scale.add(interval * growthRate);
    }
}
