//
//  Directable.hpp
//  kitt
//
//  Created by Marco Hernandez on 3/07/17.
//  Copyright © 2017 Marco Hernandez. All rights reserved.
//

#ifndef Directable_hpp
#define Directable_hpp

#include <stdio.h>
#include "./Placeable.hpp"
#include "./Trigonometry.hpp"
#include "./Time.hpp"

namespace Core {
    class Directable : public Placeable {
    private:
        Vector2D delta;
        void setTime(Time *time);
    protected:
        Vector2D direction;
        Time *time;
    public:
        Directable(Trigonometry *trigo, Time *time);
        Directable(double x, double y, Trigonometry *trigo, Time *time);
        Directable(double x, double y, double dx, double dy, Trigonometry *trigo, Time *time);
        Directable(const Vector2D &loc, Trigonometry *trigo, Time *time);
        Directable(const Vector2D &loc, const Vector2D &dir, Trigonometry *trigo, Time *time);
        
        virtual ~Directable();
        
        Vector2D getDirection();
        
        void setDirection(double dx, double dy);
        void setDirection(const Vector2D &dir);
        
        void addDirection(double dx, double dy);
        void addDirection(const Vector2D &dir);
        
        void updateLocation();
    };
}
#endif /* Directable_hpp */
