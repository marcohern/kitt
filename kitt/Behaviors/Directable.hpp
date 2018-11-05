//
//  Directable.hpp
//  kitt
//
//  Created by Marco Hernandez on 18/07/17.
//  Copyright © 2017 Marco Hernandez. All rights reserved.
//

#ifndef Directable_hpp
#define Directable_hpp

#include "./Placeable.hpp"
#include "../Core/Vector2D.hpp"
#include "../Core/Trigonometry.hpp"

namespace Behaviors
{

	/**
	 * Allows objects to have a direction
	 */
    class Directable : public Placeable {
    private:
        Vector2D _direction;
        
    protected:
        Vector2D direction;
        
    public:
		/**
		 * Constructor
		 */
        Directable();

		/**
		* Constructor
		* @param x X Direction
		* @param y Y Direction
		*/
        Directable(double x, double y);

		/**
		* Constructor
		* @param v Direction Vector
		*/
        Directable(const Vector2D &v);
        
		/**
		* Destructor
		*/
        virtual ~Directable();
        
		/**
		* Get Direction
		* @returns Direction Vector
		*/
        Vector2D getDirection() const;

		/**
		* Set Direction
		* @param dx X Direction
		* @param dy Y Direction
		*/
        void setDirection(double dx, double dy);
        
		/**
		* Set Direction
		* @param v Diretion Vector
		*/
		void setDirection(const Vector2D &v);

		/**
		* Add to current Direction
		* @param v Diretion Vector to Add
		*/
        void addDirection(const Vector2D &v);
        
		/**
		* Update Location using direction
		* @param interval time interval
		*/
        void updateLocation(double interval);
    };
}
#endif /* Directable_hpp */
