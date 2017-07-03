//
//  SdlTimeTests.cpp
//  kitt
//
//  Created by Marco Hernandez on 2/07/17.
//  Copyright © 2017 Marco Hernandez. All rights reserved.
//

#include "SdlTimeTests.hpp"
#include "../Testing/TestRunner.hpp"

namespace Tests {
    
    //using namespace Exceptions;
    using namespace Core;
    using namespace Testing;
    using namespace std;
    
    void SdlTimeTests::setup() {
        this->name = "SdlTime";
        Test::setup();
    }
    
    void SdlTimeTests::teardown() {
        Test::teardown();
    }
    
    void SdlTimeTests::runtest(string name, SdlTimeTestsMethod method) {
        TestRunner<SdlTimeTests, SdlTimeTestsMethod>
        (name, this, method).run();
    }
    
    void SdlTimeTests::run() {
        
    }
}
