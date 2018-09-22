//
//  Rotateable.hpp
//  kitt
//
//  Created by Marco Hernandez on 23/07/17.
//  Copyright © 2017 Marco Hernandez. All rights reserved.
//

#ifndef Angleable_hpp
#define Angleable_hpp

#include "../Core/Vector2D.hpp"
#include "../Core/Trigonometry.hpp"

namespace Behaviors {
    using namespace Core;
    
	/**
	 * Applies an angle to an object
	 */
    class Angleable {
    protected:

		//!Angle
        double angle;

		//!Rotation Pivot
        Vector2D rotatePivot;
        
        
    public:
		/**
		 * Constructor
		 */
        Angleable();


		/**
		* Constructor
		* @param radians default value for angle in radians
		*/
        Angleable(double radians);

		/**
		* Constructor
		* @param px Rotation Pivot X value
		* @param py Rotation Pivot Y value
		*/
        Angleable(double px, double py);



		/**
		* Constructor
		* @param pivot Rotation Pivot value
		*/
        Angleable(const Vector2D &pivot);

		/**
		* Constructor
		* @param px Rotation Pivot X value
		* @param py Rotation Pivot Y value
		* @param radians default value for angle in radians
		*/
        Angleable(double px, double py, double radians);

		/**
		* Constructor
		* @param pivot Rotation Pivot value
		* @param radians default value for angle in radians
		*/
        Angleable(const Vector2D &pivot, double radians);
        
		/**
		* Destructor
		*/
        virtual ~Angleable();

		/**
		* Set the angle value in radians
		* @param radians default value for angle in radians
		*/
        void setAngle(double radians);

		/**
		* Set the rotation pivot
		* @param px Rotation Pivot X value
		* @param py Rotation Pivot Y value
		*/
        void setRotatePivot(double px, double py);

		/**
		* Set the rotation pivot
		* @param pivot Rotation Pivot value
		*/
        void setRotatePivot(const Vector2D &pivot);
        
		/**
		* Get the angle 
		* @returns Angle in radians (from 0 to PI to TAU)
		*/
        double getAngle() const;

		/**
		* Get the angle
		* @returns Angle in degrees (from 0 to 180 to 360)
		*/
		double getAngleDegrees() const;

		/**
		* Get the rotation pivot
		* @returns Rotation pivot
		*/
        Vector2D getRotatePivot() const;
        
		/**
		* Add an amount to the current angle
		* @param radians angle to add in radians
		*/
        void addAngle(double radians);

		/**
		* Get the angle value with an additional added amount.
		* @param radians angle to add in radians
		* @returns summed angle
		*/
        double getAngleDisplacement(double radians) const;

		/**
		* Add an angle amount to the pivot vector
		* @param radians angle to add in radians
		* @returns pivot with the added angle
		*/
        Vector2D getRotatePivotDisplacement(double radians) const;

		/**
		* Add an angle amount to the pivot vector
		* @param radians angle to add in radians
		* @param zoom camera zoom amount
		* @returns pivot with the added angle
		*/
        Vector2D getRotatePivotDisplacement(double radians, double zoom) const;
    };
}

#endif /* Rotateable_hpp */
