//
//  RotateableTest.cpp
//  kitt
//
//  Created by Marco Hernandez on 23/07/17.
//  Copyright © 2017 Marco Hernandez. All rights reserved.
//

#include "RotateableTest.hpp"
#include "../Core/RealtimeTrigonometry.hpp"
#include "../Testing/TestRunner.hpp"
#include "../Testing/Assert.hpp"
#include "../Behaviors/Rotateable.hpp"

namespace Tests {
    using namespace Core;
    using namespace Testing;
    using namespace Behaviors;
    
    void RotateableTest::setup() {
        this->name = "Rotateable";
        trigonometry = new RealtimeTrigonometry();
        Test::setup();
    }
    
    void RotateableTest::teardown() {
        delete trigonometry;
        Test::teardown();
    }
    
    void RotateableTest::runtest(string name, RotateableTestMethod method) {
        TestRunner<RotateableTest, RotateableTestMethod>(name, this, method).run();
    }
    
    void RotateableTest::constructor_Test() {
        Rotateable rotateable;
        assert.areEqual(rotateable.getAngle(), 0.0);
        assert.areEqual(rotateable.getRotatePivot(), Vector2D(0.0,0.0));
    }
    
    void RotateableTest::constructor_R_Test() {
        Rotateable rotateable(1.2);
        assert.areEqual(rotateable.getAngle(), 1.2);
    }
    
    void RotateableTest::constructor_XY_Test() {
        Rotateable rotateable(3.4, 5.6);
        assert.areEqual(rotateable.getRotatePivot(), Vector2D(3.4, 5.6));
    }
    
    void RotateableTest::constructor_P_Test() {
        Rotateable rotateable(Vector2D(3.4, 5.6));
        assert.areEqual(rotateable.getRotatePivot(), Vector2D(3.4, 5.6));
    }
    
    void RotateableTest::constructor_XYR_Test() {
        Rotateable rotateable(3.4, 5.6, 7.8);
        assert.areEqual(rotateable.getRotatePivot(), Vector2D(3.4, 5.6));
        assert.areEqual(rotateable.getAngle(), 7.8);
    }
    
    void RotateableTest::constructor_PR_Test() {
        Rotateable rotateable(Vector2D(3.4, 5.6), 7.8);
        assert.areEqual(rotateable.getRotatePivot(), Vector2D(3.4, 5.6));
        assert.areEqual(rotateable.getAngle(), 7.8);
    }
    
    
    void RotateableTest::constructor_T_Test() {
        Rotateable rotateable(trigonometry);
        assert.areEqual(rotateable.getRotatePivot(), Vector2D(0.0, 0.0));
        assert.areEqual(rotateable.getAngle(), 0.0);
    }
    
    void RotateableTest::constructor_TR_Test() {
        Rotateable rotateable(1.2, trigonometry);
        assert.areEqual(rotateable.getRotatePivot(), Vector2D(0.0, 0.0));
        assert.areEqual(rotateable.getAngle(), 1.2);
    }
    
    void RotateableTest::constructor_TXY_Test() {
        Rotateable rotateable(3.4, 5.6, trigonometry);
        assert.areEqual(rotateable.getRotatePivot(), Vector2D(3.4, 5.6));
        assert.areEqual(rotateable.getAngle(), 0.0);
    }
    
    void RotateableTest::constructor_TP_Test() {
        Rotateable rotateable(Vector2D(3.4, 5.6), trigonometry);
        assert.areEqual(rotateable.getRotatePivot(), Vector2D(3.4, 5.6));
        assert.areEqual(rotateable.getAngle(), 0.0);
    }
    
    void RotateableTest::constructor_TXYR_Test() {
        Rotateable rotateable(3.4, 5.6, 7.8, trigonometry);
        assert.areEqual(rotateable.getRotatePivot(), Vector2D(3.4, 5.6));
        assert.areEqual(rotateable.getAngle(), 7.8);
    }
    
    void RotateableTest::constructor_TPR_Test() {
        Rotateable rotateable(Vector2D(3.4, 5.6), 7.8, trigonometry);
        assert.areEqual(rotateable.getRotatePivot(), Vector2D(3.4, 5.6));
        assert.areEqual(rotateable.getAngle(), 7.8);
    }
    
    
    void RotateableTest::setAngle_Test() {
        Rotateable rotateable;
        rotateable.setAngle(4.5);
        assert.areEqual(rotateable.getAngle(), 4.5);
    }
    void RotateableTest::setRotatePivot_XY_Test() {
        Rotateable rotateable;
        rotateable.setRotatePivot(3.4, 5.6);
        assert.areEqual(rotateable.getRotatePivot(), Vector2D(3.4, 5.6));
    }
    
    void RotateableTest::setRotatePivot_P_Test() {
        Rotateable rotateable;
        rotateable.setRotatePivot(Vector2D(3.4, 5.6));
        assert.areEqual(rotateable.getRotatePivot(), Vector2D(3.4, 5.6));
    }
    
    
    void RotateableTest::getAngle_Test() {
        Rotateable rotateable;
        rotateable.setAngle(2.3);
        assert.areEqual(rotateable.getAngle(), 2.3);
    }
    
    void RotateableTest::getRotatePivot_Test() {
        Rotateable rotateable;
        rotateable.setRotatePivot(Vector2D(3.4, 5.6));
        assert.areEqual(rotateable.getRotatePivot(), Vector2D(3.4, 5.6));
    }
    
    
    void RotateableTest::addAngle_Test() {
        Rotateable rotateable(1.2);
        rotateable.addAngle(3.4);
        assert.areEqual(rotateable.getAngle(), 4.6);
    }
    
    void RotateableTest::getAngleDisplacement_Test() {
        Rotateable rotateable(1.5);
        assert.areEqual(rotateable.getAngleDisplacement(3.5), 2.0);
    }
    
    void RotateableTest::getRotatePivotDisplacement_XY_Test() {
        Rotateable rotateable(1.2, 1.2);
        assert.areEqual(rotateable.getRotatePivotDisplacement(1.2), Vector2D(1.2, 1.2));
    }
    
    void RotateableTest::getRotatePivotDisplacement_P_Test() {
        Rotateable rotateable(1.2, 1.2);
        assert.areEqual(rotateable.getRotatePivotDisplacement(1.2, 2.0), Vector2D(2.4, 2.4));
    }
    
    void RotateableTest::run() {
        runtest("constructor_Test-------------------", &RotateableTest::constructor_Test);
        runtest("constructor_R_Test-----------------", &RotateableTest::constructor_R_Test);
        runtest("constructor_XY_Test----------------", &RotateableTest::constructor_XY_Test);
        runtest("constructor_P_Test-----------------", &RotateableTest::constructor_P_Test);
        runtest("constructor_XYR_Test---------------", &RotateableTest::constructor_XYR_Test);
        runtest("constructor_PR_Test----------------", &RotateableTest::constructor_PR_Test);
        
        runtest("constructor_T_Test-----------------", &RotateableTest::constructor_T_Test);
        runtest("constructor_TR_Test----------------", &RotateableTest::constructor_TR_Test);
        runtest("constructor_TXY_Test---------------", &RotateableTest::constructor_TXY_Test);
        runtest("constructor_TP_Test----------------", &RotateableTest::constructor_TP_Test);
        runtest("constructor_TXYR_Test--------------", &RotateableTest::constructor_TXYR_Test);
        runtest("constructor_TPR_Test---------------", &RotateableTest::constructor_TPR_Test);
        
        runtest("setAngle_Test----------------------", &RotateableTest::setAngle_Test);
        runtest("setRotatePivot_XY_Test-------------", &RotateableTest::setRotatePivot_XY_Test);
        runtest("setRotatePivot_P_Test--------------", &RotateableTest::setRotatePivot_P_Test);
        
        runtest("getAngle_Test----------------------", &RotateableTest::getAngle_Test);
        runtest("getRotatePivot_Test----------------", &RotateableTest::getRotatePivot_Test);
        
        runtest("addAngle_Test----------------------", &RotateableTest::addAngle_Test);
        runtest("getAngleDisplacement_Test----------", &RotateableTest::getAngleDisplacement_Test);
        runtest("getRotatePivotDisplacement_XY_Test-", &RotateableTest::getRotatePivotDisplacement_XY_Test);
        runtest("getRotatePivotDisplacement_P_Test--", &RotateableTest::getRotatePivotDisplacement_P_Test);
    }
}
