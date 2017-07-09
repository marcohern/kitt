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
#include "./Animateable.hpp"

namespace Core {
    class Directable : public Placeable, public Animateable {
    protected:
        Vector2D direction;
    public:
		Directable();
		Directable(double x, double y);
		Directable(double x, double y, double dx, double dy);
		Directable(const Vector2D &loc);
		Directable(const Vector2D &loc, const Vector2D &dir);

        Directable(Trigonometry *trigo);
        Directable(double x, double y, Trigonometry *trigo);
        Directable(double x, double y, double dx, double dy, Trigonometry *trigo);
        Directable(const Vector2D &loc, Trigonometry *trigo);
        Directable(const Vector2D &loc, const Vector2D &dir, Trigonometry *trigo);
        
        virtual ~Directable();
        
        Vector2D getDirection();
        
        void setDirection(double dx, double dy);
        void setDirection(const Vector2D &dir);
        
        void addDirection(double dx, double dy);
        void addDirection(const Vector2D &dir);

		virtual void update(double interval);
    };
}
#endif /* Directable_hpp */
