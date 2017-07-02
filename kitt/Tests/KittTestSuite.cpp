#include "./KittTestSuite.hpp"
#include "./Vector2DTests.hpp"
#include "./RealtimeTrigonometryTests.hpp"
#include "./MemoizedTrigonometryTests.hpp"
#include "./MatrixTests.hpp"

namespace Tests {
    
    void KittTestSuite::setup()
    {
        this->add(new Vector2DTests());
        this->add(new RealtimeTrigonometryTests());
        this->add(new MemoizedTrigonometryTests());
        this->add(new MatrixTests());
	}

    void KittTestSuite::teardown() {
        this->clear();
	}
}
