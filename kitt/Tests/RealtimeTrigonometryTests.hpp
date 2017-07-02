//
//  RealtimeTrigonometryTest.hpp
//  kitt
//
//  Created by Marco Hernandez on 1/07/17.
//  Copyright © 2017 Marco Hernandez. All rights reserved.
//

#ifndef RealtimeTrigonometryTest_hpp
#define RealtimeTrigonometryTest_hpp

#include <stdio.h>

#include "../Testing/Assert.hpp"
#include "../Testing/Test.hpp"

namespace Tests {
    using namespace Testing;
    
    class RealtimeTrigonometryTests;
    typedef void (RealtimeTrigonometryTests::*RealtimeTrigonometryTestsMethod)();
    
    class RealtimeTrigonometryTests : public Test {
    public:
        
        void setup();
        void teardown();
        void runtest(string name, RealtimeTrigonometryTestsMethod method);
        
        void cos_00_Test();
        void cos_05_Test();
        void cos_10_Test();
        void cos_20_Test();
        void cos_pi_Test();
        
        void sin_00_Test();
        void sin_05_Test();
        void sin_10_Test();
        void sin_20_Test();
        void sin_pi_Test();
        
        void cos_random_Test();
        
        void run();
    };
}

#endif /* RealtimeTrigonometryTest_hpp */
