//
//  Rotateable.hpp
//  kitt
//
//  Created by Marco Hernandez on 23/07/17.
//  Copyright © 2017 Marco Hernandez. All rights reserved.
//

#ifndef Angleable_hpp
#define Angleable_hpp

#include "../Core/Vector2D.hpp"
#include "../Core/Trigonometry.hpp"

namespace Behaviors {
    using namespace Core;
    
    class Angleable {
    protected:
        double angle;
        Vector2D rotatePivot;
        
        
    public:
        Angleable();
        Angleable(double radians);
        Angleable(double px, double py);
        Angleable(const Vector2D &pivot);
        Angleable(double px, double py, double radians);
        Angleable(const Vector2D &pivot, double radians);
        
        virtual ~Angleable();
        
        void setAngle(double radians);
        void setRotatePivot(double px, double py);
        void setRotatePivot(const Vector2D &pivot);
        
        double getAngle() const;
		double getAngleDegrees() const;
        Vector2D getRotatePivot() const;
        
        void addAngle(double radians);
        double getAngleDisplacement(double radians) const;
        Vector2D getRotatePivotDisplacement(double radians) const;
        Vector2D getRotatePivotDisplacement(double radians, double zoom) const;
    };
}

#endif /* Rotateable_hpp */
