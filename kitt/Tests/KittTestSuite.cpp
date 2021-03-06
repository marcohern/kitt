#include "./KittTestSuite.hpp"
#include "./Vector2DTests.hpp"
#include "./RealtimeTrigonometryTests.hpp"
#include "./MemoizedTrigonometryTests.hpp"
#include "./MatrixTests.hpp"
#include "./PlaceableTest.hpp"
#include "./DirectableTest.hpp"
#include "./ScalableTest.hpp"
#include "./GrowableTest.hpp"
#include "./AngleableTest.hpp"
#include "./RotateableTest.hpp"
#include "./AreableTest.hpp"
#include "./TransformableTest.hpp"
#include "./CollisionRectTest.hpp"

#include "./SdlFileReaderTest.hpp"

namespace Tests {
    
    void KittTestSuite::setup()
    {
        this->add(new Vector2DTests());
        this->add(new RealtimeTrigonometryTests());
        this->add(new MemoizedTrigonometryTests());
        this->add(new MatrixTests());
        this->add(new PlaceableTest());
        this->add(new DirectableTest());
        this->add(new ScalableTest());
        this->add(new GrowableTest());
        this->add(new AngleableTest());
        this->add(new RotateableTest());
        this->add(new AreableTest());
        this->add(new TransformableTest());
		this->add(new CollisionRectTest());

		this->add(new SdlFileReaderTest());
	}

    void KittTestSuite::teardown() {
        this->clear();
	}
}
