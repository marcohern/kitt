#pragma once

#include "Sprite.hpp"

namespace Graphics
{
	class Animation {
	private:
		Sprite **sprites;
		int qty;

	public:
		Animation(double interval, int qty);

		~Animation();

		void addSprite(Sprite *sprite);
		
	};
}