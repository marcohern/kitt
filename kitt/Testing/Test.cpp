
#include "../Exceptions/AssertException.hpp"
#include "Test.hpp"

namespace Testing {

    using namespace Exceptions;
    
    Test::Test() {
        this->name = "Test";
    }
    
	void Test::setup() {
        this->assert.resetCalls();
	}

	void Test::teardown() {
        if (this->assert.getCalls() == 0) {
            throw AssertException("No assertions made");
        }
	}
}
