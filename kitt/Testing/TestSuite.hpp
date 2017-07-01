#pragma once

#include <list>
#include "Test.hpp"

namespace Testing {
	using namespace std;

	class TestSuite {
	private:
		list<Test *> tests;
        int ran = 0;

	protected:
		void add(Test *test);
		void clear();
		virtual void setup() = 0;
		virtual void teardown() = 0;

	public:
		void run();


	};
}
