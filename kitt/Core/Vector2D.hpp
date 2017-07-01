//
//  Vector2D.hpp
//  kitt
//
//  Created by Marco Hernandez on 29/06/17.
//  Copyright © 2017 Marco Hernandez. All rights reserved.
//

#ifndef Vector2D_hpp
#define Vector2D_hpp

#include <string>
#include <stdio.h>
#include <math.h>
#include "Object.hpp"
#include "Trigonometry.hpp"
#include "HasTrigonometry.hpp"

namespace Core {
    using namespace std;
    
    class Vector2D : public Object, public HasTrigonometry {
    private:
        double x, y;
        
    public:
        Vector2D(Trigonometry *trigo);
        Vector2D(double x, double y, Trigonometry *trigo);
        Vector2D(const Vector2D &v, Trigonometry *trigo);
        
        virtual string toString();
        
        double getX();
        double getY();
        
        void setX(double x);
        void setY(double y);
        void set(double x, double y);
		void set(const Vector2D &v);

        void add(double x, double y);
        void add(const Vector2D &v);
        void sub(double x, double y);
        void sub(const Vector2D &v);
        
        double magnitude() const;
        void multiply(double s);
        void divide(double s);
		double dot(const Vector2D &v) const;
		double angleBetween(Vector2D &v) const;
        void rotate(double radians);
        
        //inline friend Vector2D & operator = (const Vector2D &v);
        friend Vector2D operator + (const Vector2D &v);
        friend Vector2D operator - (const Vector2D &v);
        friend Vector2D operator + (const Vector2D &v1, const Vector2D &v2);
        friend Vector2D operator - (const Vector2D &v1, const Vector2D &v2);
        
        friend Vector2D operator * (const Vector2D &v, double s);
        friend Vector2D operator * (double s, const Vector2D &v);
		friend double   operator * (const Vector2D &v1, const Vector2D &v2);
        
        friend Vector2D operator / (const Vector2D &v, double s);
        
        friend bool operator == (const Vector2D &v1, const Vector2D &v2);
        friend bool operator != (const Vector2D &v1, const Vector2D &v2);
        friend bool operator >  (const Vector2D &v1, const Vector2D &v2);
        friend bool operator >= (const Vector2D &v1, const Vector2D &v2);
        friend bool operator <  (const Vector2D &v1, const Vector2D &v2);
        friend bool operator <= (const Vector2D &v1, const Vector2D &v2);
    };
}

#endif /* Vector2D_hpp */
