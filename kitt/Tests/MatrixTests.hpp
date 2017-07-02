//
//  MatrixTests.hpp
//  kitt
//
//  Created by Marco Hernandez on 2/07/17.
//  Copyright © 2017 Marco Hernandez. All rights reserved.
//

#ifndef MatrixTests_hpp
#define MatrixTests_hpp

#include <stdio.h>
#include "../Testing/Assert.hpp"
#include "../Testing/Test.hpp"

namespace Tests {
    using namespace Testing;
    
    class MatrixTests;
    typedef void (MatrixTests::*MatrixTestsMethod)();
    
    class MatrixTests : public Test {
    public:
        
        void setup();
        void teardown();
        void runtest(string name, MatrixTestsMethod method);
        
        void constructor_Test();
        void constructor_zero_Test();
        void constructor_value_Test();
        void constructor_invalid_size_Test();
        void get_outofrange_Test();
        void add_Test();
        void add_mismatch_Test();
        void toString_Test();
        void op_access_Test();
        
        void run();
    };
}
#endif /* MatrixTests_hpp */
