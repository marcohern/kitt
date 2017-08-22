#pragma once

#include "../Core/Vector2D.hpp"
#include <vector>

namespace Collisions {
	using namespace std;
	using namespace Core;

	typedef enum {
		COLLSHAPE_RECT   = 0x1,
		COLLSHAPE_CIRCLE = 0x2
	} CollisionShapeType;

	class CollisionShape {
	protected:
		CollisionShapeType type;

	public:
		CollisionShape(CollisionShapeType type);
		virtual ~CollisionShape();

		CollisionShapeType getType() const;
		virtual bool			 intersectsSensor(const Vector2D       &sensor) const = 0;
		virtual Vector2D		 getClosestPoint (const Vector2D       &point ) const = 0;
		virtual Vector2D		 getCenter       (							  ) const = 0;
		virtual vector<Vector2D> getCorners		 (							  ) const = 0;
		virtual bool			 collidesWith    (const CollisionShape &shape ) const = 0;
	};
}