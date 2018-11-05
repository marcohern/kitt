//
//  Placeable.hpp
//  kitt
//
//  Created by Marco Hernandez on 11/07/17.
//  Copyright © 2017 Marco Hernandez. All rights reserved.
//

#ifndef Placeable_hpp
#define Placeable_hpp

#include "../Core/Trigonometry.hpp"
#include "../Core/Vector2D.hpp"

namespace Behaviors {
    using namespace Core;
    
	/**
	 * Allows objects to be placed (have a location)
	 */
    class Placeable {
    protected:
        
		//Location
        Vector2D location;
    public:

		/**
		 * Constructor
		 */
        Placeable();

		/**
		 * Constructor
		 * @param x X coordinate
		 * @param y Y coordinate
		 */
        Placeable(double x, double y);

		/**
		 * Constructor
		 * @param v Vector location
		 */
        Placeable(const Vector2D &v);
        
		/**
		 * Destructor
		 */
        virtual ~Placeable();
        
		/**
		 * Get Location Vector
		 * @returns Location Vector
		 */
        Vector2D getLocation() const;

		/**
		 * Get Displacement Vector
		 * @param dx X Displacement
		 * @param dy Y Displacement
		 * @returns Displacement Vector
		 */
        Vector2D getDisplacement(double dx, double dy) const;

		/**
		 * Get Displacement Vector
		 * @param displacement Displacement Vector
		 * @returns Displacement Vector
		 */
        Vector2D getDisplacement(const Vector2D &displacement) const;
        
		/**
		 * Set Location 
		 * @param x X Displacement
		 * @param y Y Displacement
		 */
        void setLocation(double x, double y);

		/**
		 * Set Location 
		 * @param v Vector
		 */
        void setLocation(const Vector2D &v);
        
		/**
		 * Add Displacement to Location
		 * @param dx X Displacement
		 * @param dy Y Displacement
		 */
        void addLocation(double dx, double dy);

		/**
		 * Add Displacement to Location
		 * @param v Displacement
		 */
        void addLocation(const Vector2D &v);
    };
}

#endif /* Placeable_hpp */
