//
//  AngleableTest.cpp
//  kitt
//
//  Created by Marco Hernandez on 23/07/17.
//  Copyright © 2017 Marco Hernandez. All rights reserved.
//

#include "AngleableTest.hpp"
#include "../Core/RealtimeTrigonometry.hpp"
#include "../Testing/TestRunner.hpp"
#include "../Testing/Assert.hpp"
#include "../Behaviors/Angleable.hpp"

namespace Tests {
    using namespace Core;
    using namespace Testing;
    using namespace Behaviors;
    
    void AngleableTest::setup() {
        this->name = "Angleable";
        trigonometry = new RealtimeTrigonometry();
        Test::setup();
    }
    
    void AngleableTest::teardown() {
        delete trigonometry;
        Test::teardown();
    }
    
    void AngleableTest::runtest(string name, AngleableTestMethod method) {
        TestRunner<AngleableTest, AngleableTestMethod>(name, this, method).run();
    }
    
    void AngleableTest::constructor_Test() {
        Angleable angleable;
        assert.areEqual(angleable.getAngle(), 0.0);
        assert.areEqual(angleable.getRotatePivot(), Vector2D(0.0,0.0));
    }
    
    void AngleableTest::constructor_R_Test() {
        Angleable angleable(1.2);
        assert.areEqual(angleable.getAngle(), 1.2);
    }
    
    void AngleableTest::constructor_XY_Test() {
        Angleable angleable(3.4, 5.6);
        assert.areEqual(angleable.getRotatePivot(), Vector2D(3.4, 5.6));
    }
    
    void AngleableTest::constructor_P_Test() {
        Angleable angleable(Vector2D(3.4, 5.6));
        assert.areEqual(angleable.getRotatePivot(), Vector2D(3.4, 5.6));
    }
    
    void AngleableTest::constructor_XYR_Test() {
        Angleable angleable(3.4, 5.6, 7.8);
        assert.areEqual(angleable.getRotatePivot(), Vector2D(3.4, 5.6));
        assert.areEqual(angleable.getAngle(), 7.8);
    }
    
    void AngleableTest::constructor_PR_Test() {
        Angleable angleable(Vector2D(3.4, 5.6), 7.8);
        assert.areEqual(angleable.getRotatePivot(), Vector2D(3.4, 5.6));
        assert.areEqual(angleable.getAngle(), 7.8);
    }    
    
    void AngleableTest::setAngle_Test() {
        Angleable angleable;
        angleable.setAngle(4.5);
        assert.areEqual(angleable.getAngle(), 4.5);
    }
    void AngleableTest::setRotatePivot_XY_Test() {
        Angleable angleable;
        angleable.setRotatePivot(3.4, 5.6);
        assert.areEqual(angleable.getRotatePivot(), Vector2D(3.4, 5.6));
    }
    
    void AngleableTest::setRotatePivot_P_Test() {
        Angleable angleable;
        angleable.setRotatePivot(Vector2D(3.4, 5.6));
        assert.areEqual(angleable.getRotatePivot(), Vector2D(3.4, 5.6));
    }
    
    
    void AngleableTest::getAngle_Test() {
        Angleable angleable;
        angleable.setAngle(2.3);
        assert.areEqual(angleable.getAngle(), 2.3);
    }
    
    void AngleableTest::getRotatePivot_Test() {
        Angleable angleable;
        angleable.setRotatePivot(Vector2D(3.4, 5.6));
        assert.areEqual(angleable.getRotatePivot(), Vector2D(3.4, 5.6));
    }
    
    
    void AngleableTest::addAngle_Test() {
        Angleable angleable(1.2);
        angleable.addAngle(3.4);
        assert.areEqual(angleable.getAngle(), 4.6);
    }
    
    void AngleableTest::getAngleDisplacement_Test() {
        Angleable angleable(1.5);
        assert.areEqual(angleable.getAngleDisplacement(3.5), 2.0);
    }
    
    void AngleableTest::getRotatePivotDisplacement_XY_Test() {
        Angleable angleable(1.2, 1.2);
        assert.areEqual(angleable.getRotatePivotDisplacement(1.2), Vector2D(1.2, 1.2));
    }
    
    void AngleableTest::getRotatePivotDisplacement_P_Test() {
        Angleable angleable(1.2, 1.2);
        assert.areEqual(angleable.getRotatePivotDisplacement(1.2, 2.0), Vector2D(2.4, 2.4));
    }
    
    void AngleableTest::run() {
        runtest("constructor_Test-------------------", &AngleableTest::constructor_Test);
        runtest("constructor_R_Test-----------------", &AngleableTest::constructor_R_Test);
        runtest("constructor_XY_Test----------------", &AngleableTest::constructor_XY_Test);
        runtest("constructor_P_Test-----------------", &AngleableTest::constructor_P_Test);
        runtest("constructor_XYR_Test---------------", &AngleableTest::constructor_XYR_Test);
        runtest("constructor_PR_Test----------------", &AngleableTest::constructor_PR_Test);
        
        runtest("setAngle_Test----------------------", &AngleableTest::setAngle_Test);
        runtest("setRotatePivot_XY_Test-------------", &AngleableTest::setRotatePivot_XY_Test);
        runtest("setRotatePivot_P_Test--------------", &AngleableTest::setRotatePivot_P_Test);
        
        runtest("getAngle_Test----------------------", &AngleableTest::getAngle_Test);
        runtest("getRotatePivot_Test----------------", &AngleableTest::getRotatePivot_Test);
        
        runtest("addAngle_Test----------------------", &AngleableTest::addAngle_Test);
        runtest("getAngleDisplacement_Test----------", &AngleableTest::getAngleDisplacement_Test);
        runtest("getRotatePivotDisplacement_XY_Test-", &AngleableTest::getRotatePivotDisplacement_XY_Test);
        runtest("getRotatePivotDisplacement_P_Test--", &AngleableTest::getRotatePivotDisplacement_P_Test);
    }
}
