
#include "SpriteSheet.hpp"
#include "../json.hpp"

namespace Graphics {
	using namespace std;
    using namespace nlohmann;

	SpriteSheet::SpriteSheet(Texture *texture)
		: texture(texture), sprites(), animations(), count(0) {
	}

	SpriteSheet::~SpriteSheet() {

	}

	Texture *SpriteSheet::getTexture() const {
		return texture;
	}

	void SpriteSheet::addSprite(string id, int x, int y, int w, int h, int px, int py) {
		sprites[id] = new Sprite(texture, x, y, w, h, px, py);
	}

	void SpriteSheet::addAnimation(string id, Animation *animation) {
		animations[id] = animation;
	}

	Sprite *SpriteSheet::getSprite(string id) {
		return sprites[id];
	}

	Animation *SpriteSheet::getAnimation(string id) {
		return animations[id];
	}
}
