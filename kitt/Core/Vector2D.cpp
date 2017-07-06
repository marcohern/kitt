//
//  Vector2D.cpp
//  kitt
//
//  Created by Marco Hernandez on 29/06/17.
//  Copyright © 2017 Marco Hernandez. All rights reserved.
//
#include <math.h>
#include <sstream>

#include "../constants.hpp"
#include "./Vector2D.hpp"
#include "../Exceptions/DivideByZeroException.hpp"
#include "../Exceptions/NullReferenceException.hpp"

namespace Core {
    using namespace std;
    using namespace Exceptions;
    
    Vector2D::Vector2D(Trigonometry *trigo)
    : x(0), y(0), HasTrigonometry(trigo) {
	}

    Vector2D::Vector2D(double x, double y, Trigonometry *trigo)
    : x(x), y(y), HasTrigonometry(trigo) {
	}

    Vector2D::Vector2D(const Vector2D &v, Trigonometry *trigo)
    : x(v.x), y(v.y), HasTrigonometry(trigo) {
	}
    
    string Vector2D::toString() const {
        stringstream ss;
        ss<<"("<<this->x<<","<<this->y<<")";
        return ss.str();
    }

	double Vector2D::getX() const {
		return this->x;
	}

	double Vector2D::getY() const {
		return this->y;
	}

	int Vector2D::iX() const {
		return (int) this->x;
	}

	int Vector2D::iY() const {
		return (int) this->y;
	}

	void Vector2D::setX(double x) {
		this->x = x;
	}

	void Vector2D::setY(double y) {
		this->y = y;
	}

	void Vector2D::set(double x, double y) {
		this->x = x;
		this->y = y;
	}

	void Vector2D::set(const Vector2D &v) {
		this->set(v.x, v.y);
	}

	void Vector2D::add(double x, double y) {
		this->x += x;
		this->y += y;
	}

	void Vector2D::add(const Vector2D &v) {
		this->x += v.x;
		this->y += v.y;
	}

	void Vector2D::sub(double x, double y) {
		this->x -= x;
		this->y -= y;
	}

	void Vector2D::sub(const Vector2D &v) {
		this->x -= v.x;
		this->y -= v.y;
	}

	double Vector2D::magnitude() const {
		return sqrt(this->x*this->x + this->y*this->y);
    }
    
    inline double Vector2D::getMagnitude() const {
        return this->magnitude();
    }
    
    void Vector2D::setMagnitude(double m) {
        this->set(this->u());
        this->multiply(m);
    }
    
    void Vector2D::addMagnitude(double m) {
        this->setMagnitude(m-magnitude());
    }

	void Vector2D::multiply(double s) {
		this->x *= s;
		this->y *= s;
	}

	void Vector2D::divide(double s) {
        if (s==0.0) throw DivideByZeroException("Divide Vector by zero not allowed.");
		this->x /= s;
		this->y /= s;
	}

	double Vector2D::dot(const Vector2D &v) const {
		return this->x*v.x + this->y*v.y;
	}

	double Vector2D::angleBetween(Vector2D &v) const {
		double top = this->dot(v);
		double bottom = (this->magnitude() * v.magnitude());
		return top / bottom;
    }
    
    double Vector2D::angle() const {
        Vector2D r(*this);
        Vector2D positivex(1.0, 0.0, trigo);
        return r.angleBetween(positivex);
    }
    
    inline double Vector2D::getAngle() const {
        return this->angle();
    }
    
    void Vector2D::setAngle(double radians) {
        this->rotate(radians-angle());
    }
    
    void Vector2D::rotate(double radians) {
		double xx = this->x*trigo->cos(radians) - this->y*trigo->sin(radians);
		this->y = this->x*trigo->sin(radians) + this->y*trigo->cos(radians);
		this->x = xx;
    }

	void Vector2D::rotateDeg(double degrees) {
		this->rotate(TAU*degrees/360.0);
	}
    
    inline void Vector2D::addAngle(double radians) {
        this->rotate(radians);
    }
    
    Vector2D Vector2D::u() const {
        Vector2D r(*this);
        r.divide(r.magnitude());
        return r;
    }
    
    void Vector2D::setU() {
        this->divide(this->magnitude());
    }

	Vector2D operator + (const Vector2D &v) {
		return Vector2D(v.x, v.y, v.trigo);
	}

	Vector2D operator - (const Vector2D &v) {
		return Vector2D(-v.x, -v.y, v.trigo);
	}

	Vector2D operator + (const Vector2D &v1, const Vector2D &v2) {
		return Vector2D(v1.x + v2.x, v1.y + v2.y, v1.trigo);
	}

	Vector2D operator - (const Vector2D &v1, const Vector2D &v2) {
		return Vector2D(v1.x - v2.x, v1.y - v2.y, v1.trigo);
	}

	Vector2D operator * (const Vector2D &v, double s) {
		return Vector2D(v.x * s, v.y * s, v.trigo);
	}

	Vector2D operator * (double s, const Vector2D &v) {
		return v*s;
	}

	double operator * (const Vector2D &v1, const Vector2D &v2) {
		return v1.x*v2.x + v1.y*v2.y;
	}

    Vector2D operator / (const Vector2D &v, double s) {
        if (s==0)
            throw DivideByZeroException("Divide Vector by zero not allowed.");
		return Vector2D(v.x / s, v.y / s, v.trigo);
    }
    
    bool operator == (const Vector2D &v1, const Vector2D &v2) {
        return (v1.x == v2.x && v1.y == v2.y);
    }
    
    bool operator != (const Vector2D &v1, const Vector2D &v2) {
        return (v1.x != v2.x && v1.y != v2.y);
    }
    
    bool operator > (const Vector2D &v1, const Vector2D &v2) {
        return (v1.magnitude() > v2.magnitude());
    }
    
    bool operator >= (const Vector2D &v1, const Vector2D &v2) {
        return (v1.magnitude() >= v2.magnitude());
    }
    
    bool operator < (const Vector2D &v1, const Vector2D &v2) {
        return (v1.magnitude() < v2.magnitude());
    }
    
    bool operator <= (const Vector2D &v1, const Vector2D &v2) {
        return (v1.magnitude() <= v2.magnitude());
    }
}
