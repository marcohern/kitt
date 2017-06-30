#pragma once

#include "Assert.hpp"

namespace Testing {

	class Test {
	protected:
		Assert assert;

	public:

		virtual void setup();
		virtual void teardown();
		virtual void run() = 0;
	};

}