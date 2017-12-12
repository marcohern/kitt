#include "Transformable.hpp"
#include "../Core/Trigonometry.hpp"

namespace Behaviors {
	using namespace Core;

	Transformable::Transformable()
		: Directable(), Growable(), Rotateable(), Areable()
		, rotateDirection(false), growArea(false)
	{
	}

	Transformable::Transformable(double x, double y)
		: Directable(x,y), Growable(), Rotateable(), Areable()
		, rotateDirection(false), growArea(false)
	{
	}

	Transformable::Transformable(const Vector2D &location)
		: Directable(location), Growable(), Rotateable(), Areable()
		, rotateDirection(false), growArea(false)
	{
	}

	Transformable::Transformable(double x, double y, double w, double h) 
		: Directable(x,y), Growable(), Rotateable(), Areable(w,h)
		, rotateDirection(false), growArea(false)
	{
	}

	Transformable::Transformable(const Vector2D &location, const Vector2D &area) 
		: Directable(location), Growable(), Rotateable(), Areable(area)
		, rotateDirection(false), growArea(false)
	{
	}

	Transformable::Transformable(double x, double y, double w, double h, double px, double py)
		: Directable(x,y), Growable(), Rotateable(), Areable(w,h, px, py)
		, rotateDirection(false), growArea(false)
	{
	}

	Transformable::Transformable(const Vector2D &location, const Vector2D &area, const Vector2D &areaPivot)
		: Directable(location), Growable(), Rotateable(), Areable(area, areaPivot) 
		, rotateDirection(false), growArea(false)
	{
	}

	Transformable::Transformable(double x, double y, double w, double h, double px, double py, double rx, double ry)
		: Directable(x, y), Growable(), Rotateable(rx, ry), Areable(w, h, px, py)
		, rotateDirection(false), growArea(false)
	{
	}

	Transformable::Transformable(const Vector2D &location, const Vector2D &area, const Vector2D &areaPivot, const Vector2D &rotationPivot)
		: Directable(location), Growable(), Rotateable(rotationPivot), Areable(area, areaPivot)
		, rotateDirection(false), growArea(false)
	{
	}

	Transformable::~Transformable()
	{
		Directable::~Directable();
		Growable::~Growable();
		Rotateable::~Rotateable();
		Areable::~Areable();
	}

	void Transformable::setRotateDirection(bool rotateDirection) {
		this->rotateDirection = rotateDirection;
	}

	void Transformable::setGrowArea(bool growAarea) {
		this->growArea = growAarea;
	}

	void Transformable::updateTransform(double interval) {
		updateLocation(interval);
		updateScale(interval);
		updateAngle(interval);
		if (rotateDirection) {
			direction.rotate(rotationRate * interval);
		}
		if (growArea) {
			area.add(growthRate * interval);
		}
	}

	bool Transformable::isDirectionRotating() {
		return rotateDirection;
	}

	bool Transformable::isAreaGrowing() {
		return growArea;
	}

	Vector2D Transformable::getScaledArea() {
		return Vector2D(area.getX() * scale.getX(), area.getY() * scale.getY());
	}

	Vector2D Transformable::getScaledAreaPivot() {
		return Vector2D(areaPivot.getX() * scale.getX(), areaPivot.getY() * scale.getY());
	}
}

