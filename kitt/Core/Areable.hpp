//
//  Areable.hpp
//  kitt
//
//  Created by Marco Hernandez on 8/07/17.
//  Copyright © 2017 Marco Hernandez. All rights reserved.
//

#ifndef Areable_hpp
#define Areable_hpp

#include <stdio.h>
#include "Rotateable.hpp"
#include "Vector2D.hpp"
#include "Trigonometry.hpp"
#include "Time.hpp"

namespace Core {
    class Areable : public Rotateable {
        Vector2D pivotloc;
    protected:
        Vector2D size;
        Vector2D pivot;
        
    public:
        Areable();
        Areable(const Vector2D &location, const Vector2D &size);
        Areable(const Vector2D &location, const Vector2D &size, const Vector2D &pivot);
        
        Areable(Trigonometry *trigo);
        Areable(const Vector2D &location, const Vector2D &size, Trigonometry *trigo);
        Areable(const Vector2D &location, const Vector2D &size, const Vector2D &pivot, Trigonometry *trigo);
        
        virtual ~Areable();
        
        Vector2D getSize() const;
        Vector2D getPivot() const;
        void setSize(double w, double h);
        void setPivot(double px, double py);
        void setSize(const Vector2D &size);
        void setPivot(const Vector2D &pivot);
        
        Vector2D getPivotLocation();
        Vector2D getPivotDisplacement(const Vector2D &displacement);
        double getArea() const;
        
        virtual void update(double interval);
    };
}
#endif /* Areable_hpp */
