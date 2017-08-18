#pragma once

#include "../Core/Trigonometry.hpp"
#include "../Testing/Test.hpp"

namespace Tests {
	using namespace Testing;
	using namespace Core;

	class CollisionRectTest;
	typedef void (CollisionRectTest::*CollisionRectTestMethod)();

	class CollisionRectTest : public Test {
	private:
		Trigonometry *trigonometry;
	public:

		void setup();
		void teardown();
		void runtest(string name, CollisionRectTestMethod method);

		void constructor_Test();
		void constructor_S_Test();
		void constructor_LS_Test();

		void constructor_T_Test();
		void constructor_ST_Test();
		void constructor_LST_Test();

		void getLocation_Test();
		void getSize_Test();

		void setLocation_Test();
		void addLocation_Test();

		void intersectsSensor_Test();
		void getCenter_Test();
		void getClosestPoint_Test();
		void collidesWith_Test();

		void run();
	};
}


