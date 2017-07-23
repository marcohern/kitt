//
//  ScalableTest.hpp
//  kitt
//
//  Created by Marco Hernandez on 23/07/17.
//  Copyright © 2017 Marco Hernandez. All rights reserved.
//

#ifndef ScalableTest_hpp
#define ScalableTest_hpp

#include "../Testing/Test.hpp"
#include "../Core/Trigonometry.hpp"
#include "../Testing/Assert.hpp"
#include "../Testing/Test.hpp"

namespace Tests {
    using namespace Testing;
    using namespace Core;
    
    class ScalableTest;
    typedef void (ScalableTest::*ScalableTestMethod)();
    
    class ScalableTest : public Test {
    private:
        Trigonometry *trigonometry;
    public:
        
        void setup();
        void teardown();
        void runtest(string name, ScalableTestMethod method);
        
        void constructor_Test();
        void constructor_S_Test();
        void constructor_SXY_Test();
        void constructor_SV_Test();
        
        void constructor_Trigo_Test();
        void constructor_STrigo_Test();
        void constructor_SXYTrigo_Test();
        void constructor_SVTrigo_Test();
        
        void getScale_Test();
        void getScaleX_Test();
        void getScaleY_Test();
        
        void setScale_S_Test();
        void setScale_SXY_Test();
        void setScale_SV_Test();
        
        void getZoomScale_Test();
        
        void run();
    };
}
#endif /* ScalableTest_hpp */
