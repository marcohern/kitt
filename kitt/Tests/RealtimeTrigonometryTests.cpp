//
//  RealtimeTrigonometryTest.cpp
//  kitt
//
//  Created by Marco Hernandez on 1/07/17.
//  Copyright © 2017 Marco Hernandez. All rights reserved.
//

#include "RealtimeTrigonometryTests.hpp"
#include "../Testing/TestRunner.hpp"
#include "../Core/RealtimeTrigonometry.hpp"

namespace Tests {
    
    using namespace Exceptions;
    using namespace Core;
    
    void RealtimeTrigonometryTests::setup() {
        this->name = "RealtimeTrigonometry";
        Test::setup();
    }
    
    void RealtimeTrigonometryTests::teardown() {
        Test::teardown();
    }
    
    void RealtimeTrigonometryTests::cos_00_Test() {
        RealtimeTrigonometry rtt;
        double r = rtt.cos(0.0);
        assert.areEqual(r, 1.0);
    }
    
    void RealtimeTrigonometryTests::cos_05_Test() {
        RealtimeTrigonometry rtt;
        double r = rtt.cos(0.5);
        assert.areClose(r, 0.877582561890373,10);
    }
    
    void RealtimeTrigonometryTests::cos_10_Test(){
        RealtimeTrigonometry rtt;
        double r = rtt.cos(1.0);
        assert.areClose(r, 0.54030230586814,10);
    }
    
    void RealtimeTrigonometryTests::cos_20_Test() {
        RealtimeTrigonometry rtt;
        double r = rtt.cos(2.0);
        assert.areClose(r, -0.416146836547142,10);
    }
    
    void RealtimeTrigonometryTests::cos_pi_Test() {
        RealtimeTrigonometry rtt;
        double r = rtt.cos(3.141592653589793);
        assert.areEqual(r, -1.0);
    }
    
    void RealtimeTrigonometryTests::sin_00_Test() {
        RealtimeTrigonometry rtt;
        double r = rtt.sin(0.0);
        assert.areEqual(r, 0.0);
    }
    
    void RealtimeTrigonometryTests::sin_05_Test() {
        RealtimeTrigonometry rtt;
        double r = rtt.sin(0.5);
        assert.areClose(r, 0.479425538604203,10);
    }
    
    void RealtimeTrigonometryTests::sin_10_Test(){
        RealtimeTrigonometry rtt;
        double r = rtt.sin(1.0);
        assert.areClose(r, 0.841470984807897,10);
    }
    
    void RealtimeTrigonometryTests::sin_20_Test() {
        RealtimeTrigonometry rtt;
        double r = rtt.sin(2.0);
        assert.areClose(r, 0.909297426825682,10);
    }
    
    void RealtimeTrigonometryTests::sin_pi_Test() {
        RealtimeTrigonometry rtt;
        double r = rtt.sin(3.141592653589793);
        assert.areClose(r, 0.0, 10);
    }
    
    void RealtimeTrigonometryTests::cos_random_Test() {
        RealtimeTrigonometry rtt;
        double start = time(NULL);
        for (int i=0;i<1000000;i++) {
            double rnd = (double) rand()/RAND_MAX;
            double num = rnd*1000;
            rtt.cos(num);
        }
        double end = time(NULL);
        double diff = end - start;
        cout<<"Duration:"<<diff<<endl;
        assert.isTrue(true);
    }
    
    void RealtimeTrigonometryTests::runtest(string name, RealtimeTrigonometryTestsMethod method) {
        TestRunner<RealtimeTrigonometryTests, RealtimeTrigonometryTestsMethod>
            (name, this, method).run();
    }
    
    void RealtimeTrigonometryTests::run() {
        runtest("cos_00_Test--", &RealtimeTrigonometryTests::cos_00_Test);
        runtest("cos_05_Test--", &RealtimeTrigonometryTests::cos_05_Test);
        runtest("cos_10_Test--", &RealtimeTrigonometryTests::cos_10_Test);
        runtest("cos_20_Test--", &RealtimeTrigonometryTests::cos_20_Test);
        runtest("cos_pi_Test--", &RealtimeTrigonometryTests::cos_pi_Test);
        
        runtest("sin_00_Test--", &RealtimeTrigonometryTests::sin_00_Test);
        runtest("sin_05_Test--", &RealtimeTrigonometryTests::sin_05_Test);
        runtest("sin_10_Test--", &RealtimeTrigonometryTests::sin_10_Test);
        runtest("sin_20_Test--", &RealtimeTrigonometryTests::sin_20_Test);
        runtest("sin_pi_Test--", &RealtimeTrigonometryTests::sin_pi_Test);
    }

}
