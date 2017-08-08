#pragma once

#include "Sprite.hpp"

namespace Graphics
{
	class Animation {
	private:
		Sprite **sprites;
		Sprite *current;

		int qty;
		double duration;
		double dpf;
		double acc;
		int index;

	public:
		Animation(int qty, double duration);

		~Animation();

		void setSprite(int i, Sprite *sprite);
		void setCurrentSprite(int i);
		void nextSprite();
		Sprite *getSprite(int i);
		Sprite *getCurrentSprite();
		void reset();
		void update(double interval);
	};
}