#pragma once

#include "Texture.hpp"
#include "Sprite.hpp"
#include <map>

namespace Graphics {
	using namespace std;
	class SpriteSheet {
	private:
		Texture *texture;
		int count;
		map<string, Sprite*> sprites;

	public:
		SpriteSheet(Texture *texture);
		virtual ~SpriteSheet();

		Texture *getTexture() const;
		
		void addSprite(string id, int x, int y, int w, int h, int px, int py);
		Sprite *getSprite(string id);
	};
}