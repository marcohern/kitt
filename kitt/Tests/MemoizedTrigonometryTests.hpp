//
//  MemoizedTrigonometryTests.hpp
//  kitt
//
//  Created by Marco Hernandez on 1/07/17.
//  Copyright © 2017 Marco Hernandez. All rights reserved.
//

#ifndef MemoizedTrigonometryTests_hpp
#define MemoizedTrigonometryTests_hpp

#include <stdio.h>

#include "../Testing/Assert.hpp"
#include "../Testing/Test.hpp"

namespace Tests {
    using namespace Testing;
    
    class MemoizedTrigonometryTests;
    typedef void (MemoizedTrigonometryTests::*MemoizedTrigonometryTestsMethod)();
    
    class MemoizedTrigonometryTests : public Test {
    public:
        
        void setup();
        void teardown();
        void runtest(string name, MemoizedTrigonometryTestsMethod method);
        
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


#endif /* MemoizedTrigonometryTests_hpp */
