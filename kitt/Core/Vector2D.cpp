//
//  Vector2D.cpp
//  kitt
//
//  Created by Marco Hernandez on 29/06/17.
//  Copyright © 2017 Marco Hernandez. All rights reserved.
//
#include <math.h>
#include <sstream>

#include "./Vector2D.hpp"

namespace Core {
    using namespace std;
    
	Vector2D::Vector2D() {
		this->set(0, 0);
	}

	Vector2D::Vector2D(double x, double y) {
		this->set(x, y);
	}

	Vector2D::Vector2D(const Vector2D &v) {
		this->set(v.x, v.y);
	}
    
    string Vector2D::toString() {
        stringstream ss;
        ss<<"("<<this->x<<","<<this->y<<")";
        return ss.str();
    }

	double Vector2D::getX() {
		return this->x;
	}

	double Vector2D::getY() {
		return this->y;
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

	void Vector2D::multiply(double s) {
		this->x *= s;
		this->y *= s;
	}

	void Vector2D::divide(double s) {
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

	Vector2D operator + (const Vector2D &v) {
		return Vector2D(v.x, v.y);
	}

	Vector2D operator - (const Vector2D &v) {
		return Vector2D(-v.x, -v.y);
	}

	Vector2D operator + (const Vector2D &v1, const Vector2D &v2) {
		return Vector2D(v1.x + v2.x, v1.y + v2.y);
	}

	Vector2D operator - (const Vector2D &v1, const Vector2D &v2) {
		return Vector2D(v1.x - v2.x, v1.y - v2.y);
	}

	Vector2D operator * (const Vector2D &v, double s) {
		return Vector2D(v.x * s, v.y * s);
	}

	Vector2D operator * (double s, const Vector2D &v) {
		return v*s;
	}

	double operator * (const Vector2D &v1, const Vector2D &v2) {
		return v1.x*v2.x + v1.y*v2.y;
	}

	Vector2D operator / (const Vector2D &v, double s) {
		return Vector2D(v.x / s, v.y / s);
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
