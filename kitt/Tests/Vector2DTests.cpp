#include "./Vector2DTests.hpp"
#include "../Exceptions/AssertException.hpp"

namespace Tests {

	using namespace Exceptions;

	void Vector2DTests::setup() {
        Test::setup();
	}

	void Vector2DTests::teardown() {
        Test::teardown();
	}

	void Vector2DTests::execute(string name, Vector2DTestMethod method) {
		try {
			this->setup();
			(this->*method)();
			this->teardown();
			cout << name <<":OK" << endl;
		}
		catch (AssertException &ex) {
			cout << name << ":ERROR " << ex.getMessage() << endl;
		}
		catch (exception &ex) {
			cout << name << ":ERROR " << ex.what() << endl;
		}
		catch (...) {
			cout << name << ":UNKNOWN ERROR" << endl;
		}

	}

	void Vector2DTests::constructor_Test() {
		Vector2D v(1.23, 4.56);
		assert.areEqual(v.getX(), 1.23);
		assert.areEqual(v.getY(), 4.56);
	}

	void Vector2DTests::constructor_vector_Test() {
		Vector2D v1(1.23, 4.56);
		Vector2D v2(v1);
		assert.areEqual(v2.getX(), 1.23);
		assert.areEqual(v2.getY(), 4.56);
	}

	void Vector2DTests::setX_Test() {
		Vector2D v(0, 0);
		v.setX(12.34);
		assert.areEqual(v.getX(), 12.34);
	}

	void Vector2DTests::setY_Test() {
		Vector2D v(0, 0);
		v.setY(4.321);
		assert.areEqual(v.getY(), 4.321);
	}

	void Vector2DTests::set_Test() {
		Vector2D v(0, 0);
		v.set(1.234,5.678);
		assert.areEqual(v.getX(), 1.234);
		assert.areEqual(v.getY(), 5.678);
	}

	void Vector2DTests::set_vector_Test() {
		Vector2D v1(1.234, 5.678);
		Vector2D v2;
		v2.set(v1);
		assert.areEqual(v1, v2);
	}

	void Vector2DTests::add_Test() {
		Vector2D v(1.234, 5.678);
		v.add(8.766, 4.322);
		assert.areEqual(v.getX(), 10.00);
		assert.areEqual(v.getY(), 10.00);
	}

	void Vector2DTests::run() {
		this->execute("Vector2DTests_constructor_Test--------", &Vector2DTests::constructor_Test);
		this->execute("Vector2DTests_constructor_vector_Test-", &Vector2DTests::constructor_vector_Test);
		this->execute("Vector2DTests_setX_Test---------------", &Vector2DTests::setX_Test);
		this->execute("Vector2DTests_setY_Test---------------", &Vector2DTests::setY_Test);
		this->execute("Vector2DTests_set_Test----------------", &Vector2DTests::set_Test);
		this->execute("Vector2DTests_set:vector_Test---------", &Vector2DTests::set_vector_Test);
		this->execute("Vector2DTests_add_Test----------------", &Vector2DTests::add_Test);
		

		

	}
}
