
#include "Animation.hpp"

namespace Graphics
{
	Animation::Animation(int qty, double duration)
		: qty(qty), duration(duration), current(NULL), index(0), acc(0.0)
	{
		dpf = duration / qty;
		sprites = new Sprite*[qty];
	}

	Animation::~Animation() {
		delete sprites;
	}

	void Animation::setSprite(int i, Sprite *sprite) {
		sprites[i] = sprite;
		current = sprites[i];
	}

	void Animation::setCurrentSprite(int i) {
		index = i;
		current = sprites[i];
	}

	Sprite *Animation::getSprite(int i) {
		return sprites[i];
	}

	Sprite *Animation::getCurrentSprite() {
		return current;
	}

	void Animation::nextSprite() {
		index++;
		if (index >= qty) {
			index = 0;
		}
		current = sprites[index];
	}

	void Animation::reset() {
		index = 0;
		current = sprites[index];
	}

	void Animation::update(double interval) {
		acc += interval;
		if (acc > dpf) {
			while (acc > dpf) {
				acc -= dpf;
				nextSprite();
			}
		}
	}
}