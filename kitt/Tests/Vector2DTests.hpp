#pragma once

#include <iostream>
#include <string>
#include <exception>

#include "../Testing/Assert.hpp"
#include "../Testing/Test.hpp"

namespace Tests {

	using namespace Testing;
	using namespace std;

	class Vector2DTests;
	typedef void (Vector2DTests::*Vector2DTestMethod)();

	class Vector2DTests : public Test {
	public:

		void setup();
		void teardown();
		void execute(string name, Vector2DTestMethod method);

		void constructor_Test();
		void constructor_vector_Test();
        void toString_Test();
		void setX_Test();
		void setY_Test();
		void set_Test();
		void set_vector_Test();
		void add_Test();
        void add_vector_test();
        void sub_Test();
        void sub_vector_Test();
        void magnitude_Test();
        void multiply_Test();
        void divide_Test();
        void dot_Test();
        void angleBetween_Test();

		void run();
	};

}
