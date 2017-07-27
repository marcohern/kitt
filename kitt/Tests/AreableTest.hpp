//
//  AreableTest.hpp
//  kitt
//
//  Created by Marco Hernandez on 26/07/17.
//  Copyright © 2017 Marco Hernandez. All rights reserved.
//

#ifndef AreableTest_hpp
#define AreableTest_hpp


#include "../Testing/Test.hpp"
#include "../Core/Trigonometry.hpp"

namespace Tests {
    using namespace Testing;
    using namespace Core;
    
    class AreableTest;
    typedef void (AreableTest::*AreableTestMethod)();
    
    class AreableTest : public Test {
    private:
        Trigonometry *trigonometry;
    public:
        
        void setup();
        void teardown();
        void runtest(string name, AreableTestMethod method);
        
        void constructor_Test();
        void constructor_WH_Test();
        void constructor_WHXY_Test();
        void constructor_A_Test();
        void constructor_AP_Test();
        
        void constructor_T_Test();
        void constructor_WHT_Test();
        void constructor_WHXYT_Test();
        void constructor_AT_Test();
        void constructor_APT_Test();
        
        void setWidth_Test();
        void setHeight_Test();
        void setAreaVector_WH_Test();
        void setAreaVector_A_Test();
        void setAreaPivot_XY_Test();
        void setAreaPivot_P_Test();
        
        void getWidth_Test();
        void getHeight_Test();
        void getAreaVector_Test();
        void getArea_Test();
        void getAreaPivot_Test();

        
        void run();
    };
}

#endif /* AreableTest_hpp */
