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
#include "Color.hpp"
#include "Sprite.hpp"
#include "Animation.hpp"

namespace Graphics {
	using namespace Core;

	typedef enum {
		RENDER_FLIP_NONE       = 0x00,
		RENDER_FLIP_HORIZONTAL = 0x01,
		RENDER_FLIP_VERTICAL   = 0x02
	} RendererFlip;

	class Renderer {
	public:
        virtual ~Renderer();

		virtual void clear() = 0;
		virtual void present() = 0;
		virtual void texture(const Vector2D &position, Texture *texture) = 0;
		virtual void vector2d(const Vector2D &position, const Color &color, const Vector2D &v) = 0;
		virtual void animation(Animation *animation
			, const Vector2D &position
			, const Vector2D &area = Vector2D::Zero
			, const Vector2D &offset = Vector2D::Zero
			, const Vector2D &pivot = Vector2D::Zero
			, const Color &tint = Color::White
			, int blendAdd = 0, double angle = 0
			, RendererFlip flip = RENDER_FLIP_NONE) = 0;
		virtual void sprite(const Vector2D &location, Sprite *sprite) = 0;
	};
}

#endif /* Renderer_hpp */
