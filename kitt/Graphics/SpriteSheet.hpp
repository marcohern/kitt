#pragma once

#include "Texture.hpp"
#include "Sprite.hpp"
#include "Animation.hpp"
#include "../Collisions/CollisionShape.hpp"
#include <map>
#include <vector>
#include "../json.hpp"

namespace Graphics {
	using json = nlohmann::json;
	using namespace std;
	using namespace Collisions;
	class SpriteSheet {
	private:
		Texture *texture;
		int count;
		map<string, Sprite *> sprites;
		map<string, Animation *> animations;
		vector<CollisionShape *> collisions;

	public:
		SpriteSheet(Texture *texture);
		virtual ~SpriteSheet();

		Texture *getTexture() const;
		
		Sprite *addSprite(string id, int x, int y, int w, int h, int px, int py, bool useGlobalColliders);
		void addAnimation(string id, Animation *animation);
		void addCollider(double x, double y, double r);
		void addCollider(double x, double y, double w, double h);

		Sprite *getSprite(string id);
		Animation *getAnimation(string id);
		vector<CollisionShape *> getColliders() const;
	};
}