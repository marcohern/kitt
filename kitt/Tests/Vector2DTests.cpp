#include "./Vector2DTest.hpp"
#include "../Exceptions/AssertException.hpp"

namespace Tests {

	using namespace Exceptions;

	void Vector2DTests::setup() {

	}

	void Vector2DTests::teardown() {

	}

	void Vector2DTests::execute(string name, Vector2DTestMethod method) {
		try {
			this->setup();
			(this->*method)();
			this->teardown();
			cout << name << ":" <<"OK" << endl;
		}
		catch (AssertException &ex) {
			cout << "ERROR in " << name << ":" << ex.getMessage() << endl;
		}

	}

	void Vector2DTests::constructor_Test() {
		Vector2D v(1.23, 4.56);
		assert.areEqual(v.getX(), 1.23);
		assert.areEqual(v.getY(), 5.56);
	}

	void Vector2DTests::setX_Test() {
		Vector2D v(0, 0);
		v.setX(123);
		assert.areEqual(v.getX(), 123);
	}

	void Vector2DTests::setY_Test() {
		Vector2D v(0, 0);
		v.setY(321);
		assert.areEqual(v.getY(), 321);
	}

	void Vector2DTests::run() {
		this->execute("Vector2DTests_constructor_Test", &Vector2DTests::constructor_Test);
		this->execute("Vector2DTests_setX_Test", &Vector2DTests::setX_Test);
		this->execute("Vector2DTests_setY_Test", &Vector2DTests::setY_Test);

	}
}