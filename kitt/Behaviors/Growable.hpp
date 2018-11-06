//
//  Growable.hpp
//  kitt
//
//  Created by Marco Hernandez on 23/07/17.
//  Copyright © 2017 Marco Hernandez. All rights reserved.
//

#ifndef Growable_hpp
#define Growable_hpp

#include "Scalable.hpp"
#include "../Core/Vector2D.hpp"
#include "../Core/Trigonometry.hpp"

namespace Behaviors{

	/**
	* Allows ability to grow or shrink (chnage scale)
	*/
    class Growable : public Scalable {
    protected:
		//Rage of growth in both X and Y
        Vector2D growthRate;
        
    public:
		/**
		* Constructor
		*/
        Growable();
        
		/**
		* Destructor
		*/
        virtual ~Growable();
        
		/**
		* Set Growth Rate
		* @param g Scalar Growth rate
		*/
        void setGrowthRate(double g);

		/**
		* Set Growth Rate
		* @param g Vector Growth rate
		*/
        void setGrowthRate(const Vector2D &g);
        
		/**
		* Get Growth Rate
		* @returns Vector Growth Rate
		*/
        Vector2D getGrowthRate() const;

		/**
		* Get Growth Rate X
		* @returns Growth Rate X
		*/
        double getGrowthRateX() const;

		/**
		* Get Growth Rate Y
		* @returns Growth Rate Y
		*/
        double getGrowthRateY() const;
        
		/**
		* Add to Growth Rate
		* @param ds Growth Displacement
		*/
        void addGrowth(double ds);

		/**
		* Add to Growth Rate
		* @param d Growth Displacement
		*/
        void addGrowth(const Vector2D &d);

		/**
		* Multiply Growth
		* @param ms Growth Factor 
		*/
        void multiplyGrowth(double ms);
        
		/**
		* Update Scale
		* @param interval Time Interval
		*/
        void updateScale(double interval);
    };
}

#endif /* Growable_hpp */
