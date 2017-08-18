#pragma once

#include "CollisionShape.hpp"
#include "../Core/Trigonometry.hpp"

namespace Collisions {
	using namespace Core;

	class CollisionCircle : public CollisionShape {
	private:
		Vector2D center;
		double radius;

	public:
		CollisionCircle();
		CollisionCircle(double radius);
		CollisionCircle(const Vector2D &center, double radius);
		CollisionCircle(Trigonometry *trigo);
		CollisionCircle(double radius, Trigonometry *trigo);
		CollisionCircle(const Vector2D &center, double radius, Trigonometry *trigo);

		~CollisionCircle();

		double getRadius() const;
		Vector2D getCenter() const;

		void setRadius(double radius);
		void setCenter(const Vector2D &center);
		void addCenter(const Vector2D &delta);

		bool     intersectsSensor(const Vector2D &sensor) const;
		Vector2D getClosestPoint (const Vector2D  &point) const;
	};
}