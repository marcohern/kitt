#pragma once

#include "../Core/Trigonometry.hpp"
#include "../Core/Vector2D.hpp"
#include "Directable.hpp"
#include "Growable.hpp"
#include "Rotateable.hpp"

namespace Behaviors {
	using namespace Core;

	class Transformable : public Directable, public Growable, public Rotateable
	{
	private:
		bool rotateDirection = false;

	public:
		Transformable();
		Transformable(double x, double y);
		Transformable(const Vector2D &location);
		Transformable(Trigonometry *trigo);
		Transformable(double x, double y, Trigonometry *trigo);
		Transformable(const Vector2D &location, Trigonometry *trigo);

		virtual ~Transformable();

		void setRotateDirection(bool rotateDirection);
		void updateTransform(double interval);
	};
}


