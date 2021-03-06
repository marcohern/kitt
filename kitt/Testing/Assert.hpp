#pragma once

#include <string>
#include "../Core/Vector2D.hpp"

namespace Testing {

	using namespace std;
	using namespace Core;

	class Assert {
    private:
        int calls;
        
        void pre();
	public:
        void resetCalls();
        int getCalls();
		void areEqual(Vector2D v1, Vector2D v2);
		void areEqual(string s1, string s2);
        void areEqual(double n1, double n2);
        void areClose(double n1, double n2, int digits);
        void areClose(Vector2D v1, Vector2D v2, int digits);
        void isTrue(bool b);
        void isFalse(bool b);
	};
}
