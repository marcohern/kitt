#pragma once

#include "../Core/Trigonometry.hpp"
#include "../Core/Vector2D.hpp"
#include "Directable.hpp"
#include "Growable.hpp"
#include "Rotateable.hpp"
#include "Areable.hpp"

namespace Behaviors {
	using namespace Core;

	class Transformable : public Directable, public Growable, public Rotateable, public Areable
	{
	private:
		bool rotateDirection = false;
		bool growArea = false;

	public:
		Transformable();
		Transformable(double x, double y);
		Transformable(const Vector2D &location);
		Transformable(double x, double y, double w, double h);
		Transformable(const Vector2D &location, const Vector2D &area);
		Transformable(double x, double y, double w, double h, double px, double py);
		Transformable(const Vector2D &location, const Vector2D &area, const Vector2D &areaPivot);
		Transformable(double x, double y, double w, double h, double px, double py, double rx, double ry);
		Transformable(const Vector2D &location, const Vector2D &area, const Vector2D &areaPivot, const Vector2D &rotationPivot);


		virtual ~Transformable();

		void setRotateDirection(bool rotateDirection);
		void setGrowArea(bool growArea);
		bool isDirectionRotating();
		bool isAreaGrowing();
		void updateTransform(double interval);
		Vector2D getScaledArea();
		Vector2D getScaledAreaPivot();
	};
}


