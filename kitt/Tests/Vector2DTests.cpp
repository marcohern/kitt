#include "./Vector2DTests.hpp"
#include "../Exceptions/AssertException.hpp"
#include "../Exceptions/DivideByZeroException.hpp"
#include "../Testing/TestRunner.hpp"

namespace Tests {

	using namespace Exceptions;

	void Vector2DTests::setup() {
        this->name = "Vector2D";
        Test::setup();
	}

	void Vector2DTests::teardown() {
        Test::teardown();
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
    
    void Vector2DTests::add_vector_Test() {
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
    
    void Vector2DTests::divide_ByZero_Test() {
        Vector2D v(2.5, 7.5);
        try {
            v.divide(0.0);
        } catch (DivideByZeroException &ex) {
            assert.isTrue(true);
        }
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
    
    void Vector2DTests::runtest(string name, Vector2DTestMethod method) {
        TestRunner<Vector2DTests, Vector2DTestMethod>(name, this, method).run();
    }
    
    void Vector2DTests::op_positive_Test() {
        Vector2D v1(4.0, 5.0);
        Vector2D v2 = +v1;
        
        Vector2D vr(4.0, 5.0);
        assert.areEqual(v2, vr);
    }
    
    void Vector2DTests::op_negative_Test() {
        Vector2D v1(4.0, 5.0);
        Vector2D v2 = -v1;
        
        Vector2D vr(-4.0, -5.0);
        assert.areEqual(v2, vr);
    }
    
    void Vector2DTests::op_add_Test() {
        Vector2D v1(4.0, 5.0);
        Vector2D v2(6.0, 7.0);
        Vector2D v3 = v1 + v2;
        
        Vector2D vr(10.00, 12.00);
        assert.areEqual(v3, vr);
    }
    
    void Vector2DTests::op_sub_Test() {
        Vector2D v1(4.0, 5.0);
        Vector2D v2(2.0, 3.0);
        Vector2D v3 = v1 - v2;
        
        Vector2D vr(2.00, 2.00);
        assert.areEqual(v3, vr);
    }
    
    void Vector2DTests::op_multiply_s_Test() {
        Vector2D v1(1.23, 4.56);
        double s = 2.0;
        Vector2D v2 = v1 * s;
        
        Vector2D vr(2.46, 9.12);
        assert.areEqual(v2, vr);
    }
    
    void Vector2DTests::op_s_multiply_Test() {
        Vector2D v1(1.23, 4.56);
        double s = 2.0;
        Vector2D v2 = v1 * s;
        
        Vector2D vr(2.46, 9.12);
        assert.areEqual(v2, vr);
    }
    
    void Vector2DTests::op_dot_product_Test() {
        
        Vector2D v1(4.0, 5.0);
        Vector2D v2(2.0, 3.0);
        double r = v1 * v2;
        
        assert.areEqual(r, 23.00);
    }
    
    void Vector2DTests::op_div_Test() {
        
        Vector2D v1(1.23, 4.56);
        double s = 2.0;
        Vector2D v2 = v1 / s;
        
        Vector2D vr(0.615, 2.280);
        
        assert.areEqual(v2, vr);
    }
    
    void Vector2DTests::op_div_ByZero_Test(){
        
        Vector2D v1(1.23, 4.56);
        try {
            v1 / 0.0;
        } catch (DivideByZeroException &ex) {
            assert.isTrue(true);
        }
    }
    
	void Vector2DTests::run() {
        runtest("constructor_Test--------", &Vector2DTests::constructor_Test);
        runtest("constructor_vector_Test-", &Vector2DTests::constructor_vector_Test);
        runtest("toString_Test-----------", &Vector2DTests::toString_Test);
		runtest("setX_Test---------------", &Vector2DTests::setX_Test);
		runtest("setY_Test---------------", &Vector2DTests::setY_Test);
		runtest("set_Test----------------", &Vector2DTests::set_Test);
        runtest("set_vector_Test---------", &Vector2DTests::set_vector_Test);
        runtest("add_Test----------------", &Vector2DTests::add_Test);
        runtest("add_vector_Test---------", &Vector2DTests::add_vector_Test);
        runtest("sub_Test----------------", &Vector2DTests::sub_Test);
        runtest("sub_vector_Test---------", &Vector2DTests::sub_vector_Test);
        runtest("magnitude_Test----------", &Vector2DTests::magnitude_Test);
        runtest("multiply_Test-----------", &Vector2DTests::multiply_Test);
        runtest("divide_Test-------------", &Vector2DTests::divide_Test);
        runtest("divide_ByZero_Test------", &Vector2DTests::divide_ByZero_Test);
        runtest("dot_Test----------------", &Vector2DTests::dot_Test);
        runtest("angleBetween_Test-------", &Vector2DTests::angleBetween_Test);
        runtest("op_positive_Test--------", &Vector2DTests::op_positive_Test);
        runtest("op_negative_Test--------", &Vector2DTests::op_negative_Test);
        runtest("op_add_Test-------------", &Vector2DTests::op_add_Test);
        runtest("op_sub_Test-------------", &Vector2DTests::op_sub_Test);
        runtest("op_multiply_s_Test------", &Vector2DTests::op_multiply_s_Test);
        runtest("op_s_multiply_Test------", &Vector2DTests::op_s_multiply_Test);
        runtest("op_dot_product_Test-----", &Vector2DTests::op_dot_product_Test);
        runtest("op_div_Test-------------", &Vector2DTests::op_div_Test);
        runtest("op_div_ByZero_Test------", &Vector2DTests::op_div_ByZero_Test);
        
	}
}
