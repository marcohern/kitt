#pragma once

#include "Texture.hpp"

namespace Graphics {
	class Sprite {
	private:
		Texture *texture;
		int x, y, w, h;

	public:
		Sprite(Texture *texture, int x, int y, int w, int h);

		int getW() const;
		int getH() const;
		int getX() const;
		int getY() const;

		Texture *getTexture() const;
	};
}