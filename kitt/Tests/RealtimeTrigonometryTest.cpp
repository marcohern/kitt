//
//  RealtimeTrigonometryTest.cpp
//  kitt
//
//  Created by Marco Hernandez on 1/07/17.
//  Copyright © 2017 Marco Hernandez. All rights reserved.
//

#include "RealtimeTrigonometryTest.hpp"
#include "../Testing/TestRunner.hpp"
#include "../Core/RealtimeTrigonometry.hpp"

namespace Tests {
    
    using namespace Exceptions;
    using namespace Core;
    
    void RealtimeTrigonometryTest::setup() {
        this->name = "RealtimeTrigonometry";
        Test::setup();
    }
    
    void RealtimeTrigonometryTest::teardown() {
        Test::teardown();
    }
    
    void RealtimeTrigonometryTest::cos_00_Test() {
        RealtimeTrigonometry rtt;
        double r = rtt.cos(0.0);
        assert.areEqual(r, 1.0);
    }
    
    void RealtimeTrigonometryTest::cos_05_Test() {
        RealtimeTrigonometry rtt;
        double r = rtt.cos(0.5);
        assert.areClose(r, 0.877582561890373,10);
    }
    
    void RealtimeTrigonometryTest::cos_10_Test(){
        RealtimeTrigonometry rtt;
        double r = rtt.cos(1.0);
        assert.areClose(r, 0.54030230586814,10);
    }
    
    void RealtimeTrigonometryTest::cos_20_Test() {
        RealtimeTrigonometry rtt;
        double r = rtt.cos(2.0);
        assert.areClose(r, -0.416146836547142,10);
    }
    
    void RealtimeTrigonometryTest::cos_pi_Test() {
        RealtimeTrigonometry rtt;
        double r = rtt.cos(3.141592653589793);
        assert.areEqual(r, -1.0);
    }
    
    void RealtimeTrigonometryTest::sin_00_Test() {
        RealtimeTrigonometry rtt;
        double r = rtt.sin(0.0);
        assert.areEqual(r, 0.0);
    }
    
    void RealtimeTrigonometryTest::sin_05_Test() {
        RealtimeTrigonometry rtt;
        double r = rtt.sin(0.5);
        assert.areClose(r, 0.479425538604203,10);
    }
    
    void RealtimeTrigonometryTest::sin_10_Test(){
        RealtimeTrigonometry rtt;
        double r = rtt.sin(1.0);
        assert.areClose(r, 0.841470984807897,10);
    }
    
    void RealtimeTrigonometryTest::sin_20_Test() {
        RealtimeTrigonometry rtt;
        double r = rtt.sin(2.0);
        assert.areClose(r, 0.909297426825682,10);
    }
    
    void RealtimeTrigonometryTest::sin_pi_Test() {
        RealtimeTrigonometry rtt;
        double r = rtt.sin(3.141592653589793);
        assert.areClose(r, 0.0,10);
    }
    
    void RealtimeTrigonometryTest::runtest(string name, RealtimeTrigonometryTestMethod method) {
        TestRunner<RealtimeTrigonometryTest, RealtimeTrigonometryTestMethod>
            (name, this, method).run();
    }
    
    void RealtimeTrigonometryTest::run() {
        runtest("cos_00_Test", &RealtimeTrigonometryTest::cos_00_Test);
        runtest("cos_05_Test", &RealtimeTrigonometryTest::cos_05_Test);
        runtest("cos_10_Test", &RealtimeTrigonometryTest::cos_10_Test);
        runtest("cos_20_Test", &RealtimeTrigonometryTest::cos_20_Test);
        runtest("cos_pi_Test", &RealtimeTrigonometryTest::cos_pi_Test);
        
        runtest("sin_00_Test", &RealtimeTrigonometryTest::sin_00_Test);
        runtest("sin_05_Test", &RealtimeTrigonometryTest::sin_05_Test);
        runtest("sin_10_Test", &RealtimeTrigonometryTest::sin_10_Test);
        runtest("sin_20_Test", &RealtimeTrigonometryTest::sin_20_Test);
        runtest("sin_pi_Test", &RealtimeTrigonometryTest::sin_pi_Test);
    }

}
