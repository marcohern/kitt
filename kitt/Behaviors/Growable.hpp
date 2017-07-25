//
//  Growable.hpp
//  kitt
//
//  Created by Marco Hernandez on 23/07/17.
//  Copyright © 2017 Marco Hernandez. All rights reserved.
//

#ifndef Growable_hpp
#define Growable_hpp

#include "Scalable.hpp"
#include "../Core/Vector2D.hpp"
#include "../Core/Trigonometry.hpp"

namespace Behaviors{
    class Growable : public Scalable {
    protected:
        Vector2D growthRate;
        
    public:
        Growable();
        Growable(Trigonometry *trigo);
        
        virtual ~Growable();
        
        void setGrowthRate(double g);
        void setGrowthRate(const Vector2D &g);
        
        Vector2D getGrowthRate() const;
        double getGrowthRateX() const;
        double getGrowthRateY() const;
        
        void addGrowth(double ds);
        void addGrowth(const Vector2D &d);
        void multiplyGrowth(double ms);
        
        void updateScale(double interval);
    };
}

#endif /* Growable_hpp */
