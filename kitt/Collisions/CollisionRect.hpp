#pragma once

#include "CollisionShape.hpp"
#include "../Core/Vector2D.hpp"
#include "../Core/Trigonometry.hpp"

namespace Collisions {
	using namespace Core;

	class CollisionRect : public CollisionShape {
	private:
		Vector2D location, size;

	public:
		CollisionRect();
		CollisionRect(const Vector2D &size);
		CollisionRect(const Vector2D &location, const Vector2D &size);

		~CollisionRect();

		Vector2D getLocation() const;
		Vector2D getSize() const;

		void setLocation(const Vector2D &location);
		void addLocation(const Vector2D &delta);

		bool			 intersectsSensor(const Vector2D &sensor) const;
		Vector2D		 getCenter       (						) const;
		vector<Vector2D> getCorners		 (						) const;
		Vector2D*        getClosestCorner(const Vector2D &point ) const;
		Vector2D		 getClosestPoint (const Vector2D &point ) const;
		bool collidesWith(const CollisionShape &shape) const;

		inline Vector2D  getTopLeftCorner    () const;
		inline Vector2D  getTopRightCorner   () const;
		inline Vector2D  getBottomLeftCorner () const;
		inline Vector2D  getBottomRightCorner() const;
	};
}