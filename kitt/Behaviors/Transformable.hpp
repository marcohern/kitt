#pragma once

#include "../Core/Trigonometry.hpp"
#include "../Core/Vector2D.hpp"
#include "Directable.hpp"
#include "Growable.hpp"
#include "Rotateable.hpp"
#include "Areable.hpp"

namespace Behaviors {
	using namespace Core;
	/**
	* Allows instance to be transformable.
	*/
	class Transformable : public Directable, public Growable, public Rotateable, public Areable
	{
	private:
		//Whether to rotate clockwise or counterclockwise
		bool rotateClockwise = false;

		//Whether or not the area grows
		bool growArea = false;

	public:
		/**
		* Constructor
		*/
		Transformable();

		/**
		* Constructor
		* @param x Location X
		* @param x Location Y
		*/
		Transformable(double x, double y);

		/**
		* Constructor
		* @param location Location
		*/
		Transformable(const Vector2D &location);

		/**
		* Constructor
		* @param x Location X
		* @param x Location Y
		* @param w Width
		* @param h Height
		*/
		Transformable(double x, double y, double w, double h);

		/**
		* Constructor
		* @param location Location
		* @param area Area
		*/
		Transformable(const Vector2D &location, const Vector2D &area);

		/**
		* Constructor
		* @param x Location X
		* @param x Location Y
		* @param w Width
		* @param h Height
		* @param px Pivot X
		* @param px Pivot Y
		*/
		Transformable(double x, double y, double w, double h, double px, double py);

		/**
		* Constructor
		* @param location Location
		* @param area Area
		* @param areaPivot Area Pivot
		*/
		Transformable(const Vector2D &location, const Vector2D &area, const Vector2D &areaPivot);

		/**
		* Constructor
		* @param x Location X
		* @param x Location Y
		* @param w Width
		* @param h Height
		* @param px Pivot X
		* @param py Pivot Y
		* @param rx Rotation Pivot X
		* @param ry Rotation Pivot Y
		*/
		Transformable(double x, double y, double w, double h, double px, double py, double rx, double ry);

		/**
		* Constructor
		* @param location Location
		* @param area Area
		* @param areaPivot Area Pivot
		* @param rotationPivot Rotation Pivot
		*/
		Transformable(const Vector2D &location, const Vector2D &area, const Vector2D &areaPivot, const Vector2D &rotationPivot);

		/**
		* Destructor
		*/
		virtual ~Transformable();

		/**
		* Set Rotation Direction
		* @param rotateClockwise Clockwise if true, false otherwise
		*/
		void setRotateDirection(bool rotateClockwise);

		/**
		* Set Grow Area
		* @param growArea Grow Area if true, false otherwise
		*/
		void setGrowArea(bool growArea);

		/**
		* Is the object rotating clockwise
		* @retuns rotateClockwise
		*/
		bool isRotatingClockwise();

		/**
		* Is the area growing set
		* @retuns growArea
		*/
		bool isAreaGrowing();

		/**
		* Update Transformation according to time
		* @param interval Time Interval
		*/
		void updateTransform(double interval);

		/**
		* Get the Area measured with he scale
		* @returns Scaled area
		*/
		Vector2D getScaledArea();

		/**
		* Get the Area pivot
		* @returns Area Pivot
		*/
		Vector2D getScaledAreaPivot();
	};
}


