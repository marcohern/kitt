#include "Rotateable.hpp"
#include "../constants.hpp"

namespace Core {

	Rotateable::Rotateable()
		: Directable(), deltaAngle(0) {}

	Rotateable::Rotateable(double x, double y)
		: Directable(x, y), deltaAngle(0) {}

	Rotateable::Rotateable(double x, double y, double dx, double dy)
		: Directable(x, y, dx, dy), deltaAngle(0) {}

	Rotateable::Rotateable(double x, double y, double dx, double dy, double radians) 
		: Directable(x,y,dx,dy), deltaAngle(radians) {}

	Rotateable::Rotateable(const Vector2D &loc)
		: Directable(loc), deltaAngle(0) {}

	Rotateable::Rotateable(const Vector2D &loc, const Vector2D &dir)
		: Directable(loc, dir), deltaAngle(0) {}

	Rotateable::Rotateable(const Vector2D &loc, const Vector2D &dir, double radians)
		: Directable(loc, dir), deltaAngle(radians) {}


	Rotateable::Rotateable(Trigonometry *trigo)
		: Directable(trigo), deltaAngle(0) {}

	Rotateable::Rotateable(double x, double y, Trigonometry *trigo)
		: Directable(x, y, trigo), deltaAngle(0) {}
	Rotateable::Rotateable(double x, double y, double dx, double dy, Trigonometry *trigo)
		: Directable(x, y, dx, dy, trigo), deltaAngle(0) {}

	Rotateable::Rotateable(double x, double y, double dx, double dy, double radians, Trigonometry *trigo)
		: Directable(x, y, dx, dy, trigo), deltaAngle(radians) {}

	Rotateable::Rotateable(const Vector2D &loc, Trigonometry *trigo)
		: Directable(loc, trigo), deltaAngle(0) {}

	Rotateable::Rotateable(const Vector2D &loc, const Vector2D &dir, Trigonometry *trigo)
		: Directable(loc, dir, trigo), deltaAngle(0) {}

	Rotateable::Rotateable(const Vector2D &loc, const Vector2D &dir, double radians, Trigonometry *trigo)
		: Directable(loc, dir, trigo), deltaAngle(radians) {}

	Rotateable::~Rotateable() {
		Directable::~Directable();
        Animateable::~Animateable();
	}

	void Rotateable::setDeltaAngle(double radians) {
		this->deltaAngle = radians;
	}

	void Rotateable::setDeltaAngleDeg(double degrees) {
		this->deltaAngle = TAU * degrees / 360.0;
	}

	void Rotateable::setAngle(double radians) {
		this->direction.setAngle(radians);
	}

	void Rotateable::setAngleDeg(double degrees) {
		this->direction.setAngle(TAU * degrees/360.0);
	}

	void Rotateable::rotate(double radians) {
		this->direction.rotate(radians);
	}

	void Rotateable::rotateDeg(double degrees) {
		this->direction.rotateDeg(degrees);
	}

	void Rotateable::update(double interval) {
		Directable::update(interval);
		this->direction.rotate(this->deltaAngle * interval);
	}
}
