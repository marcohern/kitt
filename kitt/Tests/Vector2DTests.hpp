#pragma once

#include <iostream>
#include <string>
#include <exception>

#include "../Core/Trigonometry.hpp"
#include "../Testing/Assert.hpp"
#include "../Testing/Test.hpp"

namespace Tests {

    using namespace Core;
	using namespace Testing;
	using namespace std;

	class Vector2DTests;
	typedef void (Vector2DTests::*Vector2DTestMethod)();

	class Vector2DTests : public Test {
    private:
        Trigonometry *trigonometry;
	public:

		void setup();
		void teardown();
        void runtest(string name, Vector2DTestMethod method);

        void constructor_Test();
        void constructor_NoTrigo_Test();
		void constructor_vector_Test();
        void toString_Test();
		void setX_Test();
		void setY_Test();
		void set_Test();
		void set_vector_Test();
		void add_Test();
        void add_vector_Test();
        void sub_Test();
        void sub_vector_Test();
        void magnitude_Test();
        void multiply_Test();
        void divide_Test();
        void divide_ByZero_Test();
        void dot_Test();
        void angleBetween_Test();
        void rotate_Test();
        void rotate_TigoNull_Test();
        
        void op_positive_Test();
        void op_negative_Test();
        void op_add_Test();
        void op_sub_Test();
        void op_multiply_s_Test();
        void op_s_multiply_Test();
        void op_dot_product_Test();
        void op_div_Test();
        void op_div_ByZero_Test();

		void run();
	};

}
