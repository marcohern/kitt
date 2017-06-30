
#include <string>

#include "Assert.hpp"
#include "../Core/Vector2D.hpp"
#include "../Exceptions/AssertException.hpp"

namespace Testing {
	using namespace Core;
	using namespace Exceptions;

	void Assert::areEqual(Vector2D &v1, Vector2D &v2) {
		bool r = (v1.getX() == v2.getX() && v1.getY() == v2.getY());
		if (!r) throw AssertException("Vectors are not equal");
	}

	void Assert::areEqual(string s1, string s2) {
		bool r = (s1 == s2);
		if (!r) throw AssertException("strings are not equal");
	}

	void Assert::areEqual(double n1, double n2) {
		bool r = (n1 == n2);
		if (!r) throw AssertException("doubles are not equal");
	}
}