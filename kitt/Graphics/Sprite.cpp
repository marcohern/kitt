
#include "Sprite.hpp"

namespace Graphics {
	Sprite::Sprite(Texture *texture, int x, int y, int w, int h, int px, int py) 
	: texture(texture), x(x), y(y), w(w), h(h), px(px), py(py) {
	}

	int Sprite::getW() const { return w; }
	int Sprite::getH() const { return h; }
	int Sprite::getX() const { return x; }
	int Sprite::getY() const { return y; }
	int Sprite::getRX() const { return x - px; }
	int Sprite::getRY() const { return y - py; }
	int Sprite::getPX() const { return px; }
	int Sprite::getPY() const { return py; }


	Texture *Sprite::getTexture() const { return texture; }
}