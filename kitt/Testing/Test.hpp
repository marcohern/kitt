#pragma once

#include "Assert.hpp"

namespace Testing {

	class Test {
	protected:
		Assert assert;

	public:

		virtual void setup() = 0;
		virtual void teardown() = 0;
		virtual void run() = 0;
	};

}