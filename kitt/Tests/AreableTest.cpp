//
//  AreableTest.cpp
//  kitt
//
//  Created by Marco Hernandez on 26/07/17.
//  Copyright © 2017 Marco Hernandez. All rights reserved.
//

#include "AreableTest.hpp"
#include "../Testing/TestRunner.hpp"
#include "../Core/RealtimeTrigonometry.hpp"
#include "../Behaviors/Areable.hpp"

namespace Tests {
    using namespace Core;
    using namespace Behaviors;
    
    void AreableTest::setup() {
        this->name = "Areable";
        trigonometry = new RealtimeTrigonometry();
        Test::setup();
    }
    
    void AreableTest::teardown() {
        Test::teardown();
    }
    
    void AreableTest::runtest(string name, AreableTestMethod method) {
        TestRunner<AreableTest, AreableTestMethod>(name, this, method).run();
    }
    
    void AreableTest::constructor_Test() {
        Areable areable;
        assert.areEqual(areable.getAreaVector(), Vector2D(0.0, 0.0));
        assert.areEqual(areable.getAreaPivot() , Vector2D(0.0, 0.0));
    }
    void AreableTest::constructor_WH_Test() {
        Areable areable(1.2, 3.4);
        assert.areEqual(areable.getAreaVector(), Vector2D(1.2, 3.4));
    }
    void AreableTest::constructor_WHXY_Test(){
        Areable areable(1.2, 3.4, 5.6, 7.8);
        assert.areEqual(areable.getAreaVector(), Vector2D(1.2, 3.4));
        assert.areEqual(areable.getAreaPivot() , Vector2D(5.6, 7.8));
    }
    void AreableTest::constructor_A_Test(){
        Vector2D area(1.2, 3.4);
        Areable areable(area);
        assert.areEqual(areable.getAreaVector(), Vector2D(1.2, 3.4));
    }
    void AreableTest::constructor_AP_Test(){
        Vector2D area(1.2, 3.4);
        Vector2D pivot(5.6, 7.8);
        Areable areable(area, pivot);
        assert.areEqual(areable.getAreaVector(), Vector2D(1.2, 3.4));
        assert.areEqual(areable.getAreaPivot() , Vector2D(5.6, 7.8));
    }
    
    void AreableTest::constructor_T_Test() {
        Areable areable(trigonometry);
        assert.areEqual(areable.getAreaVector(), Vector2D(0.0, 0.0));
        assert.areEqual(areable.getAreaPivot() , Vector2D(0.0, 0.0));
    }
    void AreableTest::constructor_WHT_Test() {
        Areable areable(1.2, 3.4, trigonometry);
        assert.areEqual(areable.getAreaVector(), Vector2D(1.2, 3.4));
    }
    void AreableTest::constructor_WHXYT_Test(){
        Areable areable(1.2, 3.4, 5.6, 7.8, trigonometry);
        assert.areEqual(areable.getAreaVector(), Vector2D(1.2, 3.4));
        assert.areEqual(areable.getAreaPivot() , Vector2D(5.6, 7.8));
    }
    void AreableTest::constructor_AT_Test(){
        Vector2D area(1.2, 3.4);
        Areable areable(area, trigonometry);
        assert.areEqual(areable.getAreaVector(), Vector2D(1.2, 3.4));
    }
    void AreableTest::constructor_APT_Test(){
        Vector2D area(1.2, 3.4);
        Vector2D pivot(5.6, 7.8);
        Areable areable(area, pivot, trigonometry);
        assert.areEqual(areable.getAreaVector(), Vector2D(1.2, 3.4));
        assert.areEqual(areable.getAreaPivot() , Vector2D(5.6, 7.8));
    }
    
    void AreableTest::setWidth_Test(){
        Areable areable;
        areable.setWidth(1.2);
        assert.areEqual(areable.getWidth(), 1.2);
    }
    void AreableTest::setHeight_Test() {
        Areable areable;
        areable.setHeight(3.4);
        assert.areEqual(areable.getHeight(), 3.4);
    }
    void AreableTest::setAreaVector_WH_Test() {
        Areable areable;
        areable.setAreaVector(1.2, 3.4);
        assert.areEqual(areable.getAreaVector(), Vector2D(1.2, 3.4));
    }
    void AreableTest::setAreaVector_A_Test() {
        Vector2D area(1.2, 3.4);
        Areable areable;
        areable.setAreaVector(area);
        assert.areEqual(areable.getAreaVector(), Vector2D(1.2, 3.4));
    
    }
    void AreableTest::setAreaPivot_XY_Test(){
        Areable areable;
        areable.setAreaPivot(5.6, 7.8);
        assert.areEqual(areable.getAreaPivot() , Vector2D(5.6, 7.8));
    }
    void AreableTest::setAreaPivot_P_Test(){
        Vector2D pivot(5.6, 7.8);
        Areable areable;
        areable.setAreaPivot(pivot);
        assert.areEqual(areable.getAreaPivot() , Vector2D(5.6, 7.8));
    }
    
    void AreableTest::getWidth_Test(){
        Areable areable;
        areable.setWidth(1.2);
        assert.areEqual(areable.getWidth(), 1.2);
    }
    void AreableTest::getHeight_Test(){
        Areable areable;
        areable.setHeight(3.4);
        assert.areEqual(areable.getHeight(), 3.4);
    }
    void AreableTest::getAreaVector_Test(){
        Vector2D area(1.2, 3.4);
        Areable areable;
        areable.setAreaVector(area);
        assert.areEqual(areable.getAreaVector(), Vector2D(1.2, 3.4));
    }
    void AreableTest::getArea_Test(){
        Areable areable(1.2, 3.4);
        
        assert.areEqual(areable.getArea(), 4.0800);
    }
    void AreableTest::getAreaPivot_Test(){
        Vector2D pivot(5.6, 7.8);
        Areable areable;
        areable.setAreaPivot(pivot);
        assert.areEqual(areable.getAreaPivot() , Vector2D(5.6, 7.8));
    }
    
    
    void AreableTest::run() {
        runtest("constructor_Test-------", &AreableTest::constructor_Test);
        runtest("constructor_WH_Test----", &AreableTest::constructor_WH_Test);
        runtest("constructor_WHXY_Test--", &AreableTest::constructor_WHXY_Test);
        runtest("constructor_A_Test-----", &AreableTest::constructor_A_Test);
        runtest("constructor_AP_Test----", &AreableTest::constructor_AP_Test);
        
        runtest("constructor_T_Test-----", &AreableTest::constructor_T_Test);
        runtest("constructor_WHT_Test---", &AreableTest::constructor_WHT_Test);
        runtest("constructor_WHXYT_Test-", &AreableTest::constructor_WHXYT_Test);
        runtest("constructor_AT_Test----", &AreableTest::constructor_AT_Test);
        runtest("constructor_APT_Test---", &AreableTest::constructor_APT_Test);
        
        runtest("setWidth_Test----------", &AreableTest::setWidth_Test);
        runtest("setHeight_Test---------", &AreableTest::setHeight_Test);
        runtest("setAreaVector_WH_Test--", &AreableTest::setAreaVector_WH_Test);
        runtest("setAreaVector_A_Test---", &AreableTest::setAreaVector_A_Test);
        runtest("setAreaPivot_XY_Test---", &AreableTest::setAreaPivot_XY_Test);
        runtest("setAreaPivot_P_Test----", &AreableTest::setAreaPivot_P_Test);
        
        runtest("getWidth_Test----------", &AreableTest::getWidth_Test);
        runtest("getHeight_Test---------", &AreableTest::getHeight_Test);
        runtest("getAreaVector_Test-----", &AreableTest::getAreaVector_Test);
        runtest("getArea_Test-----------", &AreableTest::getArea_Test);
        runtest("getAreaPivot_Test------", &AreableTest::getAreaPivot_Test);
    }
}
