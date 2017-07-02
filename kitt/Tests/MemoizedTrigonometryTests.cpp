//
//  MemoizedTrigonometryTests.cpp
//  kitt
//
//  Created by Marco Hernandez on 1/07/17.
//  Copyright © 2017 Marco Hernandez. All rights reserved.
//

#include "MemoizedTrigonometryTests.hpp"
#include "../Testing/TestRunner.hpp"
#include "../Core/MemoizedTrigonometry.hpp"

namespace Tests {
    
    using namespace Exceptions;
    using namespace Core;
    
    void MemoizedTrigonometryTests::setup() {
        this->name = "MemoizedTrigonometry";
        Test::setup();
    }
    
    void MemoizedTrigonometryTests::teardown() {
        Test::teardown();
    }
    
    void MemoizedTrigonometryTests::cos_00_Test() {
        MemoizedTrigonometry rtt;
        double r = rtt.cos(0.0);
        assert.areEqual(r, 1.0);
    }
    
    void MemoizedTrigonometryTests::cos_05_Test() {
        MemoizedTrigonometry rtt;
        double r = rtt.cos(0.5);
        assert.areClose(r, 0.877582561890373,10);
    }
    
    void MemoizedTrigonometryTests::cos_10_Test(){
        MemoizedTrigonometry rtt;
        double r = rtt.cos(1.0);
        assert.areClose(r, 0.54030230586814,10);
    }
    
    void MemoizedTrigonometryTests::cos_20_Test() {
        MemoizedTrigonometry rtt;
        double r = rtt.cos(2.0);
        assert.areClose(r, -0.416146836547142,10);
    }
    
    void MemoizedTrigonometryTests::cos_pi_Test() {
        MemoizedTrigonometry rtt;
        double r = rtt.cos(3.141592653589793);
        assert.areEqual(r, -1.0);
    }
    
    void MemoizedTrigonometryTests::sin_00_Test() {
        MemoizedTrigonometry rtt;
        double r = rtt.sin(0.0);
        assert.areEqual(r, 0.0);
    }
    
    void MemoizedTrigonometryTests::sin_05_Test() {
        MemoizedTrigonometry rtt;
        double r = rtt.sin(0.5);
        assert.areClose(r, 0.479425538604203,10);
    }
    
    void MemoizedTrigonometryTests::sin_10_Test(){
        MemoizedTrigonometry rtt;
        double r = rtt.sin(1.0);
        assert.areClose(r, 0.841470984807897,10);
    }
    
    void MemoizedTrigonometryTests::sin_20_Test() {
        MemoizedTrigonometry rtt;
        double r = rtt.sin(2.0);
        assert.areClose(r, 0.909297426825682,10);
    }
    
    void MemoizedTrigonometryTests::sin_pi_Test() {
        MemoizedTrigonometry rtt;
        double r = rtt.sin(3.141592653589793);
        assert.areClose(r, 0.0, 10);
    }
    
    void MemoizedTrigonometryTests::runtest(string name, MemoizedTrigonometryTestsMethod method) {
        TestRunner<MemoizedTrigonometryTests, MemoizedTrigonometryTestsMethod>
        (name, this, method).run();
    }
    
    void MemoizedTrigonometryTests::run() {
        runtest("cos_00_Test--", &MemoizedTrigonometryTests::cos_00_Test);
        runtest("cos_05_Test--", &MemoizedTrigonometryTests::cos_05_Test);
        runtest("cos_10_Test--", &MemoizedTrigonometryTests::cos_10_Test);
        runtest("cos_20_Test--", &MemoizedTrigonometryTests::cos_20_Test);
        runtest("cos_pi_Test--", &MemoizedTrigonometryTests::cos_pi_Test);
        
        runtest("sin_00_Test--", &MemoizedTrigonometryTests::sin_00_Test);
        runtest("sin_05_Test--", &MemoizedTrigonometryTests::sin_05_Test);
        runtest("sin_10_Test--", &MemoizedTrigonometryTests::sin_10_Test);
        runtest("sin_20_Test--", &MemoizedTrigonometryTests::sin_20_Test);
        runtest("sin_pi_Test--", &MemoizedTrigonometryTests::sin_pi_Test);
    }
    
}
