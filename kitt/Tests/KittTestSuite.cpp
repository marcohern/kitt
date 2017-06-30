#include "./KittTestSuite.hpp"

namespace Tests {
	void KittTestSuite::setup() {
		this->add(new Vector2DTests());
	}

	void KittTestSuite::teardown() {
		this->clear();
	}
}