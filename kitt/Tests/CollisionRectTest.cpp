
#include "CollisionRectTest.hpp"
#include "../Testing/TestRunner.hpp"
#include "../Core/RealtimeTrigonometry.hpp"
#include "../Collisions/CollisionRect.hpp"
#include "../Collisions/CollisionCircle.hpp"

namespace Tests {
	using namespace Core;
	using namespace Collisions;
	using namespace Testing;

	void CollisionRectTest::setup() {
		this->name = "CollisionRect";
		trigonometry = new RealtimeTrigonometry();
		Test::setup();
	}

	void CollisionRectTest::teardown() {
		delete trigonometry;
		Test::teardown();
	}

	void CollisionRectTest::runtest(string name, CollisionRectTestMethod method) {
		TestRunner<CollisionRectTest, CollisionRectTestMethod>(name, this, method).run();
	}

	void CollisionRectTest::constructor_Test() {
		CollisionRect rect;
		assert.areEqual(rect.getLocation(), Vector2D(0, 0));
		assert.areEqual(rect.getSize(), Vector2D(0, 0));
	}

	void CollisionRectTest::constructor_S_Test() {
		CollisionRect rect(Vector2D(5.0, 5.0));
		assert.areEqual(rect.getSize(), Vector2D(5.0, 5.0));
	}

	void CollisionRectTest::constructor_LS_Test() {
		CollisionRect rect(Vector2D(10.0, 15.0), Vector2D(5.0, 5.0));
		assert.areEqual(rect.getLocation(), Vector2D(10.0, 15.0));
		assert.areEqual(rect.getSize(), Vector2D(5.0, 5.0));
	}

	void CollisionRectTest::constructor_T_Test() {
		CollisionRect rect(trigonometry);
		assert.areEqual(rect.getLocation(), Vector2D(0, 0));
		assert.areEqual(rect.getSize(), Vector2D(0, 0));
	}
	void CollisionRectTest::constructor_ST_Test() {
		CollisionRect rect(Vector2D(5.0, 5.0), trigonometry);
		assert.areEqual(rect.getSize(), Vector2D(5.0, 5.0));
	}

	void CollisionRectTest::constructor_LST_Test() {
		CollisionRect rect(Vector2D(10.0, 15.0), Vector2D(5.0, 5.0), trigonometry);
		assert.areEqual(rect.getLocation(), Vector2D(10.0, 15.0));
		assert.areEqual(rect.getSize(), Vector2D(5.0, 5.0));
	}

	void CollisionRectTest::getLocation_Test() {
		CollisionRect rect(Vector2D(10.0, 15.0), Vector2D(5.0, 5.0));
		assert.areEqual(rect.getLocation(), Vector2D(10.0, 15.0));
	}
	void CollisionRectTest::getSize_Test() {
		CollisionRect rect(Vector2D(10.0, 15.0), Vector2D(5.0, 5.0));
		assert.areEqual(rect.getSize(), Vector2D(5.0, 5.0));
	}

	void CollisionRectTest::setLocation_Test() {
		CollisionRect rect;
		rect.setLocation(Vector2D(12.3, 45.6));
		assert.areEqual(rect.getLocation(), Vector2D(12.3, 45.6));
	}

	void CollisionRectTest::addLocation_Test() {
		CollisionRect rect;
		rect.setLocation(Vector2D(12.3, 45.6));
		rect.addLocation(Vector2D(78.9, 01.2));
		assert.areClose(rect.getLocation(), Vector2D(91.2, 46.8), 4);
	}

	void CollisionRectTest::intersectsSensor_Test() {
		CollisionRect rect(Vector2D(5, 5));
		Vector2D sensor(6, 6);

		assert.isFalse(rect.intersectsSensor(sensor));
		sensor.add(-1, -1);
		assert.isTrue(rect.intersectsSensor(sensor));
		sensor.add(-5, -5);
		assert.isTrue(rect.intersectsSensor(sensor));
		sensor.add(-5, -5);
		assert.isFalse(rect.intersectsSensor(sensor));
		sensor.set(2, 3);
		assert.isTrue(rect.intersectsSensor(sensor));
		sensor.set(7, 8);
		assert.isFalse(rect.intersectsSensor(sensor));
		sensor.set(12, 3);
		assert.isFalse(rect.intersectsSensor(sensor));
	}

	void CollisionRectTest::getCenter_Test() {
		CollisionRect rect(Vector2D(5, 5), Vector2D(5, 5));
		assert.areEqual(rect.getCenter(), Vector2D(7.5, 7.5));
	}

	void CollisionRectTest::getClosestPoint_Test() {
		CollisionRect rect(Vector2D(5, 5), Vector2D(5, 5));
		Vector2D sensor(2, 3);
		assert.areEqual(rect.getClosestPoint(sensor), Vector2D(5, 5));
		sensor.set(6, 6);
		assert.areEqual(rect.getClosestPoint(sensor), Vector2D(6, 6));
		sensor.set(7.5, 0);
		assert.areEqual(rect.getClosestPoint(sensor), Vector2D(7.5, 5));
		sensor.set(0, 7.5);
		assert.areEqual(rect.getClosestPoint(sensor), Vector2D(5, 7.5));
	}

	void CollisionRectTest::collidesWith_Test() {
		CollisionRect rect1(Vector2D(5, 5), Vector2D(5, 5));
		CollisionRect rect2(Vector2D(20, 20), Vector2D(5, 5));
		CollisionCircle circle(Vector2D(5, 5), 5);

		assert.isFalse(rect1.collidesWith(rect2));
		assert.isFalse(rect2.collidesWith(rect1));
		rect1.setLocation(Vector2D(17,17));
		
		assert.isTrue(rect1.collidesWith(rect2));
		assert.isTrue(rect2.collidesWith(rect1));

		assert.isFalse(rect1.collidesWith(circle));
		assert.isFalse(circle.collidesWith(rect1));
		circle.setCenter(Vector2D(15, 15));
		assert.isFalse(rect1.collidesWith(circle));
		assert.isFalse(circle.collidesWith(rect1));
		circle.setCenter(Vector2D(16, 16));
		assert.isFalse(rect1.collidesWith(circle));
	}

	void CollisionRectTest::run() {
		runtest("constructor_Test------", &CollisionRectTest::constructor_Test);
		runtest("constructor_S_Test----", &CollisionRectTest::constructor_S_Test);
		runtest("constructor_LS_Test---", &CollisionRectTest::constructor_LS_Test);
		runtest("constructor_T_Test----", &CollisionRectTest::constructor_T_Test);
		runtest("constructor_ST_Test---", &CollisionRectTest::constructor_ST_Test);
		runtest("constructor_LST_Test--", &CollisionRectTest::constructor_LST_Test);

		runtest("getLocation_Test------", &CollisionRectTest::getLocation_Test);
		runtest("getSize_Test----------", &CollisionRectTest::getSize_Test);
		runtest("setLocation_Test------", &CollisionRectTest::setLocation_Test);
		runtest("addLocation_Test------", &CollisionRectTest::addLocation_Test);

		runtest("intersectsSensor_Test-", &CollisionRectTest::intersectsSensor_Test);
		runtest("getCenter_Test--------", &CollisionRectTest::getCenter_Test);
		runtest("getClosestPoint_Test--", &CollisionRectTest::getClosestPoint_Test);
		runtest("collidesWith_Test-----", &CollisionRectTest::collidesWith_Test);
	}
}