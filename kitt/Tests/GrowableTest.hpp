//
//  GrowableTest.hpp
//  kitt
//
//  Created by Marco Hernandez on 23/07/17.
//  Copyright © 2017 Marco Hernandez. All rights reserved.
//

#ifndef GrowableTest_hpp
#define GrowableTest_hpp

#include "../Core/Trigonometry.hpp"
#include "../Testing/Test.hpp"

namespace Tests {
    using namespace Testing;
    using namespace Core;
    
    class GrowableTest;
    typedef void (GrowableTest::*GrowableTestMethod)();
    
    class GrowableTest : public Test {
    private:
        Trigonometry *trigonometry;
    public:
        
        void setup();
        void teardown();
        void runtest(string name, GrowableTestMethod method);
        
        void constructor_Test();
        void constructor_Trigo_Test();
        
        void setGrowthRate_G_Test();
        void setGrowthRate_GV_Test();
        
        void getGrowthRate_Test();
        void getGrowthRateX_Test();
        void getGrowthRateY_Test();
        
        void addGrowth_S_Test();
        void addGrowth_V_Test();
        void multiplyGrowth_S_Test();
        
        void updateScale_Test();
        
        void run();
    };
}

#endif /* GrowableTest_hpp */
