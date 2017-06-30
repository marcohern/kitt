
#include "TestSuite.hpp"

namespace Testing {

	void TestSuite::add(Test *test) {
		this->tests.push_back(test);
	}

	void TestSuite::clear() {
		this->tests.clear();
	}

	void TestSuite::run() {
		this->setup();

		auto it = this->tests.begin();
		while (it != this->tests.end()) {
			(*it)->run();
			++it;
		}

		this->teardown();
	}
}