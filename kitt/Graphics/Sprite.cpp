
#include "Sprite.hpp"
#include "../Collisions/CollisionRect.hpp"
#include "../Collisions/CollisionCircle.hpp"

namespace Graphics {
	Sprite::Sprite(Texture *texture, int x, int y, int w, int h, int px, int py) 
	: texture(texture), x(x), y(y), w(w), h(h), px(px), py(py), colliders() {
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

	void Sprite::addCollider(double x, double y, double r) {
		colliders.push_back(new CollisionCircle(Vector2D(x, y), r));
	}

	void Sprite::addCollider(double x, double y, double w, double h) {
		colliders.push_back(new CollisionRect(Vector2D(x, y), Vector2D(w, h)));
	}

	void Sprite::addCollider(CollisionShape *shape) {
		colliders.push_back(shape);
	}

	void Sprite::setColliders(const vector<CollisionShape *> &colliders) {
		this->colliders = colliders;
	}

	vector<CollisionShape *> Sprite::getColliders() const {
		return colliders;
	}
}