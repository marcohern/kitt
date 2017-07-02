//
//  Matrix.hpp
//  kitt
//
//  Created by Marco Hernandez on 29/06/17.
//  Copyright © 2017 Marco Hernandez. All rights reserved.
//

#ifndef Matrix_hpp
#define Matrix_hpp

#include <stdio.h>
#include "Object.hpp"

namespace Core {
    class Matrix : public Object {
    private:
        int n, m;
        double **v;
        
        void allocate(int n, int m);
        void validate_size(int n, int m) const;
        void validate_access(int i, int j) const;
        void validate_match_size(const Matrix &mx) const;
        
    public:
        Matrix(int n, int m, double v[]);
        Matrix(int n, int m);
        
        int cols() const;
        int rows() const;
        
        double get(int i, int j) const;
        void set(int i, int j, double value);
        
        void add(const Matrix &mx);
        void sub(const Matrix &mx);
        
        double* operator [] (int i) const;
        friend Matrix operator + (const Matrix &mx);
        friend Matrix operator - (const Matrix &mx);
        
        
        virtual string toString();
    };
}
#endif /* Matrix_hpp */
