//
//  Renderer.hpp
//  kitt
//
//  Created by Marco Hernandez on 3/07/17.
//  Copyright © 2017 Marco Hernandez. All rights reserved.
//

#ifndef Renderer_hpp
#define Renderer_hpp

#include <stdio.h>
#include "../Core/Vector2D.hpp"
#include "./Texture.hpp"

namespace Graphics {
	using namespace Core;

	class Renderer {
	public:

		virtual void clear() = 0;
		virtual void present() = 0;
		virtual void texture(int x, int y, Texture *texture) = 0;
		virtual void vector2d(int x, int y, int color, const Vector2D &v) = 0;
	};
}

#endif /* Renderer_hpp */
