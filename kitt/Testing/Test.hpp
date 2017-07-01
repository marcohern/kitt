#pragma once

#include <string>
#include "Assert.hpp"

namespace Testing {

    using namespace std;
    
	class Test {
	protected:
        string name;
		Assert assert;

	public:
        Test();
        string getName();
        
		virtual void setup();
		virtual void teardown();
		virtual void run() = 0;
	};

}
