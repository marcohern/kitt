//
//  Scalable.hpp
//  kitt
//
//  Created by Marco Hernandez on 22/07/17.
//  Copyright © 2017 Marco Hernandez. All rights reserved.
//

#ifndef Scalable_hpp
#define Scalable_hpp

#include "../Core/Vector2D.hpp"

namespace Behaviors {
    using namespace Core;
    
    class Scalable {
    protected:
        Vector2D scale;
        
    public:
        Scalable();
        Scalable(double s);
        Scalable(double sx, double sy);
        Scalable(const Vector2D &scale);
        
        Scalable(Trigonometry *trigo);
        Scalable(double s, Trigonometry *trigo);
        Scalable(double sx, double sy, Trigonometry *trigo);
        Scalable(const Vector2D &scale, Trigonometry *trigo);
        virtual ~Scalable();
        
        void setScale(double s);
        void setScale(double sx, double sy);
        void setScale(const Vector2D &scale);
        
        Vector2D getScale();
        double getScaleX();
        double getScaleY();
        
        void addScale(double ds);
        void addScale(double dx, double dy);
        void addScale(const Vector2D &delta);
        
        Vector2D getZoomScale(double zoom);
    };
}
#endif /* Scalable_hpp */
