
#include <string>
#include <sstream>
#include <cmath>

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
    
    void Assert::pre() {
        calls++;
    }

	void Assert::areEqual(Vector2D v1, Vector2D v2) {
        this->pre();
		bool r = (v1.getX() == v2.getX() && v1.getY() == v2.getY());
		if (!r) throw AssertException("Vectors are not equal, " + v1.toString() + " != " + v2.toString());
	}

    void Assert::areEqual(string s1, string s2) {
        this->pre();
		bool r = (s1 == s2);
		if (!r) throw AssertException("strings are not equal, '"+ s1 + "' != '" + s2 + "'");
	}

    void Assert::areEqual(double n1, double n2) {
        this->pre();
		bool r = (n1 == n2);
        if (!r) {
            stringstream ss;
            ss<<"doubles are not equal, '"<<n1<<"' != '"<<n2<<"'";
            throw AssertException(ss.str());
        }
    }
    
    void Assert::areClose(Vector2D v1, Vector2D v2, int digits) {
        this->pre();
        double dd = (double)digits;
        double error = 1.0/pow(10.0, dd);
        double deltaX = v1.getX() - v2.getX();
        double deltaY = v1.getY() - v2.getY();
        if (abs(deltaX) > error || abs(deltaY) > error)
            throw AssertException("Vectors expected to be closer");
    }
    
    void Assert::areClose(double n1, double n2, int digits) {
        this->pre();
        double dd = (double)digits;
        double error = 1.0/pow(10.0, dd);
        double delta = n1 - n2;
        if (abs(delta) > error)
            throw AssertException("Values expected to be closer");
    }
    void Assert::isTrue(bool b) {
        this->pre();
        if (!b) {
            throw AssertException("Expected to be true");
        }
    }
    void Assert::isFalse(bool b) {
        this->pre();
        if (b) {
            throw AssertException("Expected to be false");
        }
    }
};
