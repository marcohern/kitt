#pragma once

#include "./Vector2D.hpp"

namespace Core {
	class Placeable {
	private:
		Vector2D location;

	public:
		Vector2D getLocation();

		void setLocation(double x, double y);
		void setLocation(const Vector2D &v);

		void move(double x, double y);
		void move(const Vector2D &v);
	};
}