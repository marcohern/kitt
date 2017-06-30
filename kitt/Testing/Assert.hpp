#pragma once

#include <string>
#include "../Core/Vector2D.hpp"

namespace Testing {

	using namespace std;
	using namespace Core;

	class Assert {
	public:
		void areEqual(Vector2D &v1, Vector2D &v2);
		void areEqual(string s1, string s2);
		void areEqual(double n1, double n2);
	};
}