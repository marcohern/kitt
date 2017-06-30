#pragma once

#include "Vector2D.hpp"

namespace Core{

	class Camera {
	private:
		Vector2D location;

	public:
		Camera(const Vector2D &location);
		virtual ~Camera();
	};
}