#pragma once

#include "Texture.hpp"

namespace Graphics {
	class Sprite {
	private:
		Texture *texture;
		int x, y, w, h, px, py;

	public:
		Sprite(Texture *texture, int x, int y, int w, int h, int px, int py);

		int getW() const;
		int getH() const;
		int getX() const;
		int getY() const;
		int getRX() const;
		int getRY() const;
		int getPX() const;
		int getPY() const;

		Texture *getTexture() const;
	};
}