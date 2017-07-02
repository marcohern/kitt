//
//  Matrix.cpp
//  kitt
//
//  Created by Marco Hernandez on 29/06/17.
//  Copyright © 2017 Marco Hernandez. All rights reserved.
//
#include <iostream>
#include <iomanip>
#include <sstream>
#include "Matrix.hpp"
#include "../Exceptions/OutOfRangeException.hpp"
#include "../Exceptions/MismatchException.hpp"

namespace Core {
    using namespace std;
    using namespace Exceptions;
    
    void Matrix::allocate(int n, int m) {
        this->n = n;
        this->m = m;
        v = new double*[n];
        for (int i=0;i<n;i++) {
            v[i] = new double[m];
            for (int j=0;j<m;j++) {
                v[i][j] = 0.0;
            }
        }
    }
    
    void Matrix::validate_size(int n, int m) const {
        if (n<=0 || m<=0) throw OutOfRangeException("Matrix size not allowed");
    }
    
    void Matrix::validate_access(int i, int j) const {
        if (i<0 || i>=n || j<0 || j>=n) throw OutOfRangeException("Matrix index out of range");
    }
    
    void Matrix::validate_match_size(const Matrix &mx) const {
        if (n!=mx.n || m!=mx.m) throw MismatchException("Matrix sizes must match");
    }
    
    Matrix::Matrix(int n, int m, double v[]) {
        this->validate_size(n, m);
        this->allocate(n, m);
        for (int i=0;i<n;i++) {
            for (int j=0;j<m;j++) {
                this->v[i][j] = v[i*n + j];
            }
        }
    }
    
    Matrix::Matrix(int n, int m) {
        this->validate_size(n, m);
        this->allocate(n, m);
    }
    
    int Matrix::cols() const {
        return n;
    }
    
    int Matrix::rows() const {
        return m;
    }
    
    double Matrix::get(int i, int j) const {
        this->validate_access(i, j);
        return v[i][j];
    }
    
    void Matrix::set(int i, int j, double value) {
        this->validate_access(i, j);
        v[i][j] = value;
    }
    
    void Matrix::add(const Matrix &mx) {
        this->validate_match_size(mx);
        for (int i=0;i<n;i++) {
            for (int j=0;j<n;j++) {
                v[i][j] += mx.get(i,j);
            }
        }
    }
    
    void Matrix::sub(const Matrix &mx) {
        this->validate_match_size(mx);
        for (int i=0;i<n;i++) {
            for (int j=0;j<n;j++) {
                v[i][j] -= mx.get(i,j);
            }
        }
    }
    
    string Matrix::toString() {
        stringstream ss;
        for (int i=0;i<n;i++) {
            for (int j=0;j<m;j++) {
                ss<<((j==0) ? "[ " :" , ");
                ss<<setw(7)<<v[i][j];
            }
            ss<<" ]"<<endl;
        }
        return ss.str();
    }
    
    double *Matrix::operator[](int i) const {
        if (i<0 || i>=n) throw OutOfRangeException("Matrix index out of range");
        return v[i];
    }
    
    Matrix operator + (const Matrix &mx) {
        Matrix r(mx.cols(), mx.rows());
        r.add(mx);
        return r;
    }
    
    Matrix operator - (const Matrix &mx) {
        Matrix r(mx.cols(), mx.rows());
        r.sub(mx);
        return r;
    }
}
