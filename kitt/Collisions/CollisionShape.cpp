
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
}