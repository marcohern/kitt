#pragma once

#include "Time.hpp"

namespace Core {
	class Animateable {
        
	public:
		Animateable();
		virtual ~Animateable();
		virtual void update(double interval) = 0;
	};
}
