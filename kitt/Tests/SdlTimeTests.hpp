//
//  SdlTimeTests.hpp
//  kitt
//
//  Created by Marco Hernandez on 2/07/17.
//  Copyright © 2017 Marco Hernandez. All rights reserved.
//

#ifndef SdlTimeTests_hpp
#define SdlTimeTests_hpp

#include <stdio.h>

#include "../Testing/Assert.hpp"
#include "../Testing/Test.hpp"

namespace Tests {
    using namespace Testing;
    
    class SdlTimeTests;
    typedef void (SdlTimeTests::*SdlTimeTestsMethod)();
    
    class SdlTimeTests : public Test {
    public:
        
        void setup();
        void teardown();
        void runtest(string name, SdlTimeTestsMethod method);
        
        void run();
    };
}


#endif /* SdlTimeTests_hpp */
