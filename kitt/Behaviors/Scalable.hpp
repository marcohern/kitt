//
//  Scalable.hpp
//  kitt
//
//  Created by Marco Hernandez on 22/07/17.
//  Copyright © 2017 Marco Hernandez. All rights reserved.
//

#ifndef Scalable_hpp
#define Scalable_hpp

#include "../Core/Vector2D.hpp"

namespace Behaviors {
    using namespace Core;
    
	/**
	* Allows object to be scalable by keeping track of a scale vector
	**/
    class Scalable {
    protected:
		//Scale vector
        Vector2D scale;
        
    public:

		/**
		* Constructor
		*/
        Scalable();

		/**
		* Constructor
		* @param s uniform scale value
		*/
        Scalable(double s);

		/**
		* Constructor
		* @param sx scale on X axis
		* @param sy scale on Y axis
		*/
        Scalable(double sx, double sy);

		/**
		* Constructor
		* @param scale Scale vector (X and Y)
		*/
        Scalable(const Vector2D &scale);

		/**
		* Destructor
		*/
        virtual ~Scalable();
        
		/**
		* Set the uniform scale value
		* @param s uniform scale value
		*/
        void setScale(double s);

		/**
		* Set scale value for each axis
		* @param sx x scale value
		* @param sy y scale value
		*/
        void setScale(double sx, double sy);

		/**
		* Set scale vector
		* @param scale Scale vector
		*/
        void setScale(const Vector2D &scale);
        
		/**
		* Get the scale vector value
		* @returns Scale vector
		*/
        Vector2D getScale() const;

		/**
		* Get the X scale value
		* @returns X scale
		*/
        double getScaleX() const;

		/**
		* Get the Y scale value
		* @returns Y scale
		*/
        double getScaleY() const;
        
		/**
		* Add a scalar value to the scale vector
		* @param ds uniform scale value
		*/
        void addScale(double ds);
		
		/**
		* Add x and y values to the scale vector
		* @param dx X scale value
		* @param dy Y scale value
		*/
        void addScale(double dx, double dy);

		/**
		* Add vector to the scale vector
		* @param scale Scale vector
		*/
        void addScale(const Vector2D &delta);
        
		/**
		* Get the scale vector adjusted to camera zoom
		* @param zoom Zoom value
		*/
        Vector2D getZoomScale(double zoom) const;
    };
}
#endif /* Scalable_hpp */
