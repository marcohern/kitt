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

        virtual ~Scalable();
        
        void setScale(double s);
        void setScale(double sx, double sy);
        void setScale(const Vector2D &scale);
        
        Vector2D getScale() const;
        double getScaleX() const;
        double getScaleY() const;
        
        void addScale(double ds);
        void addScale(double dx, double dy);
        void addScale(const Vector2D &delta);
        
        Vector2D getZoomScale(double zoom) const;
    };
}
#endif /* Scalable_hpp */
