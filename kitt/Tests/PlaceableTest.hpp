//
//  PlaceableTest.hpp
//  kitt
//
//  Created by Marco Hernandez on 17/07/17.
//  Copyright © 2017 Marco Hernandez. All rights reserved.
//

#ifndef PlaceableTest_hpp
#define PlaceableTest_hpp

#include <iostream>
#include <string>
#include <exception>

#include "../Core/Trigonometry.hpp"
#include "../Testing/Assert.hpp"
#include "../Testing/Test.hpp"

namespace Tests {
    
    using namespace Core;
    using namespace Testing;
    using namespace std;
    
    
    class PlaceableTest;
    typedef void (PlaceableTest::*PlaceableTestMethod)();
    
    class PlaceableTest : public Test {
    private:
        Trigonometry *trigonometry;
        
    public:
        void setup();
        void teardown();
        void runtest(string name, PlaceableTestMethod method);
        
        void constructor_Empty_Test();
        void constructor_XY_Test();
        void constructor_V_Test();
        void constructor_Trigo_Test();
        void constructor_TrigoNull_Test();
        void constructor_TrigoXY_Test();
        void constructor_TrigoV_Test();
        void getDisplacement_V_Test();
        void getDisplacement_XY_Test();
        void setLocation_V_Test();
        void setLocation_XY_Test();
        void addLocation_V_Test();
        void addLocation_XY_Test();
        
        void run();
    };
}
#endif /* PlaceableTest_hpp */
