#include "./KittTestSuite.hpp"
#include "./Vector2DTests.hpp"
#include "./RealtimeTrigonometryTests.hpp"
#include "./MemoizedTrigonometryTests.hpp"
#include "./MatrixTests.hpp"
#include "./PlaceableTest.hpp"

namespace Tests {
    
    void KittTestSuite::setup()
    {
        this->add(new Vector2DTests());
        this->add(new RealtimeTrigonometryTests());
        this->add(new MemoizedTrigonometryTests());
        this->add(new MatrixTests());
        this->add(new PlaceableTest());
	}

    void KittTestSuite::teardown() {
        this->clear();
	}
}
