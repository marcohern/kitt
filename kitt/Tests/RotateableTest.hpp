//
//  RotateableTest.hpp
//  kitt
//
//  Created by Marco Hernandez on 25/07/17.
//  Copyright © 2017 Marco Hernandez. All rights reserved.
//

#ifndef RotateableTest_hpp
#define RotateableTest_hpp

#include "../Testing/Test.hpp"
#include "../Core/Trigonometry.hpp"

namespace Tests {
    using namespace Testing;
    using namespace Core;
    
    class RotateableTest;
    typedef void (RotateableTest::*RotateableTestMethod)();

    class RotateableTest : public Test {
    private:
        Trigonometry *trigonometry;
    public:
        
        void setup();
        void teardown();
        void runtest(string name, RotateableTestMethod method);
        
        void constructor_Test();
        void constructor_R_Test();
        void constructor_XY_Test();
        void constructor_P_Test();
        void constructor_XYR_Test();
        void constructor_PR_Test();
        
        void constructor_T_Test();
        void constructor_RT_Test();
        void constructor_XYT_Test();
        void constructor_PT_Test();
        void constructor_XYRT_Test();
        void constructor_PRT_Test();
        
        void setRotationRate_Test();
        void addRotationRate_Test();
        void getRotationRate_Test();
        void updateAngle_Test();
        
        void run();
    };
}

#endif /* RotateableTest_hpp */
