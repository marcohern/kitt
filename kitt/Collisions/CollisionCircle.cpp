#include "CollisionCircle.hpp"

namespace Collisions {
	CollisionCircle::CollisionCircle()
		: CollisionShape(COLLSHAPE_CIRCLE), center(), radius(0) {}

	CollisionCircle::CollisionCircle(double radius)
		: CollisionShape(COLLSHAPE_CIRCLE), center(), radius(radius) {}

	CollisionCircle::CollisionCircle(const Vector2D &center, double radius)
		: CollisionShape(COLLSHAPE_CIRCLE), center(center), radius(radius) {}

	CollisionCircle::~CollisionCircle() {
		CollisionShape::~CollisionShape();
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

	vector<Vector2D> CollisionCircle::getCorners() const {
		return vector<Vector2D>();
	}

	Vector2D* CollisionCircle::getClosestCorner(const Vector2D &point) const {
		return NULL;
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

	bool CollisionCircle::collidesWith(const CollisionShape &shape) const {
		if (shape.getType() == COLLSHAPE_RECT) {
			return shape.collidesWith(*this);
		}
		else {
			return this->intersectsSensor(shape.getClosestPoint(this->getCenter()));
		}
		return false;
	}
}