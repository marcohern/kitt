//
//  Rotateable.hpp
//  kitt
//
//  Created by Marco Hernandez on 23/07/17.
//  Copyright © 2017 Marco Hernandez. All rights reserved.
//

#ifndef Rotateable_hpp
#define Rotateable_hpp

#include "../Core/Vector2D.hpp"
#include "../Core/Trigonometry.hpp"

namespace Behaviors {
    using namespace Core;
    
    class Rotateable {
    protected:
        double angle;
        Vector2D rotatePivot;
        
        
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
        
        virtual ~Rotateable();
        
        void setAngle(double radians);
        void setRotatePivot(double px, double py);
        void setRotatePivot(const Vector2D &pivot);
        
        double getAngle() const;
        Vector2D getRotatePivot() const;
        
        void addAngle(double radians);
        double getAngleDisplacement(double radians) const;
        Vector2D getRotatePivotDisplacement(double radians) const;
        Vector2D getRotatePivotDisplacement(double radians, double zoom) const;
    };
}

#endif /* Rotateable_hpp */
