
#include "CollisionRect.hpp"

namespace Collisions {
	CollisionRect::CollisionRect()
		: CollisionShape(COLLSHAPE_RECT), location(), size() {
		
	}

	CollisionRect::CollisionRect(const Vector2D &size)
		: CollisionShape(COLLSHAPE_RECT), location(), size(size) {}

	CollisionRect::CollisionRect(const Vector2D &location, const Vector2D &size)
		: CollisionShape(COLLSHAPE_RECT), location(location), size(size) {}

	CollisionRect::~CollisionRect() {
		CollisionShape::~CollisionShape();
	}

	Vector2D CollisionRect::getLocation() const {
		return this->location;
	}

	Vector2D CollisionRect::getSize() const {
		return this->size;
	}

	void  CollisionRect::setLocation(const Vector2D &location) {
		this->location.set(location);
	}

	void CollisionRect::addLocation(const Vector2D &delta) {
		this->location.add(delta);
	}

	bool CollisionRect::intersectsSensor(const Vector2D &sensor) const {
		Vector2D bottomRight(location);
		bottomRight.add(size);
		if (   sensor.getX() >= location.getX() 
			&& sensor.getX() <= bottomRight.getX()
			&& sensor.getY() >= location.getY()
			&& sensor.getY() <= bottomRight.getY()) {
			return true;
		}
		return false;
	}

	Vector2D CollisionRect::getCenter() const {
		return Vector2D(location.getX() + size.getX() / 2.0, location.getY() + size.getY() / 2.0);
	}

	vector<Vector2D> CollisionRect::getCorners() const {
		
		return { getTopLeftCorner(), getTopRightCorner(), getBottomLeftCorner(), getBottomRightCorner() };
	}

	Vector2D* CollisionRect::getClosestCorner(const Vector2D &point) const {
		Vector2D* closest = NULL;
		vector<Vector2D> corners = this->getCorners();
		double mindist = DBL_MAX;
		for (auto corner : corners) {
			if (closest == NULL) closest = &corner;
			else {
				if (mindist < sqrt(pow(corner.getX() - point.getX(), 2) + pow(corner.getY() - point.getY(), 2))) {
					closest = &corner;
				}
			}
		}
		return closest;
	}

	Vector2D CollisionRect::getClosestPoint(const Vector2D &point) const {
		Vector2D closestPoint(point);
		if      (point.getX() < location.getX()               ) closestPoint.setX(location.getX());
		else if (point.getX() > location.getX() + size.getX() ) closestPoint.setX(location.getX() + size.getX());
		else closestPoint.setX(point.getX());
		if      (point.getY() < location.getY()               ) closestPoint.setY(location.getY());
		else if (point.getY() > location.getY() + size.getY() ) closestPoint.setY(location.getY() + size.getY());
		else closestPoint.setY(point.getY());
		return closestPoint;
	}

	bool CollisionRect::collidesWith(const CollisionShape &shape) const {
		Vector2D closest = shape.getClosestPoint(getCenter());
		Vector2D* corner = shape.getClosestCorner(getCenter());
		if (intersectsSensor(closest)) return true;
		else if (corner != NULL && intersectsSensor(*corner)) return true;
		return false;
	}

	inline Vector2D CollisionRect::getTopLeftCorner() const {
		return location;
	}

	inline Vector2D CollisionRect::getTopRightCorner() const {
		return Vector2D(location.getX() + size.getX(), location.getY());
	}

	inline Vector2D CollisionRect::getBottomLeftCorner() const {
		return Vector2D(location.getX() + size.getX(), location.getY());
	}

	inline Vector2D CollisionRect::getBottomRightCorner() const {
		return Vector2D(location.getX() + size.getX(), location.getY() + size.getY());
	}
}