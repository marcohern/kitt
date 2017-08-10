//
//  TransformableTest.hpp
//  kitt
//
//  Created by Marco Hernandez on 29/07/17.
//  Copyright © 2017 Marco Hernandez. All rights reserved.
//

#ifndef TransformableTest_hpp
#define TransformableTest_hpp

#include "../Testing/Test.hpp"
#include "../Core/Trigonometry.hpp"

namespace Tests {
    using namespace Testing;
    using namespace Core;
    
    class TransformableTest;
    typedef void (TransformableTest::*TransformableTestMethod)();
    
    class TransformableTest : public Test {
    private:
        Trigonometry *trigonometry;
    public:
        void setup();
        void teardown();
        void runtest(string name, TransformableTestMethod method);
        
        void constructor_Test();
        void constructor_XY_Test();
        void constructor_L_Test();
        void constructor_T_Test();
        void constructor_XYT_Test();
        void constructor_LT_Test();
        
        void setRotateDirection_Test();
        void updateTransform_Test();

		void getScaledArea_Test();
        
        void run();
    };
}

#endif /* TransformableTest_hpp */
