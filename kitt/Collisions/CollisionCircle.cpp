#include "CollisionCircle.hpp"

namespace Collisions {
	CollisionCircle::CollisionCircle()
		: center(), radius(0) {}

	CollisionCircle::CollisionCircle(double radius)
		: center(), radius(radius) {}

	CollisionCircle::CollisionCircle(const Vector2D &center, double radius)
		: center(center), radius(radius) {}

	CollisionCircle::CollisionCircle(Trigonometry *trigo)
		: center(trigo), radius(0) {}

	CollisionCircle::CollisionCircle(double radius, Trigonometry *trigo)
		: center(trigo), radius(radius) {}

	CollisionCircle::CollisionCircle(const Vector2D &center, double radius, Trigonometry *trigo)
		: center(center, trigo), radius(radius) {}

	CollisionCircle::~CollisionCircle() {

	}

	double CollisionCircle::getRadius() const {
		return radius;
	}

	Vector2D CollisionCircle::getCenter() const {
		return center;
	}

	void CollisionCircle::setRadius(double radius) {
		this->radius = radius;
	}

	void CollisionCircle::setCenter(const Vector2D &center) {
		this->center.set(center);
	}

	void CollisionCircle::addCenter(const Vector2D &center) {
		this->center.add(center);
	}

	bool CollisionCircle::intersectsSensor(const Vector2D &sensor) const {
		Vector2D aim(center);
		aim.sub(sensor);
		if (aim.magnitude() < radius) return true;
		return false;
	}

	Vector2D CollisionCircle::getClosestPoint(const Vector2D  &point) const {
		Vector2D toPoint(point);
		toPoint.sub(center);
		Vector2D closestPoint = toPoint.u() * radius;
		double dist = toPoint.magnitude();
		if (dist < radius) {
			return point;
		}
		return closestPoint;
	}
}