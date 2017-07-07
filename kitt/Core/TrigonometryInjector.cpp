
#include "TrigonometryInjector.hpp"
#include "TrigonometryFactory.hpp"

namespace Core {

	Trigonometry *TrigonometryInjector::trigonometry = NULL;

	TrigonometryInjector::TrigonometryInjector() {
		
	}

	void TrigonometryInjector::init(int type) {
		trigonometry = TrigonometryFactory::create(type);
	}

	Trigonometry *TrigonometryInjector::inject() {
		return trigonometry;
	}
}