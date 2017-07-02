#include "./KittTestSuite.hpp"
#include "./Vector2DTests.hpp"
#include "./RealtimeTrigonometryTests.hpp"
#include "./MemoizedTrigonometryTests.hpp"

namespace Tests {
    
    void KittTestSuite::setup()
    {
        this->add(new Vector2DTests());
        this->add(new RealtimeTrigonometryTests());
        this->add(new MemoizedTrigonometryTests());
	}

    void KittTestSuite::teardown() {
        this->clear();
	}
}
