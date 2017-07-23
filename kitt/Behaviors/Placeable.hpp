//
//  Placeable.hpp
//  kitt
//
//  Created by Marco Hernandez on 11/07/17.
//  Copyright © 2017 Marco Hernandez. All rights reserved.
//

#ifndef Placeable_hpp
#define Placeable_hpp

#include "../Core/Trigonometry.hpp"
#include "../Core/Vector2D.hpp"

namespace Behaviors {
    using namespace Core;
    
    class Placeable {
    protected:
        
        Vector2D location;
    public:
        Placeable();
        Placeable(double x, double y);
        Placeable(const Vector2D &v);
        
        Placeable(Trigonometry *trigo);
        Placeable(double x, double y, Trigonometry *trigo);
        Placeable(const Vector2D &v, Trigonometry *trigo);
        
        virtual ~Placeable();
        
        Vector2D getLocation() const;
        Vector2D getDisplacement(double dx, double dy) const;
        Vector2D getDisplacement(const Vector2D &displacement) const;
        
        void setLocation(double x, double y);
        void setLocation(const Vector2D &v);
        
        void addLocation(double dx, double dy);
        void addLocation(const Vector2D &v);
    };
}

#endif /* Placeable_hpp */