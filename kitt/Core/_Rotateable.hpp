#pragma once

#include "_Directable.hpp"

namespace Core {
	class Rotateable : public Directable {
		double deltaAngle;
	public:

		Rotateable();
		Rotateable(double x, double y);
		Rotateable(double x, double y, double dx, double dy);
		Rotateable(double x, double y, double dx, double dy, double radians);
		Rotateable(const Vector2D &loc);
		Rotateable(const Vector2D &loc, const Vector2D &dir);
		Rotateable(const Vector2D &loc, const Vector2D &dir, double radians);

		Rotateable(Trigonometry *trigo);
		Rotateable(double x, double y, Trigonometry *trigo);
		Rotateable(double x, double y, double dx, double dy, Trigonometry *trigo);
		Rotateable(double x, double y, double dx, double dy, double radians, Trigonometry *trigo);
		Rotateable(const Vector2D &loc, Trigonometry *trigo);
		Rotateable(const Vector2D &loc, const Vector2D &dir, Trigonometry *trigo);
		Rotateable(const Vector2D &loc, const Vector2D &dir, double radians, Trigonometry *trigo);
		
		virtual ~Rotateable();
		void setDeltaAngle(double radians);
		void setDeltaAngleDeg(double degrees);
		void setAngle(double radians);
		void setAngleDeg(double degrees);
		void rotate(double radians);
		void rotateDeg(double degrees);

		virtual void update(double interval);
	};
}
