//
//  MatrixTests.cpp
//  kitt
//
//  Created by Marco Hernandez on 2/07/17.
//  Copyright © 2017 Marco Hernandez. All rights reserved.
//

#include "MatrixTests.hpp"
#include "../Core/Matrix.hpp"
#include "../Testing/TestRunner.hpp"
#include "../Exceptions/OutOfRangeException.hpp"
#include "../Exceptions/MismatchException.hpp"

namespace Tests {
    using namespace std;
    using namespace Core;
    using namespace Testing;
    using namespace Exceptions;
    
    void MatrixTests::setup() {
        this->name = "Matrix";
        Test::setup();
    }
    
    void MatrixTests::teardown() {
        Test::teardown();
    }
    
    void MatrixTests::constructor_Test() {
        Matrix m(3,4);
        assert.areEqual(m.cols(), 3);
        assert.areEqual(m.rows(), 4);
    }
    
    void MatrixTests::constructor_zero_Test() {
        Matrix m(2,2);
        assert.areEqual(m.get(0,0), 0.0);
        assert.areEqual(m.get(0,1), 0.0);
        assert.areEqual(m.get(1,0), 0.0);
        assert.areEqual(m.get(1,1), 0.0);
    }
    
    void MatrixTests::constructor_value_Test() {
        double values[4] = {
            1.0, 2.0,
            3.0, 4.0
        };
        
        Matrix m(2,2, values);
        assert.areEqual(m.cols(), 2);
        assert.areEqual(m.rows(), 2);
        
        assert.areEqual(m.get(0,0), 1.0);
        assert.areEqual(m.get(0,1), 2.0);
        assert.areEqual(m.get(1,0), 3.0);
        assert.areEqual(m.get(1,1), 4.0);
    }
    
    void MatrixTests::constructor_invalid_size_Test() {
        try {
            Matrix m(3,-1);
        } catch (OutOfRangeException &ex) {
            assert.isTrue(true);
        }
    }
    
    void MatrixTests::get_outofrange_Test() {
        Matrix m(3,3);
        try {
            m.get(4,5);
        } catch (OutOfRangeException &ex) {
            assert.isTrue(true);
        }
    }
    
    void MatrixTests::set_Test() {
        double values[4] = {
            1.0, 2.0,
            3.0, 4.0
        };
        
        Matrix m(2,2, values);
        m.set(0,1, 9.0);
        assert.areEqual(m.get(0,1), 9.0);
    }
    
    void MatrixTests::set_outofrange_Test() {
        Matrix m(3,3);
        try {
            m.set(6,7, 1.0);
        } catch (OutOfRangeException &ex) {
            assert.isTrue(true);
        }
    }
    
    void MatrixTests::add_Test() {
        double a[4] = {
            1.0, 2.0,
            3.0, 4.0
        };
        double b[4] = {
            4.0, 3.0,
            2.0, 1.0
        };
        Matrix ma(2, 2, a);
        Matrix mb(2, 2, b);
        ma.add(mb);
        assert.areEqual(ma.get(0,0), 5.0);
        assert.areEqual(ma.get(0,1), 5.0);
        assert.areEqual(ma.get(1,0), 5.0);
        assert.areEqual(ma.get(1,1), 5.0);
    }
    
    void MatrixTests::add_mismatch_Test() {
        double a[4] = {
            1.0, 2.0,
            3.0, 4.0
        };
        double b[6] = {
            4.0, 3.0, 5.0,
            2.0, 1.0, 0.0
        };
        Matrix ma(2, 2, a);
        Matrix mb(3, 2, b);
        try {
            ma.add(mb);
        } catch(MismatchException &ex) {
            assert.isTrue(true);
        }
    }
    
    void MatrixTests::sub_Test() {
        double a[4] = {
            1.0, 2.0,
            3.0, 4.0
        };
        double b[4] = {
            4.0, 3.0,
            2.0, 1.0
        };
        Matrix ma(2, 2, a);
        Matrix mb(2, 2, b);
        ma.sub(mb);
        assert.areEqual(ma.get(0,0), -3.0);
        assert.areEqual(ma.get(0,1), -1.0);
        assert.areEqual(ma.get(1,0),  1.0);
        assert.areEqual(ma.get(1,1),  3.0);
    }
    
    void MatrixTests::sub_mismatch_Test() {
        double a[4] = {
            1.0, 2.0,
            3.0, 4.0
        };
        double b[6] = {
            4.0, 3.0, 5.0,
            2.0, 1.0, 0.0
        };
        Matrix ma(2, 2, a);
        Matrix mb(3, 2, b);
        try {
            ma.sub(mb);
        } catch(MismatchException &ex) {
            assert.isTrue(true);
        }
    }
    
    void MatrixTests::toString_Test() {
        double values[4] = {
            1.23456, 2.34567,
            3.45678, 4.56789
        };
        Matrix m(2,2, values);
        string r("[ 1.23456 , 2.34567 ]\n[ 3.45678 , 4.56789 ]\n");
        assert.areEqual(r, m.toString());
    }
    
    void MatrixTests::op_access_Test() {
        double values[4] = {
            1.0, 2.0,
            3.0, 4.0
        };
        
        Matrix m(2,2, values);
        assert.areEqual(m.cols(), 2);
        assert.areEqual(m.rows(), 2);
        
        assert.areEqual(m[0][0], 1.0);
        assert.areEqual(m[0][1], 2.0);
        assert.areEqual(m[1][0], 3.0);
        assert.areEqual(m[1][1], 4.0);
    }
    void MatrixTests::op_positive_Test() {
        
        double values[4] = {
            1.0, 2.0,
            3.0, 4.0
        };
        
        Matrix m1(2,2, values);
        Matrix m2 = +m1;
        
        assert.areEqual(m2[0][0], 1.0);
        assert.areEqual(m2[0][1], 2.0);
        assert.areEqual(m2[1][0], 3.0);
        assert.areEqual(m2[1][1], 4.0);
    }
    
    void MatrixTests::op_negative_Test() {
        double values[4] = {
            1.0, 2.0,
            3.0, 4.0
        };
        
        Matrix m1(2,2, values);
        Matrix m2 = -m1;
        
        assert.areEqual(m2[0][0], -1.0);
        assert.areEqual(m2[0][1], -2.0);
        assert.areEqual(m2[1][0], -3.0);
        assert.areEqual(m2[1][1], -4.0);
    }
    
    void MatrixTests::runtest(string name, MatrixTestsMethod method) {
        TestRunner<MatrixTests, MatrixTestsMethod>
            (name, this, method).run();
    }
    
    void MatrixTests::run() {
        runtest("constructor_Test--------------", &MatrixTests::constructor_Test);
        runtest("constructor_zero_Test---------", &MatrixTests::constructor_zero_Test);
        runtest("constructor_value_Test--------", &MatrixTests::constructor_value_Test);
        runtest("constructor_invalid_size_Test-", &MatrixTests::constructor_invalid_size_Test);
        runtest("get_outofrange_Test-----------", &MatrixTests::get_outofrange_Test);
        runtest("set_Test----------------------", &MatrixTests::set_Test);
        runtest("set_outofrange_Test-----------", &MatrixTests::set_outofrange_Test);
        runtest("add_Test----------------------", &MatrixTests::add_Test);
        runtest("sub_mismatch_Test-------------", &MatrixTests::sub_mismatch_Test);
        runtest("sub_Test----------------------", &MatrixTests::sub_Test);
        runtest("add_mismatch_Test-------------", &MatrixTests::add_mismatch_Test);
        runtest("toString_Test-----------------", &MatrixTests::toString_Test);
        runtest("op_access_Test----------------", &MatrixTests::op_access_Test);
        runtest("op_positive_Test--------------", &MatrixTests::op_positive_Test);
        runtest("op_negative_Test--------------", &MatrixTests::op_negative_Test);
    }
}
