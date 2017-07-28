#include "Transformable.hpp"
#include "../Core/Trigonometry.hpp"

namespace Behaviors {
	using namespace Core;

	Transformable::Transformable()
		: Directable()
	{
	}

	Transformable::Transformable(double x, double y)
		: Directable(x,y), Growable(), Rotateable()
	{
	}

	Transformable::Transformable(const Vector2D &location)
		: Directable(location), Growable(), Rotateable()
	{
	}

	Transformable::Transformable(Trigonometry *trigo)
		: Directable(trigo), Growable(trigo), Rotateable(trigo)
	{
	}

	Transformable::Transformable(double x, double y, Trigonometry *trigo)
		: Directable(x, y, trigo), Growable(trigo), Rotateable(trigo)
	{
	}

	Transformable::Transformable(const Vector2D &location, Trigonometry *trigo)
		: Directable(location, trigo), Growable(trigo), Rotateable(trigo)
	{
	}


	Transformable::~Transformable()
	{
		Directable::~Directable();
		Growable::~Growable();
		Rotateable::~Rotateable();
	}

	void Transformable::setRotateDirection(bool rotateDirection) {
		this->rotateDirection = rotateDirection;
		angle = direction.angle();
	}

	void Transformable::updateTransform(double interval) {
		updateLocation(interval);
		updateScale(interval);
		updateAngle(interval);
		if (rotateDirection) {
			direction.rotate(rotationRate * interval);
		}
	}
}

