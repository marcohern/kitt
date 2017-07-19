//
//  DirectableTest.hpp
//  kitt
//
//  Created by Marco Hernandez on 18/07/17.
//  Copyright © 2017 Marco Hernandez. All rights reserved.
//

#ifndef DirectableTest_hpp
#define DirectableTest_hpp

#include <iostream>
#include <string>
#include <exception>

#include "../Behaviors/Directable.hpp"
#include "../Core/Trigonometry.hpp"
#include "../Testing/Assert.hpp"
#include "../Testing/Test.hpp"

namespace Tests {
    
    using namespace Core;
    using namespace Testing;
    using namespace std;
    
    
    class DirectableTest;
    typedef void (DirectableTest::*DirectableTestMethod)();
    
    class DirectableTest : public Test {
    private:
        Trigonometry *trigonometry;
        
    public:
        void setup();
        void teardown();
        void runtest(string name, DirectableTestMethod method);
        
        void constructor_Empty_Test();
        void constructor_XY_Test();
        void constructor_V_Test();
        void constructor_Trigo_Test();
        void constructor_TrigoNull_Test();
        void constructor_TrigoXY_Test();
        void constructor_TrigoV_Test();
        
        void setDirection_XY_Test();
        void setDirection_V_Test();
        void updateLocation_Test();
        
        void run();
    };
}


#endif /* DirectableTest_hpp */
