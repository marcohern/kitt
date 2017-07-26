//
//  RotateableTest.cpp
//  kitt
//
//  Created by Marco Hernandez on 25/07/17.
//  Copyright © 2017 Marco Hernandez. All rights reserved.
//

#include "RotateableTest.hpp"
#include "../Core/RealtimeTrigonometry.hpp"
#include "../Testing/TestRunner.hpp"
#include "../Behaviors/Rotateable.hpp"

namespace Tests {
    using namespace Core;
    using namespace Behaviors;
    
    void RotateableTest::setup() {
        this->name = "Rotateable";
        trigonometry = new RealtimeTrigonometry();
        Test::setup();
    }
    
    void RotateableTest::teardown() {
        Test::teardown();
    }
    
    void RotateableTest::runtest(string name, RotateableTestMethod method) {
        TestRunner<RotateableTest, RotateableTestMethod>(name, this, method).run();
    }
    
    void RotateableTest::constructor_Test() {
        Rotateable rotateable;
        assert.areEqual(0.0, rotateable.getRotationRate());
    }
    
    void RotateableTest::constructor_R_Test() {
        Rotateable rotateable(2.3);
        assert.areEqual(2.3, rotateable.getAngle());
    }
    
    void RotateableTest::constructor_XY_Test() {
        Rotateable rotateable(2.3, 4.5);
        assert.areEqual(Vector2D(2.3, 4.5), rotateable.getRotatePivot());
    }
    
    void RotateableTest::constructor_P_Test() {
        Rotateable rotateable(Vector2D(2.3, 4.5));
        assert.areEqual(Vector2D(2.3, 4.5), rotateable.getRotatePivot());
        
    }
    void RotateableTest::constructor_XYR_Test() {
        Rotateable rotateable(2.3, 4.5, 6.7);
        assert.areEqual(Vector2D(2.3, 4.5), rotateable.getRotatePivot());
        assert.areEqual(6.7, rotateable.getAngle());
        
    }
    void RotateableTest::constructor_PR_Test(){
        Rotateable rotateable(Vector2D(2.3, 4.5), 6.7);
        assert.areEqual(Vector2D(2.3, 4.5), rotateable.getRotatePivot());
        assert.areEqual(6.7, rotateable.getAngle());
    }
    
    void RotateableTest::constructor_T_Test(){
        Rotateable rotateable(trigonometry);
        assert.areEqual(0.0, rotateable.getRotationRate());
    }
    void RotateableTest::constructor_RT_Test(){
        Rotateable rotateable(2.3, trigonometry);
        assert.areEqual(2.3, rotateable.getAngle());
    }
    void RotateableTest::constructor_XYT_Test() {
        Rotateable rotateable(2.3, 4.5, trigonometry);
        assert.areEqual(Vector2D(2.3, 4.5), rotateable.getRotatePivot());
    }
    void RotateableTest::constructor_PT_Test() {
        Rotateable rotateable(Vector2D(2.3, 4.5), trigonometry);
        assert.areEqual(Vector2D(2.3, 4.5), rotateable.getRotatePivot());
    }
    void RotateableTest::constructor_XYRT_Test() {
        Rotateable rotateable(2.3, 4.5, 6.7, trigonometry);
        assert.areEqual(Vector2D(2.3, 4.5), rotateable.getRotatePivot());
        assert.areEqual(6.7, rotateable.getAngle());
    }
    void RotateableTest::constructor_PRT_Test(){
        Rotateable rotateable(Vector2D(2.3, 4.5), 6.7, trigonometry);
        assert.areEqual(Vector2D(2.3, 4.5), rotateable.getRotatePivot());
        assert.areEqual(6.7, rotateable.getAngle());
    }
    
    void RotateableTest::setRotationRate_Test(){
        Rotateable rotateable;
        rotateable.setRotationRate(5.6);
        assert.areEqual(5.6, rotateable.getRotationRate());
    }
    void RotateableTest::addRotationRate_Test(){
        Rotateable rotateable;
        rotateable.setRotationRate(2.3);
        rotateable.addRotationRate(1.1);
        assert.areEqual(3.4, rotateable.getRotationRate());
    }
    void RotateableTest::getRotationRate_Test(){
        Rotateable rotateable;
        rotateable.setRotationRate(5.6);
        assert.areEqual(5.6, rotateable.getRotationRate());
    }
    void RotateableTest::updateAngle_Test(){
        Rotateable rotateable;
        rotateable.setAngle(0.2);
        rotateable.setRotationRate(5.6);
        rotateable.updateAngle(1.0);
        assert.areEqual(5.8, rotateable.getAngle());
    }

    void RotateableTest::run() {
        runtest("constructor_Test------", &RotateableTest::constructor_Test);
        runtest("constructor_R_Test----", &RotateableTest::constructor_R_Test);
        runtest("constructor_XY_Test---", &RotateableTest::constructor_XY_Test);
        runtest("constructor_P_Test----", &RotateableTest::constructor_P_Test);
        runtest("constructor_XYR_Test--", &RotateableTest::constructor_XYR_Test);
        runtest("constructor_PR_Test---", &RotateableTest::constructor_PR_Test);
        
        runtest("constructor_T_Test----", &RotateableTest::constructor_T_Test);
        runtest("constructor_RT_Test---", &RotateableTest::constructor_RT_Test);
        runtest("constructor_XYT_Test--", &RotateableTest::constructor_XYT_Test);
        runtest("constructor_PT_Test---", &RotateableTest::constructor_PT_Test);
        runtest("constructor_XYRT_Test-", &RotateableTest::constructor_XYRT_Test);
        runtest("constructor_PRT_Test--", &RotateableTest::constructor_PRT_Test);
        
        runtest("setRotationRate_Test--", &RotateableTest::setRotationRate_Test);
        runtest("addRotationRate_Test--", &RotateableTest::addRotationRate_Test);
        runtest("getRotationRate_Test--", &RotateableTest::getRotationRate_Test);
        runtest("updateAngle_Test------", &RotateableTest::updateAngle_Test);
    }
}
