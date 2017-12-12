//
//  TransformableTest.cpp
//  kitt
//
//  Created by Marco Hernandez on 29/07/17.
//  Copyright © 2017 Marco Hernandez. All rights reserved.
//

#include "TransformableTest.hpp"
#include "../Testing/TestRunner.hpp"
#include "../Behaviors/Transformable.hpp"
#include "../Core/RealtimeTrigonometry.hpp"

namespace Tests {
    
    using namespace Core;
    using namespace Behaviors;
    
    void TransformableTest::setup() {
        this->name = "Transformable";
        trigonometry = new RealtimeTrigonometry();
        Test::setup();
    }
    
    void TransformableTest::teardown() {
        Test::teardown();
    }
    
    void TransformableTest::runtest(string name, TransformableTestMethod method) {
        TestRunner<TransformableTest, TransformableTestMethod>(name, this, method).run();
    }
    
    
    void TransformableTest::constructor_Test() {
        Transformable trans;
        assert.areEqual(trans.getLocation(), Vector2D());
    }
    void TransformableTest::constructor_XY_Test(){
        Transformable trans(1.2, 3.4);
        assert.areEqual(trans.getLocation(), Vector2D(1.2, 3.4));
    }
    void TransformableTest::constructor_L_Test(){
        Transformable trans(Vector2D(1.2, 3.4));
        assert.areEqual(trans.getLocation(), Vector2D(1.2, 3.4));
    }
    void TransformableTest::constructor_T_Test(){
        Transformable trans;
        assert.areEqual(trans.getLocation(), Vector2D());
    }
    void TransformableTest::constructor_XYT_Test(){
        Transformable trans(1.2, 3.4);
        assert.areEqual(trans.getLocation(), Vector2D(1.2, 3.4));
    }
    void TransformableTest::constructor_LT_Test(){
        Transformable trans(Vector2D(1.2, 3.4));
        assert.areEqual(trans.getLocation(), Vector2D(1.2, 3.4));
    }
    
    void TransformableTest::setRotateDirection_Test(){
        Transformable trans;
        trans.setRotateDirection(true);
        assert.isTrue(true);
    }
    void TransformableTest::updateTransform_Test(){
        Transformable trans;
        trans.updateTransform(1.0);
        assert.isTrue(true);
    }

	void TransformableTest::getScaledArea_Test() {
		Transformable trans;
		trans.setScale(2.0, 2.0);
		trans.setAreaVector(2.0, 2.0);
		
		assert.areEqual(trans.getScaledArea().getX(), 4.0);
		assert.areEqual(trans.getScaledArea().getY(), 4.0);
	}
    
    void TransformableTest::run() {
        runtest("constructor_Test--------", &TransformableTest::constructor_Test);
        runtest("constructor_XY_Test-----", &TransformableTest::constructor_XY_Test);
        runtest("constructor_L_Test------", &TransformableTest::constructor_L_Test);
        runtest("constructor_T_Test------", &TransformableTest::constructor_T_Test);
        runtest("constructor_XYT_Test----", &TransformableTest::constructor_XYT_Test);
        runtest("constructor_LT_Test-----", &TransformableTest::constructor_LT_Test);
        
        runtest("setRotateDirection_Test-", &TransformableTest::setRotateDirection_Test);
		runtest("updateTransform_Test----", &TransformableTest::updateTransform_Test);
		runtest("getScaledArea_Test------", &TransformableTest::getScaledArea_Test);
    }
}
