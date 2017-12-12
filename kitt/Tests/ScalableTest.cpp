//
//  ScalableTest.cpp
//  kitt
//
//  Created by Marco Hernandez on 23/07/17.
//  Copyright © 2017 Marco Hernandez. All rights reserved.
//

#include "ScalableTest.hpp"
#include "../Testing/TestRunner.hpp"
#include "../Behaviors/Scalable.hpp"
#include "../Core/Trigonometry.hpp"
#include "../Core/RealtimeTrigonometry.hpp"

namespace Tests {
    using namespace Testing;
    using namespace Core;
    using namespace Behaviors;
    using namespace Exceptions;
    
    void ScalableTest::setup() {
        this->name = "Scalable";
        trigonometry = new RealtimeTrigonometry();
        Test::setup();
    }
    
    void ScalableTest::teardown() {
        Test::teardown();
        delete trigonometry;
    }
    
    void ScalableTest::runtest(string name, ScalableTestMethod method) {
        TestRunner<ScalableTest, ScalableTestMethod>(name, this, method).run();
    }
    
    void ScalableTest::constructor_Test() {
        Scalable scalable;
        assert.areEqual(scalable.getScaleX(), 1.0);
        assert.areEqual(scalable.getScaleY(), 1.0);
    }
    
    void ScalableTest::constructor_S_Test() {
        Scalable scalable(2.0);
        assert.areEqual(scalable.getScaleX(), 2.0);
        assert.areEqual(scalable.getScaleY(), 2.0);
    }
    
    void ScalableTest::constructor_SXY_Test(){
        Scalable scalable(1.2, 3.4);
        assert.areEqual(scalable.getScaleX(), 1.2);
        assert.areEqual(scalable.getScaleY(), 3.4);
    }
    
    void ScalableTest::constructor_SV_Test(){
        Vector2D scale(1.2, 3.4);
        Scalable scalable(scale);
        assert.areEqual(scalable.getScaleX(), 1.2);
        assert.areEqual(scalable.getScaleY(), 3.4);
    }
    
    void ScalableTest::constructor_Trigo_Test(){
        Scalable scalable;
        assert.areEqual(scalable.getScaleX(), 1.0);
        assert.areEqual(scalable.getScaleY(), 1.0);
    }
    void ScalableTest::constructor_STrigo_Test(){
        Scalable scalable(2.0);
        assert.areEqual(scalable.getScaleX(), 2.0);
        assert.areEqual(scalable.getScaleY(), 2.0);
    }
    void ScalableTest::constructor_SXYTrigo_Test(){
        Scalable scalable(1.2, 3.4);
        assert.areEqual(scalable.getScaleX(), 1.2);
        assert.areEqual(scalable.getScaleY(), 3.4);
    }
    void ScalableTest::constructor_SVTrigo_Test(){
        Vector2D scale(1.2, 3.4);
        Scalable scalable(scale);
        assert.areEqual(scalable.getScaleX(), 1.2);
        assert.areEqual(scalable.getScaleY(), 3.4);
    }
    
    void ScalableTest::getScale_Test(){
        Vector2D scale(2.3, 4.5);
        Scalable scalable(2.3, 4.5);
        Vector2D v = scalable.getScale();
        assert.areEqual(scale, v);
    }
    
    void ScalableTest::getScaleX_Test(){
        Scalable scalable(2.3, 4.5);
        double x = scalable.getScaleX();
        assert.areEqual(2.3, x);
    }
    
    void ScalableTest::getScaleY_Test(){
        Scalable scalable(2.3, 4.5);
        double y = scalable.getScaleY();
        assert.areEqual(4.5, y);
    }
    
    void ScalableTest::setScale_S_Test(){
        Vector2D scale(2.0, 2.0);
        Scalable scalable;
        scalable.setScale(2.0);
        assert.areEqual(scale, scalable.getScale());
    }
    
    void ScalableTest::setScale_SXY_Test(){
        Vector2D scale(2.0, 2.0);
        Scalable scalable;
        scalable.setScale(2.0, 2.0);
        assert.areEqual(scale, scalable.getScale());
    }
    
    void ScalableTest::setScale_SV_Test(){
        Vector2D scale(2.0, 2.0);
        Scalable scalable;
        scalable.setScale(scale);
        assert.areEqual(scalable.getScaleX(), 2.0);
        assert.areEqual(scalable.getScaleY(), 2.0);
    }
    
    void ScalableTest::getZoomScale_Test(){
        Scalable scalable(2.0);
        Vector2D zooms = scalable.getZoomScale(2.0);
        assert.areEqual(zooms.getX(), 4.0);
        assert.areEqual(zooms.getY(), 4.0);
    }
    

    void ScalableTest::run() {
        runtest("constructor_Test----------",&ScalableTest::constructor_Test);
        runtest("constructor_S_Test--------",&ScalableTest::constructor_S_Test);
        runtest("constructor_SXY_Test------",&ScalableTest::constructor_SXY_Test);
        runtest("constructor_SV_Test-------",&ScalableTest::constructor_SV_Test);
        
        runtest("constructor_Trigo_Test----",&ScalableTest::constructor_Trigo_Test);
        runtest("constructor_STrigo_Test---",&ScalableTest::constructor_STrigo_Test);
        runtest("constructor_SXYTrigo_Test-",&ScalableTest::constructor_SXYTrigo_Test);
        runtest("constructor_SVTrigo_Test--",&ScalableTest::constructor_SVTrigo_Test);
        
        runtest("getScale_Test-------------",&ScalableTest::getScale_Test);
        runtest("getScaleX_Test------------",&ScalableTest::getScaleX_Test);
        runtest("getScaleY_Test------------",&ScalableTest::getScaleY_Test);
        runtest("setScale_S_Test-----------",&ScalableTest::setScale_S_Test);
        runtest("setScale_SXY_Test---------",&ScalableTest::setScale_SXY_Test);
        runtest("setScale_SV_Test----------",&ScalableTest::setScale_SV_Test);
        runtest("getZoomScale_Test---------",&ScalableTest::getZoomScale_Test);
    }
}
