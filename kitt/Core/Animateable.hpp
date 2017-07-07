#pragma once

#include "Time.hpp"

namespace Core {
	class Animateable {
	protected:
		Time *time;
	public:
		Animateable();
		Animateable(Time *time);
		virtual ~Animateable();
		virtual void update() = 0;
	};
}