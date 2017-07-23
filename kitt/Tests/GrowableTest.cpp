//
//  GrowableTest.cpp
//  kitt
//
//  Created by Marco Hernandez on 23/07/17.
//  Copyright © 2017 Marco Hernandez. All rights reserved.
//

#include "GrowableTest.hpp"
#include "../Testing/TestRunner.hpp"
#include "../Behaviors/Growable.hpp"
#include "../Core/RealtimeTrigonometry.hpp"

namespace Tests {
    using namespace Testing;
    using namespace Core;
    using namespace Behaviors;
    using namespace Exceptions;
    
    void GrowableTest::setup() {
        this->name = "Growable";
        trigonometry = new RealtimeTrigonometry();
        Test::setup();
    }
    
    void GrowableTest::teardown() {
        Test::teardown();
        delete trigonometry;
    }
    
    void GrowableTest::runtest(string name, GrowableTestMethod method) {
        TestRunner<GrowableTest, GrowableTestMethod>(name, this, method).run();
    }
    
    void GrowableTest::constructor_Test() {
        Vector2D zero;
        Growable growable;
        assert.areEqual(zero, growable.getGrowthRate());
    }
    void GrowableTest::constructor_Trigo_Test() {
        Vector2D zero(trigonometry);
        Growable growable(trigonometry);
        assert.areEqual(zero, growable.getGrowthRate());
    }
    
    void GrowableTest::setGrowthRate_G_Test() {
        Vector2D one(1.2, 1.2);
        Growable growable;
        growable.setGrowthRate(1.2);
        assert.areEqual(one, growable.getGrowthRate());
    }
    
    void GrowableTest::setGrowthRate_GV_Test() {
        Vector2D scalar(1.2, 1.2);
        Vector2D growth(1.2, 1.2);
        Growable growable;
        growable.setGrowthRate(growth);
        assert.areEqual(scalar, growable.getGrowthRate());
    }
    
    void GrowableTest::getGrowthRate_Test() {
        Growable growable;
        Vector2D zero;
        Vector2D rate = growable.getGrowthRate();
        assert.areEqual(zero, rate);
    }
    
    void GrowableTest::getGrowthRateX_Test() {
        Growable growable;
        growable.setGrowthRate(1.2);
        
        assert.areEqual(1.2, growable.getGrowthRateX());
    }
    
    void GrowableTest::getGrowthRateY_Test() {
        Growable growable;
        growable.setGrowthRate(3.4);
        
        assert.areEqual(3.4, growable.getGrowthRateY());
    }
    
    void GrowableTest::addGrowth_S_Test() {
        Growable growable;
        Vector2D scalar(1.4, 1.4);
        growable.setGrowthRate(1.2);
        
        growable.addGrowth(0.2);
        
        assert.areEqual(scalar, growable.getGrowthRate());
    }
    
    void GrowableTest::addGrowth_V_Test() {
        Growable growable;
        Vector2D growth(0.2, 0.4);
        Vector2D scalar(1.4, 1.6);
        growable.setGrowthRate(1.2);
        
        growable.addGrowth(growth);
        
        assert.areEqual(scalar, growable.getGrowthRate());
    }
    
    void GrowableTest::multiplyGrowth_S_Test() {
        Growable growable;
        Vector2D growth(1.0, 2.0);
        Vector2D scalar(2.0, 4.0);
        growable.setGrowthRate(growth);
        
        growable.multiplyGrowth(2.0);
        
        assert.areEqual(scalar, growable.getGrowthRate());
    }
    
    void GrowableTest::updateScale_Test() {
        Growable growable;
        Vector2D scale(4.0, 4.0);
        growable.setScale(2.0, 2.0);
        growable.setGrowthRate(2.0);
        
        growable.updateScale(1.0);
        
        assert.areEqual(scale, growable.getScale());
    }

    void GrowableTest::run() {
        
        runtest("constructor_Test",&GrowableTest::constructor_Test);
        runtest("constructor_Trigo_Test",&GrowableTest::constructor_Trigo_Test);
        runtest("setGrowthRate_G_Test",&GrowableTest::setGrowthRate_G_Test);
        runtest("setGrowthRate_GV_Test",&GrowableTest::setGrowthRate_GV_Test);
        runtest("getGrowthRate_Test",&GrowableTest::getGrowthRate_Test);
        runtest("getGrowthRateX_Test",&GrowableTest::getGrowthRateX_Test);
        runtest("getGrowthRateY_Test",&GrowableTest::getGrowthRateY_Test);
        runtest("addGrowth_S_Test",&GrowableTest::addGrowth_S_Test);
        runtest("addGrowth_V_Test",&GrowableTest::addGrowth_V_Test);
        runtest("multiplyGrowth_S_Test",&GrowableTest::multiplyGrowth_S_Test);
        runtest("updateScale_Test",&GrowableTest::updateScale_Test);
    }
}
