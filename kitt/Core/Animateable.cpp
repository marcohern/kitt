#include "Animateable.hpp"
#include "TimeInjector.hpp"
#include "..\Exceptions\NullReferenceException.hpp"

namespace Core {

	Animateable::Animateable() : time(TimeInjector::inject()) {
		if (time == NULL) throw Exceptions::NullReferenceException("Time cannot be null in Animateable");
	}

	Animateable::Animateable(Time *time) : time(time) {
		if (time == NULL) throw Exceptions::NullReferenceException("Time cannot be null in Animateable");
	}

	Animateable::~Animateable() {

	}
}