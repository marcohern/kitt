
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
		Vector2D tl(location)
			, tr(location.getX() + size.getX(), location.getY())
			, bl(location.getX(), location.getY() + size.getY())
			, br(location + size);
		return { tl, tr, br, bl };
	}

	Vector2D CollisionRect::getClosestPoint(const Vector2D &point) const {
		Vector2D closestPoint(point);
		if      (point.getX() < location.getX()               ) closestPoint.setX(location.getX());
		else if (point.getX() > location.getX() + size.getX() ) closestPoint.setX(location.getX() + size.getX());
		if      (point.getY() < location.getY()               ) closestPoint.setY(location.getY());
		else if (point.getY() > location.getY() + size.getY() ) closestPoint.setY(location.getY() + size.getY());
		return closestPoint;
	}

	bool CollisionRect::collidesWith(const CollisionShape &shape) const {
		Vector2D closest = shape.getClosestPoint(getCenter());
		if (intersectsSensor(closest)) return true;
		else {
			vector<Vector2D> corners = shape.getCorners();
			for (auto c : corners) {
				if (intersectsSensor(c)) return true;
			}
		}
		return false;
	}
}