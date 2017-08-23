#pragma once

#include "Texture.hpp"
#include "../Collisions/CollisionShape.hpp"
#include <vector>

namespace Graphics {
	using namespace Collisions;

	class Sprite {
	private:
		Texture *texture;
		vector<CollisionShape *> colliders;
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

		void addCollider(double x, double y, double r);
		void addCollider(double x, double y, double w, double h);
		vector<CollisionShape *> getColliders() const;
	};
}