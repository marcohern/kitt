//
//  PlaceableTest.cpp
//  kitt
//
//  Created by Marco Hernandez on 17/07/17.
//  Copyright © 2017 Marco Hernandez. All rights reserved.
//

#include "PlaceableTest.hpp"
#include "../Testing/TestRunner.hpp"
#include "../Core/RealtimeTrigonometry.hpp"
#include "../Behaviors/Placeable.hpp"
#include "../Exceptions/NullReferenceException.hpp"

namespace Tests
{
    using namespace Testing;
    using namespace Core;
    using namespace Behaviors;
    using namespace Exceptions;
    
    void PlaceableTest::setup() {
        this->name = "Placeable";
        trigonometry = new RealtimeTrigonometry();
        Test::setup();
    }
    
    void PlaceableTest::teardown() {
        Test::teardown();
        delete trigonometry;
    }
    
    void PlaceableTest::runtest(string name, PlaceableTestMethod method) {
        TestRunner<PlaceableTest, PlaceableTestMethod>(name, this, method).run();
    }
    
    void PlaceableTest::constructor_Empty_Test() {
        Placeable placeable;
        assert.areEqual(placeable.getLocation().getX(), 0.0);
        assert.areEqual(placeable.getLocation().getY(), 0.0);
    }
    
    void PlaceableTest::constructor_XY_Test() {
        Placeable placeable(1.23,4.56);
        assert.areEqual(placeable.getLocation().getX(), 1.23);
        assert.areEqual(placeable.getLocation().getY(), 4.56);
    }
    
    void PlaceableTest::constructor_V_Test() {
        Vector2D v(1.23, 4.56);
        Placeable placeable(v);
        assert.areEqual(placeable.getLocation().getX(), 1.23);
        assert.areEqual(placeable.getLocation().getY(), 4.56);
    }
    
    void PlaceableTest::constructor_Trigo_Test() {
        Placeable placeable(trigonometry);
        assert.areEqual(placeable.getLocation().getX(), 0.0);
        assert.areEqual(placeable.getLocation().getY(), 0.0);
    }
    
    void PlaceableTest::constructor_TrigoNull_Test() {
        try {
            Placeable placeable(NULL);
            
        } catch (NullReferenceException &ex) {
            assert.isTrue(true);
        }
    }
    
    void PlaceableTest::constructor_TrigoXY_Test() {
        Placeable placeable(1.23,4.56, trigonometry);
        assert.areEqual(placeable.getLocation().getX(), 1.23);
        assert.areEqual(placeable.getLocation().getY(), 4.56);
    }
    
    void PlaceableTest::constructor_TrigoV_Test() {
        Vector2D v(1.23, 4.56, trigonometry);
        Placeable placeable(v);
        assert.areEqual(placeable.getLocation().getX(), 1.23);
        assert.areEqual(placeable.getLocation().getY(), 4.56);
    }
    
    
    void PlaceableTest::getDisplacement_V_Test() {
        Placeable placeable(1000,1000);
        Vector2D d(200,300);
        Vector2D v = placeable.getDisplacement(d);
        Vector2D r(800,700);
        assert.areEqual(v, r);
    }
    void PlaceableTest::getDisplacement_XY_Test() {
        Placeable placeable(1000,1000);
        Vector2D v = placeable.getDisplacement(200,300);
        Vector2D r(800,700);
        assert.areEqual(v, r);
    }
    void PlaceableTest::setLocation_V_Test(){
        
        Placeable placeable;
        Vector2D v(1.23,4.56);
        placeable.setLocation(v);
        
        assert.areEqual(placeable.getLocation(), v);
    }
    void PlaceableTest::setLocation_XY_Test(){
        
        Placeable placeable;
        placeable.setLocation(1.23,4.56);
        
        assert.areEqual(placeable.getLocation().getX(), 1.23);
        assert.areEqual(placeable.getLocation().getY(), 4.56);
    }
    void PlaceableTest::addLocation_V_Test(){
        Placeable placeable(10,20);
        Vector2D v(1.23, 4.56);
        placeable.addLocation(v);
        
        assert.areEqual(placeable.getLocation().getX(), 11.23);
        assert.areEqual(placeable.getLocation().getY(), 24.56);
    }
    void PlaceableTest::addLocation_XY_Test(){
        Placeable placeable(10,20);
        placeable.addLocation(1.23, 4.56);
        
        assert.areEqual(placeable.getLocation().getX(), 11.23);
        assert.areEqual(placeable.getLocation().getY(), 24.56);
    }
    
    void PlaceableTest::run() {
        runtest("constructor_Empty_Test------", &PlaceableTest::constructor_Empty_Test);
        runtest("constructor_XY_Test---------", &PlaceableTest::constructor_XY_Test);
        runtest("constructor_V_Test----------", &PlaceableTest::constructor_V_Test);
        runtest("constructor_Trigo_Test------", &PlaceableTest::constructor_Trigo_Test);
        runtest("constructor_TrigoNull_Test--", &PlaceableTest::constructor_TrigoNull_Test);
        runtest("constructor_TrigoXY_Test----", &PlaceableTest::constructor_TrigoXY_Test);
        runtest("constructor_TrigoV_Test-----", &PlaceableTest::constructor_TrigoV_Test);
        runtest("getDisplacement_V_Test------", &PlaceableTest::getDisplacement_V_Test);
        runtest("getDisplacement_XY_Test-----", &PlaceableTest::getDisplacement_XY_Test);
        runtest("setLocation_V_Test----------", &PlaceableTest::setLocation_V_Test);
        runtest("setLocation_XY_Test---------", &PlaceableTest::setLocation_XY_Test);
        runtest("addLocation_V_Test----------", &PlaceableTest::addLocation_V_Test);
        runtest("addLocation_XY_Test---------", &PlaceableTest::addLocation_XY_Test);
    }
}
