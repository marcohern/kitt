
#include "Sprite.hpp"

namespace Graphics {
	Sprite::Sprite(Texture *texture, int x, int y, int w, int h) 
	: texture(texture), x(x), y(y), w(w), h(h) {
	}

	int Sprite::getW() const { return w; }
	int Sprite::getH() const { return h; }
	int Sprite::getX() const { return x; }
	int Sprite::getY() const { return y; }

	Texture *Sprite::getTexture() const { return texture; }
}