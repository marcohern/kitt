
#include "SpriteSheet.hpp"

namespace Graphics {
	using namespace std;

	SpriteSheet::SpriteSheet(Texture *texture)
		: texture(texture), sprites(), count(0) {
	}

	SpriteSheet::~SpriteSheet() {

	}

	Texture *SpriteSheet::getTexture() const {
		return texture;
	}

	void SpriteSheet::addSprite(string id, int x, int y, int w, int h, int px, int py) {
		sprites[id] = new Sprite(texture, x, y, w, h, px, py);
	}

	Sprite *SpriteSheet::getSprite(string id) {
		return sprites[id];
	}
}