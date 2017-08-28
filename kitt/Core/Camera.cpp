//
//  Camera.cpp
//  kitt
//
//  Created by Marco Hernandez on 8/07/17.
//  Copyright © 2017 Marco Hernandez. All rights reserved.
//

#include "Camera.hpp"

namespace Core {
	Camera::Camera() 
		: location(), offset(), focus(NULL), zoom(1.0) {}

	Camera::Camera(double x, double y)
		: location(x,y), offset(), focus(NULL), zoom(1.0) {}

	Camera::Camera(const Vector2D &location)
		: location(location), offset(), focus(NULL), zoom(1.0) {}

	Camera::Camera(double x, double y, double ox, double oy)
		: location(x, y), offset(ox, oy), focus(NULL), zoom(1.0) {}

	Camera::Camera(const Vector2D &location, const Vector2D &offset)
		: location(location), offset(offset), focus(NULL), zoom(1.0) {}

	Camera::Camera(Trigonometry *trigo)
		: location(trigo), offset(trigo), focus(NULL), zoom(1.0) {}

	Camera::Camera(double x, double y, Trigonometry *trigo) 
		: location(x, y, trigo), offset(trigo), focus(NULL), zoom(1.0) {}

	Camera::Camera(const Vector2D &location, Trigonometry *trigo)
		: location(location, trigo), offset(trigo), focus(NULL), zoom(1.0) {}

	Camera::Camera(double x, double y, double ox, double oy, Trigonometry *trigo)
		: location(x, y, trigo), offset(ox, oy, trigo), focus(NULL), zoom(1.0) {}

	Camera::Camera(const Vector2D &location, const Vector2D &offset, Trigonometry *trigo)
		: location(location, trigo), offset(offset, trigo), focus(NULL), zoom(1.0) {}

	Camera::~Camera() {

	}

	void Camera::setFocusObject(Placeable *placeable) {
		focus = placeable;
	}

	void Camera::clearFocusObject() {
		focus = NULL;
	}

	void Camera::setLocation(double x, double y) {
		location.set(x,y);
	}

	void Camera::setLocation(const Vector2D &location) {
		this->location.set(location);
	}

	void Camera::setOffset(double x, double y) {
		this->offset.set(x, y);
	}
	void Camera::setOffset(const Vector2D &offset) {
		this->offset.set(offset);
	}

	void Camera::setZoom(double zoom) {
		this->zoom = zoom;
	}

	void Camera::addZoom(double z) {
		this->zoom += z;
	}

	Vector2D Camera::getLocation() const {
		return location;
	}

	Vector2D Camera::getOffset() const {
		return offset;
	}

	double Camera::getZoom() const {
		return zoom;
	}
}
