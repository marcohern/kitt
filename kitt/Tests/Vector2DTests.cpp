#include "./Vector2DTests.hpp"
#include "../Exceptions/AssertException.hpp"

namespace Tests {

	using namespace Exceptions;

	void Vector2DTests::setup() {
        this->name = "Vector2D";
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
			cout << this->name << "_" << name <<":OK" << endl;
		}
		catch (AssertException &ex) {
			cout << this->name << "_" << name << ":ERROR " << ex.getMessage() << endl;
		}
		catch (exception &ex) {
			cout << this->name << "_" << name << ":ERROR " << ex.what() << endl;
		}
		catch (...) {
			cout << this->name << "_" << name << ":UNKNOWN ERROR" << endl;
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
    
    void Vector2DTests::toString_Test() {
        Vector2D v(1.23, 4.56);
        assert.areEqual(v.toString(),"(1.23,4.56)");
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
    
    void Vector2DTests::add_vector_test() {
        Vector2D v1(1.234, 5.678);
        Vector2D v2(8.766, 4.322);
        
        v1.add(v2);
        Vector2D vr(10.00,10.00);
        assert.areEqual(v1, vr);
    }
    
    void Vector2DTests::sub_Test() {
        Vector2D v(2.56,1.28);
        v.sub(0.64, 0.32);
        
        Vector2D vr(1.92, 0.96);
        assert.areEqual(v, vr);
    }
    
    void Vector2DTests::sub_vector_Test() {
        Vector2D v1(2.56, 1.28);
        Vector2D v2(0.64, 0.32);
        
        v1.sub(v2);
        Vector2D vr(1.92, 0.96);
        assert.areEqual(v1, vr);
    }
    
    void Vector2DTests::magnitude_Test() {
        Vector2D v(3.0, 4.0);
        assert.areEqual(v.magnitude(), 5.0);
    }
    
    void Vector2DTests::multiply_Test() {
        Vector2D v(2.5, 7.5);
        v.multiply(2.0);
        Vector2D vr(5.0, 15.0);
        assert.areEqual(v, vr);
    }
    
    void Vector2DTests::divide_Test() {
        Vector2D v(2.5, 7.5);
        v.divide(2.0);
        Vector2D vr(1.25, 3.75);
        assert.areEqual(v, vr);
    }
    
    void Vector2DTests::dot_Test() {
        Vector2D v1(2.56, 1.28);
        Vector2D v2(0.64, 0.32);
        
        double d = v1.dot(v2);
        assert.areEqual(d, 2.048);
    }
    
    void Vector2DTests::angleBetween_Test() {
        
        Vector2D v1(3.0, 4.0);
        Vector2D v2(4.0, 3.0);
        
        double a = v1.angleBetween(v2);
        assert.areEqual(a, 0.96);
    }

	void Vector2DTests::run() {
        this->execute("constructor_Test--------", &Vector2DTests::constructor_Test);
        this->execute("constructor_vector_Test-", &Vector2DTests::constructor_vector_Test);
        this->execute("toString_Test-----------", &Vector2DTests::toString_Test);
		this->execute("setX_Test---------------", &Vector2DTests::setX_Test);
		this->execute("setY_Test---------------", &Vector2DTests::setY_Test);
		this->execute("set_Test----------------", &Vector2DTests::set_Test);
        this->execute("set_vector_Test---------", &Vector2DTests::set_vector_Test);
        this->execute("add_Test----------------", &Vector2DTests::add_Test);
        this->execute("add_vector_Test---------", &Vector2DTests::add_vector_test);
        this->execute("sub_Test----------------", &Vector2DTests::sub_Test);
        this->execute("sub_vector_Test---------", &Vector2DTests::sub_vector_Test);
        this->execute("magnitude_Test----------", &Vector2DTests::magnitude_Test);
        this->execute("multiply_Test-----------", &Vector2DTests::multiply_Test);
        this->execute("divide_Test-------------", &Vector2DTests::divide_Test);
        this->execute("dot_Test----------------", &Vector2DTests::dot_Test);
        this->execute("angleBetween_Test-------", &Vector2DTests::angleBetween_Test);
		

	}
}
