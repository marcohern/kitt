#include "./KittTestSuite.hpp"
#include "./Vector2DTests.hpp"
#include "./RealtimeTrigonometryTest.hpp"

namespace Tests {

    void KittTestSuite::setup()
    {
        this->add(new Vector2DTests());
        this->add(new RealtimeTrigonometryTest());
	}

    void KittTestSuite::teardown() {
        this->clear();
	}
}
