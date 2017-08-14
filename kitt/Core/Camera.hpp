//
//  Camera.hpp
//  kitt
//
//  Created by Marco Hernandez on 8/07/17.
//  Copyright © 2017 Marco Hernandez. All rights reserved.
//

#ifndef Camera_hpp
#define Camera_hpp

#include "Trigonometry.hpp"
#include "Vector2D.hpp"
#include "../Behaviors/Placeable.hpp"

namespace Core {
	using namespace Behaviors;

    class Camera {
	private:
		Vector2D location;
		Vector2D offset;
		Placeable *focus;

	public:

		Camera();
		Camera(double x, double y);
		Camera(const Vector2D &location);
		Camera(double x, double y, double ox, double oy);
		Camera(const Vector2D &location, const Vector2D &offset);

		Camera(Trigonometry *trigo);
		Camera(double x, double y, Trigonometry *trigo);
		Camera(const Vector2D &location, Trigonometry *trigo);
		Camera(double x, double y, double ox, double oy, Trigonometry *trigo);
		Camera(const Vector2D &location, const Vector2D &offset, Trigonometry *trigo);

		~Camera();

		void setFocusObject(Placeable *placeable);
		void clearFocusObject();

		void setLocation(double x, double y);
		void setLocation(const Vector2D &location);
		void setOffset(double x, double y);
		void setOffset(const Vector2D &location);
		Vector2D getLocation() const;
		Vector2D getOffset() const;
    };
}
#endif /* Camera_hpp */
