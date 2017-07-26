//
//  Rotateable.hpp
//  kitt
//
//  Created by Marco Hernandez on 25/07/17.
//  Copyright © 2017 Marco Hernandez. All rights reserved.
//

#ifndef Rotateable_hpp
#define Rotateable_hpp

#include "Angleable.hpp"

namespace Behaviors {
    class Rotateable : public Angleable {
    protected:
        double rotationRate;
        
    public:
        Rotateable();
        Rotateable(double radians);
        Rotateable(double px, double py);
        Rotateable(const Vector2D &pivot);
        Rotateable(double px, double py, double radians);
        Rotateable(const Vector2D &pivot, double radians);
        
        Rotateable(Trigonometry *trigo);
        Rotateable(double radians, Trigonometry *trigo);
        Rotateable(const Vector2D &pivot, Trigonometry *trigo);
        Rotateable(double px, double py, Trigonometry *trigo);
        Rotateable(const Vector2D &pivot, double radians, Trigonometry *trigo);
        Rotateable(double px, double py, double radians, Trigonometry *trigo);
        
        ~Rotateable();
        
        void setRotationRate(double rate);
        void addRotationRate(double rate);
        double getRotationRate() const;
        void updateAngle(double interval);
    };
}

#endif /* Rotateable_hpp */
