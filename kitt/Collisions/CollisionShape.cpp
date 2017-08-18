
#include "CollisionShape.hpp"

namespace Collisions {

	bool CollisionShape::collidesWith(const CollisionShape &shape) const {
		Vector2D closestPoint = shape.getClosestPoint(this->getCenter());
		return intersectsSensor(closestPoint);
	}

}