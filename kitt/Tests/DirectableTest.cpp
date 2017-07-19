//
//  DirectableTest.cpp
//  kitt
//
//  Created by Marco Hernandez on 18/07/17.
//  Copyright © 2017 Marco Hernandez. All rights reserved.
//

#include "DirectableTest.hpp"
#include "../Testing/TestRunner.hpp"
#include "../Core/RealtimeTrigonometry.hpp"
#include "../Behaviors/Directable.hpp"
#include "../Exceptions/NullReferenceException.hpp"

namespace Tests {
    using namespace Testing;
    using namespace Core;
    using namespace Behaviors;
    using namespace Exceptions;
    
    void DirectableTest::setup() {
        this->name = "Directable";
        trigonometry = new RealtimeTrigonometry();
        Test::setup();
    }
    
    void DirectableTest::teardown() {
        Test::teardown();
        delete trigonometry;
    }
    
    void DirectableTest::runtest(string name, DirectableTestMethod method) {
        TestRunner<DirectableTest, DirectableTestMethod>(name, this, method).run();
    }
    
    void DirectableTest::constructor_Empty_Test() {
        Directable directable;
        assert.areEqual(directable.getDirection().getX(), 0.0);
        assert.areEqual(directable.getDirection().getY(), 0.0);
    }
    
    void DirectableTest::constructor_XY_Test() {
        Directable directable(1.23, 4.56);
        assert.areEqual(directable.getDirection().getX(), 0.0);
        assert.areEqual(directable.getDirection().getY(), 0.0);
        assert.areEqual(directable.getLocation().getX(), 1.23);
        assert.areEqual(directable.getLocation().getY(), 4.56);
    }
    
    void DirectableTest::constructor_V_Test() {
        Vector2D v(1.23, 4.56);
        Directable directable(v);
        assert.areEqual(directable.getDirection().getX(), 0.0);
        assert.areEqual(directable.getDirection().getY(), 0.0);
        assert.areEqual(directable.getLocation().getX(), 1.23);
        assert.areEqual(directable.getLocation().getY(), 4.56);
    }
    
    void DirectableTest::constructor_Trigo_Test() {
        Directable directable(trigonometry);
        assert.areEqual(directable.getDirection().getX(), 0.0);
        assert.areEqual(directable.getDirection().getY(), 0.0);
    }
    
    void DirectableTest::constructor_TrigoNull_Test(){
        try {
            Directable directable(NULL);
        } catch(NullReferenceException &ex) {
            assert.isTrue(true);
        }
    }
    
    void DirectableTest::constructor_TrigoXY_Test(){
        Directable directable(1.23, 4.56, trigonometry);
        assert.areEqual(directable.getDirection().getX(), 0.0);
        assert.areEqual(directable.getDirection().getY(), 0.0);
        assert.areEqual(directable.getLocation().getX(), 1.23);
        assert.areEqual(directable.getLocation().getY(), 4.56);
    }
    
    void DirectableTest::constructor_TrigoV_Test(){
        Vector2D v(1.23, 4.56, trigonometry);
        Directable directable(v);
        assert.areEqual(directable.getDirection().getX(), 0.0);
        assert.areEqual(directable.getDirection().getY(), 0.0);
        assert.areEqual(directable.getLocation().getX(), 1.23);
        assert.areEqual(directable.getLocation().getY(), 4.56);
    }
    
    void DirectableTest::setDirection_XY_Test() {
        Directable directable;
        directable.setDirection(1.23, 4.56);
        assert.areEqual(directable.getDirection().getX(), 1.23);
        assert.areEqual(directable.getDirection().getY(), 4.56);
    }
    
    void DirectableTest::setDirection_V_Test(){
        Vector2D direction(1.23, 4.56);
        Directable directable;
        directable.setDirection(direction);
        assert.areEqual(directable.getDirection().getX(), 1.23);
        assert.areEqual(directable.getDirection().getY(), 4.56);
    }
    void DirectableTest::updateLocation_Test(){
        Directable directable(0.0, 0.0);
        directable.setDirection(4.0, 2.0);
        directable.updateLocation(0.5);
        assert.areEqual(directable.getLocation().getX(), 2.0);
        assert.areEqual(directable.getLocation().getY(), 1.0);
        directable.updateLocation(0.5);
        assert.areEqual(directable.getLocation().getX(), 4.0);
        assert.areEqual(directable.getLocation().getY(), 2.0);
    }
    
    void DirectableTest::run() {
        runtest("constructor_Empty_Test--------", &DirectableTest::constructor_Empty_Test);
        runtest("constructor_XY_Test-----------", &DirectableTest::constructor_XY_Test);
        runtest("constructor_V_Test------------", &DirectableTest::constructor_V_Test);
        runtest("constructor_Trigo_Test--------", &DirectableTest::constructor_Trigo_Test);
        runtest("constructor_TrigoNull_Test----", &DirectableTest::constructor_TrigoNull_Test);
        runtest("constructor_TrigoXY_Test------", &DirectableTest::constructor_TrigoXY_Test);
        runtest("constructor_TrigoV_Test-------", &DirectableTest::constructor_TrigoV_Test);
        runtest("setDirection_XY_Test----------", &DirectableTest::setDirection_XY_Test);
        runtest("setDirection_V_Test-----------", &DirectableTest::setDirection_V_Test);
        runtest("updateLocation_Test-----------", &DirectableTest::updateLocation_Test);
    }
}
