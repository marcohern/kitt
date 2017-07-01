
#include "../Exceptions/AssertException.hpp"
#include "Test.hpp"

namespace Testing {

    using namespace Exceptions;
    
    Test::Test() {
        this->name = "Test";
    }
    
    string Test::getName() {
        return this->name;
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
