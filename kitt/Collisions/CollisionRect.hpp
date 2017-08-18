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

		CollisionRect(Trigonometry *trigo);
		CollisionRect(const Vector2D &size, Trigonometry *trigo);
		CollisionRect(const Vector2D &location, const Vector2D &size, Trigonometry *trigo);

		~CollisionRect();

		Vector2D getLocation() const;
		Vector2D getSize() const;

		void setLocation(const Vector2D &location);
		void addLocation(const Vector2D &delta);

		bool     intersectsSensor(const Vector2D       &sensor) const;
		Vector2D getCenter       (                            ) const;
		Vector2D getClosestPoint (const Vector2D       &point ) const;
	};
}