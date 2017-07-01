
#include <string>

#include "Assert.hpp"
#include "../Core/Vector2D.hpp"
#include "../Exceptions/AssertException.hpp"

namespace Testing {
	using namespace Core;
	using namespace Exceptions;
    
    void Assert::resetCalls() {
        this->calls = 0;
    }
    
    int Assert::getCalls() {
        return this->calls;
    }

	void Assert::areEqual(Vector2D &v1, Vector2D &v2) {
        calls++;
		bool r = (v1.getX() == v2.getX() && v1.getY() == v2.getY());
		if (!r) throw AssertException("Vectors are not equal");
	}

    void Assert::areEqual(string s1, string s2) {
        calls++;
		bool r = (s1 == s2);
		if (!r) throw AssertException("strings are not equal");
	}

    void Assert::areEqual(double n1, double n2) {
        calls++;
		bool r = (n1 == n2);
		if (!r) throw AssertException("doubles are not equal");
	}
}
