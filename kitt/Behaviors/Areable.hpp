//
//  Areable.hpp
//  kitt
//
//  Created by Marco Hernandez on 26/07/17.
//  Copyright © 2017 Marco Hernandez. All rights reserved.
//

#ifndef Areable_hpp
#define Areable_hpp

#include "../Core/Vector2D.hpp"
#include "../Core/Trigonometry.hpp"

namespace Behaviors {
    using namespace Core;
    
	/**
	 * Applies an area (with and height) along with a pivot point
	 */
    class Areable {
    protected:
		//Area (With and Height)
        Vector2D area;

		//Pivot Point
        Vector2D areaPivot;
        
    public:

		/**
		 * Constructor
		 */
        Areable();

		/**
		* Constructor
		* @param w Width
		* @param h Height
		*/
        Areable(double w, double h);

		/**
		* Constructor
		* @param w Width
		* @param h Height
		* @param px Pivot X
		* @param py Pivot Y
		*/
        Areable(double w, double h, double px, double py);

		/**
		* Constructor
		* @param area Area
		*/
        Areable(const Vector2D &area);

		/**
		* Constructor
		* @param area Area
		* @param pivot Pivot
		*/
        Areable(const Vector2D &area, const Vector2D &pivot);
        
		/**
		* Destructor
		*/
        virtual ~Areable();
        
		/**
		* Set the width of the area
		* @param w Width
		*/
        void setWidth(double w);

		/**
		* Set the height of the area
		* @param h Height
		*/
        void setHeight(double h);

		/**
		* Set the area
		* @param w Width
		* @param h Height
		*/
        void setAreaVector(double w, double h);

		/**
		* Set the area
		* @param area Area
		*/
        void setAreaVector(const Vector2D &area);

		/**
		* Set the pivot point
		* @param px Pivot X
		* @param py Pivot Y
		*/
        void setAreaPivot(double px, double py);

		/**
		* Set the pivot point
		* @param pivot Pivot Point
		*/
        void setAreaPivot(const Vector2D &pivot);
        
		/**
		* Get the Width value
		* @returns Width
		*/
        double getWidth() const;

		/**
		* Get the Height value
		* @returns Height
		*/
        double getHeight() const;

		/**
		* Get the Area Vector
		* @returns Area Vector
		*/
        Vector2D getAreaVector() const;

		/**
		* Get the Area Value (With * Height)
		* @returns Calculated Area Value
		*/
        double getArea() const;

		/**
		* Get the Pivot Point
		* @returns Area Pivot Vector
		*/
        Vector2D getAreaPivot() const;
        
		/**
		* Get the Pivot Absolute Location
		* @param location Absolute location where Pivot is placed
		* @returns Absolute Location
		*/
        Vector2D getPivotLocation(Vector2D location) const;
    };
}

#endif /* Areable_hpp */
