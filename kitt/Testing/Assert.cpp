
#include <string>
#include <sstream>

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
		if (!r) throw AssertException("Vectors are not equal, " + v1.toString() + " != " + v2.toString());
	}

    void Assert::areEqual(string s1, string s2) {
        calls++;
		bool r = (s1 == s2);
		if (!r) throw AssertException("strings are not equal, '"+ s1 + "' != '" + s2 + "'");
	}

    void Assert::areEqual(double n1, double n2) {
        calls++;
		bool r = (n1 == n2);
        if (!r) {
            stringstream ss;
            ss<<"doubles are not equal, '"<<n1<<"' != '"<<n2<<"'";
            throw AssertException(ss.str());
        }
	}
    
    void Assert::isTrue(bool b) {
        calls++;
        if (!b) {
            throw AssertException("Expected to be true");
        }
    }
    void Assert::isFalse(bool b) {
        calls++;
        if (b) {
            throw AssertException("Expected to be false");
        }
    }
};
