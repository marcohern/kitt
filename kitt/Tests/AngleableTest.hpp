//
//  AngleableTest.hpp
//  kitt
//
//  Created by Marco Hernandez on 23/07/17.
//  Copyright © 2017 Marco Hernandez. All rights reserved.
//

#ifndef AngleableTest_hpp
#define AngleableTest_hpp


#include "../Core/Trigonometry.hpp"
#include "../Testing/Test.hpp"

namespace Tests {
    using namespace Testing;
    using namespace Core;
    
    class AngleableTest;
    typedef void (AngleableTest::*AngleableTestMethod)();
    
    class AngleableTest : public Test {
    private:
        Trigonometry *trigonometry;
    public:
        
        void setup();
        void teardown();
        void runtest(string name, AngleableTestMethod method);
        
        void constructor_Test();
        void constructor_R_Test();
        void constructor_XY_Test();
        void constructor_P_Test();
        void constructor_XYR_Test();
        void constructor_PR_Test();
        
        void setAngle_Test();
        void setRotatePivot_XY_Test();
        void setRotatePivot_P_Test();
        
        void getAngle_Test();
        void getRotatePivot_Test();
        
        void addAngle_Test();
        void getAngleDisplacement_Test();
        void getRotatePivotDisplacement_XY_Test();
        void getRotatePivotDisplacement_P_Test();
        
        void run();
    };
}


#endif /* AngleableTest_hpp */
