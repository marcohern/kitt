//
//  Rotateable.hpp
//  kitt
//
//  Created by Marco Hernandez on 25/07/17.
//  Copyright © 2017 Marco Hernandez. All rights reserved.
//

#ifndef Rotateable_hpp
#define Rotateable_hpp

#include "Angleable.hpp"

namespace Behaviors {

	/**
	* Allows an object to rotate
	*/
    class Rotateable : public Angleable {
    protected:
        double rotationRate;
        
    public:

		/**
		* Constructor
		*/
        Rotateable();

		/**
		* Constructor
		* @param radians Angle in Radians
		*/
        Rotateable(double radians);

		/**
		* Constructor
		* @param px Rotation Pivot X
		* @param py Rotation Pivot Y
		*/
        Rotateable(double px, double py);

		/**
		* Constructor
		* @param pivot Rotation Pivot
		*/
        Rotateable(const Vector2D &pivot);

		/**
		* Constructor
		* @param px Rotation Pivot X
		* @param py Rotation Pivot Y
		* @param radians Angle in Radians
		*/
        Rotateable(double px, double py, double radians);

		/**
		* Constructor
		* @param pivot Rotation Pivot
		* @param radians Angle in Radians
		*/
        Rotateable(const Vector2D &pivot, double radians);
        
		/**
		* Destructor
		*/
        virtual ~Rotateable();
        
		/**
		* Set the Rotation Rate
		* @param rate Rotation Rate
		*/
        void setRotationRate(double rate);

		/**
		* Add to the Rotation Rate
		* @param rate value to add
		*/
        void addRotationRate(double rate);

		/**
		* Get Rotation Rate
		* @returns Rotation Rate
		*/
        double getRotationRate() const;

		/**
		* Update angle given rotationrate
		* @returns Time interval
		*/
        void updateAngle(double interval);
    };
}

#endif /* Rotateable_hpp */
