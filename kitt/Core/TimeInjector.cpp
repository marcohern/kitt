
#include "TimeInjector.hpp"
#include "TimeFactory.hpp"

namespace Core {

	Time *TimeInjector::time = NULL;

	void TimeInjector::init(int type) {
		if (time == NULL) {
			time = TimeFactory::create();
		}
	}

	Time *TimeInjector::inject() {
		return time;
	}
}