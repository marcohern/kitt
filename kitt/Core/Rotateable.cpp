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


	Rotateable::Rotateable(Trigonometry *trigo, Time *time)
		: Directable(trigo, time), deltaAngle(0) {}

	Rotateable::Rotateable(double x, double y, Trigonometry *trigo, Time *time)
		: Directable(x, y, trigo, time), deltaAngle(0) {}
	Rotateable::Rotateable(double x, double y, double dx, double dy, Trigonometry *trigo, Time *time)
		: Directable(x, y, dx, dy, trigo, time), deltaAngle(0) {}

	Rotateable::Rotateable(double x, double y, double dx, double dy, double radians, Trigonometry *trigo, Time *time)
		: Directable(x, y, dx, dy, trigo, time), deltaAngle(radians) {}

	Rotateable::Rotateable(const Vector2D &loc, Trigonometry *trigo, Time *time)
		: Directable(loc, trigo, time), deltaAngle(0) {}

	Rotateable::Rotateable(const Vector2D &loc, const Vector2D &dir, Trigonometry *trigo, Time *time)
		: Directable(loc, dir, trigo, time), deltaAngle(0) {}

	Rotateable::Rotateable(const Vector2D &loc, const Vector2D &dir, double radians, Trigonometry *trigo, Time *time)
		: Directable(loc, dir, trigo, time), deltaAngle(radians) {}

	Rotateable::~Rotateable() {
		Directable::~Directable();
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
}