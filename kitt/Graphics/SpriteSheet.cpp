
#include "SpriteSheet.hpp"
#include "../Collisions/CollisionRect.hpp"
#include "../Collisions/CollisionCircle.hpp"
#include "../json.hpp"

namespace Graphics {
	using namespace std;
    using namespace nlohmann;

	SpriteSheet::SpriteSheet(Texture *texture)
		: texture(texture), sprites(), animations(), collisions(), count(0) {
	}

	SpriteSheet::~SpriteSheet() {

	}

	Texture *SpriteSheet::getTexture() const {
		return texture;
	}

	Sprite *SpriteSheet::addSprite(string id, int x, int y, int w, int h, int px, int py) {
		Sprite *sprite = new Sprite(texture, x, y, w, h, px, py);
		sprites[id] = sprite;
		return sprite;
	}

	void SpriteSheet::addAnimation(string id, Animation *animation) {
		animations[id] = animation;
	}

	void SpriteSheet::addCollider(string id, double x, double y, double r) {
		CollisionCircle *circle = new CollisionCircle(Vector2D(x, y), r);
		collisions[id].push_back(circle);
	}

	void SpriteSheet::addCollider(string id, double x, double y, double w, double h) {
		CollisionRect *rect = new CollisionRect(Vector2D(x, y), Vector2D(w, h));
		collisions[id].push_back(rect);
	}

	Animation *SpriteSheet::getAnimation(string id) {
		return animations[id];
	}

	vector<CollisionShape *> SpriteSheet::getColliders(string id) {
		return collisions[id];
	}

	Sprite *SpriteSheet::getSprite(string id) {
		return sprites[id];
	}
}
