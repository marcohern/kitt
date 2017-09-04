#pragma once

#include "../Testing/Test.hpp"

namespace Tests {
	using namespace Testing;

	class QuadmemTrigonometryTests;
	typedef void (QuadmemTrigonometryTests::*QuadmemTrigonometryTestsMethod)();

	class QuadmemTrigonometryTests : public Test {
		void setup();
		void teardown();
		void runtest(string name, QuadmemTrigonometryTestsMethod method);

		void run();
	};
}