//
//  Placeable.hpp
//  kitt
//
//  Created by Marco Hernandez on 3/07/17.
//  Copyright © 2017 Marco Hernandez. All rights reserved.
//

#ifndef Placeable_hpp
#define Placeable_hpp

#include <stdio.h>
#include "./Vector2D.hpp"
#include "./Trigonometry.hpp"

namespace Core {
    class Placeable {
    protected:
        Vector2D location;
    public:
        Placeable(Trigonometry *trigo);
        Placeable(double x, double y, Trigonometry *trigo);
        Placeable(const Vector2D &v, Trigonometry *trigo);
        
        virtual ~Placeable();
        
        Vector2D getLocation() const;

        void setLocation(double x, double y);
        void setLocation(const Vector2D &v);
        
        void addLocation(double dx, double dy);
        void addLocation(const Vector2D &v);
    };
}

#endif /* Placeable_hpp */
