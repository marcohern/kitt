
#include "CollisionShape.hpp"

namespace Collisions {

	CollisionShape::CollisionShape(CollisionShapeType type) {
		this->type = type;
	}

	CollisionShape::~CollisionShape() {

	}

	CollisionShapeType CollisionShape::getType() const {
		return this->type;
	}

	/*
	bool CollisionShape::collidesWith(const CollisionShape &shape) const {
		Vector2D closestPoint = shape.getClosestPoint(this->getCenter());
		return intersectsSensor(closestPoint);
	}
	*/
}