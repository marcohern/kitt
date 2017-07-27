//
//  Areable.hpp
//  kitt
//
//  Created by Marco Hernandez on 26/07/17.
//  Copyright © 2017 Marco Hernandez. All rights reserved.
//

#ifndef Areable_hpp
#define Areable_hpp

#include "../Core/Vector2D.hpp"
#include "../Core/Trigonometry.hpp"

namespace Behaviors {
    using namespace Core;
    
    class Areable {
    protected:
        Vector2D area;
        Vector2D areaPivot;
        
    public:
        Areable();
        Areable(double w, double h);
        Areable(double w, double h, double px, double py);
        Areable(const Vector2D &area);
        Areable(const Vector2D &area, const Vector2D &pivot);
        
        Areable(Trigonometry *trigo);
        Areable(double w, double h, Trigonometry *trigo);
        Areable(double w, double h, double px, double py, Trigonometry *trigo);
        Areable(const Vector2D &area, Trigonometry *trigo);
        Areable(const Vector2D &area, const Vector2D &pivot, Trigonometry *trigo);
        
        virtual ~Areable();
        
        void setWidth(double w);
        void setHeight(double h);
        void setAreaVector(double w, double h);
        void setAreaVector(const Vector2D &area);
        void setAreaPivot(double px, double py);
        void setAreaPivot(const Vector2D &pivot);
        
        double getWidth() const;
        double getHeight() const;
        Vector2D getAreaVector() const;
        double getArea() const;
        Vector2D getAreaPivot() const;
        
        Vector2D getPivotLocation(Vector2D location) const;
    };
}

#endif /* Areable_hpp */
