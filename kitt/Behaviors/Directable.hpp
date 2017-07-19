//
//  Directable.hpp
//  kitt
//
//  Created by Marco Hernandez on 18/07/17.
//  Copyright © 2017 Marco Hernandez. All rights reserved.
//

#ifndef Directable_hpp
#define Directable_hpp

#include "./Placeable.hpp"
#include "../Core/Vector2D.hpp"
#include "../Core/Trigonometry.hpp"

namespace Behaviors
{
    class Directable : public Placeable {
    private:
        Vector2D _direction;
        
    protected:
        Vector2D direction;
        
    public:
        Directable();
        Directable(double x, double y);
        Directable(const Vector2D &v);
        Directable(Trigonometry *trigo);
        Directable(double x, double y, Trigonometry *trigo);
        Directable(const Vector2D &v, Trigonometry *trigo);
        
        virtual ~Directable();
        
        Vector2D getDirection() const;
        void setDirection(double dx, double dy);
        void setDirection(const Vector2D &v);
        void addDirection(const Vector2D &v);
        
        void updateLocation(double interval);
    };
}
#endif /* Directable_hpp */
