//
//  Moveable.hpp
//  kitt
//
//  Created by Marco Hernandez on 3/07/17.
//  Copyright © 2017 Marco Hernandez. All rights reserved.
//

#ifndef Moveable_hpp
#define Moveable_hpp

#include <stdio.h>
#include "./Placeable.hpp"
#include "./Trigonometry.hpp"
#include "./Time.hpp"

namespace Core {
    class Moveable : public Placeable {
    private:
        Vector2D delta;
        void setTime(Time *time);
    protected:
        Vector2D direction;
        Time *time;
    public:
        Moveable(Trigonometry *trigo, Time *time);
        Moveable(double x, double y, Trigonometry *trigo, Time *time);
        Moveable(double x, double y, double dx, double dy, Trigonometry *trigo, Time *time);
        Moveable(const Vector2D &loc, Trigonometry *trigo, Time *time);
        Moveable(const Vector2D &loc, const Vector2D &dir, Trigonometry *trigo, Time *time);
        
        virtual ~Moveable();
        
        Vector2D getDirection();
        
        void setDirection(double dx, double dy);
        void setDirection(const Vector2D &dir);
        
        void addDirection(double dx, double dy);
        void addDirection(const Vector2D &dir);
        
        void updateLocation();
    };
}
#endif /* Moveable_hpp */
