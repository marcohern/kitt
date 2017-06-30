#pragma once

#include "../Testing/TestSuite.hpp"
#include "./Vector2DTest.hpp"

namespace Tests {
	using namespace Testing;

	class KittTestSuite : public TestSuite {
	protected:
		void setup();
		void teardown();
	};
}