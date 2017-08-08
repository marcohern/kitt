#pragma once

#include "Texture.hpp"
#include "Sprite.hpp"
#include "Animation.hpp"
#include <map>

namespace Graphics {
	using namespace std;
	class SpriteSheet {
	private:
		Texture *texture;
		int count;
		map<string, Sprite*> sprites;
		map<string, Animation*> animations;

	public:
		SpriteSheet(Texture *texture);
		virtual ~SpriteSheet();

		Texture *getTexture() const;
		
		void addSprite(string id, int x, int y, int w, int h, int px, int py);
		void addAnimation(string id, Animation *animation);
		Sprite *getSprite(string id);
		Animation *getAnimation(string id);
	};
}