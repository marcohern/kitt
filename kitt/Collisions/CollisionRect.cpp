
#include "CollisionRect.hpp"

namespace Collisions {
	CollisionRect::CollisionRect()
		: location(), size() {}

	CollisionRect::CollisionRect(const Vector2D &size)
		: location(), size(size) {}

	CollisionRect::CollisionRect(const Vector2D &location, const Vector2D &size)
		: location(location), size(size) {}

	CollisionRect::CollisionRect(Trigonometry *trigo)
		: location(trigo), size(trigo) {}

	CollisionRect::CollisionRect(const Vector2D &size, Trigonometry *trigo)
		: location(trigo), size(size, trigo) {}

	CollisionRect::CollisionRect(const Vector2D &location, const Vector2D &size, Trigonometry *trigo)
		: location(location, trigo), size(size, trigo) {}

	CollisionRect::~CollisionRect() {

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

	Vector2D CollisionRect::getClosestPoint(const Vector2D &point) const {
		Vector2D closestPoint(point);
		if      (point.getX() < location.getX()               ) closestPoint.setX(location.getX());
		else if (point.getX() > location.getX() + size.getX() ) closestPoint.setX(location.getX() + size.getX());
		if      (point.getY() < location.getY()               ) closestPoint.setY(location.getY());
		else if (point.getY() > location.getY() + size.getY() ) closestPoint.setY(location.getY() + size.getY());
		return closestPoint;
	}
}