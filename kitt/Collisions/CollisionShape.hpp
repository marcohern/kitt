#pragma once

#include "../Core/Vector2D.hpp"

namespace Collisions {
	using namespace Core;

	class CollisionShape {
	public:
		virtual bool     intersectsSensor(const Vector2D       &sensor) const = 0;
		virtual Vector2D getClosestPoint (const Vector2D       &point ) const = 0;
		virtual Vector2D getCenter() const = 0;
		virtual bool     collidesWith    (const CollisionShape &shape ) const;
	};
}