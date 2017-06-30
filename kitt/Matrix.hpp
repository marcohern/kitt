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

namespace Core {
    class Matrix {
    private:
        int n, m;
        double **v;
        
        void allocate(int n, int m);
        
    public:
        Matrix(int n, int m, double **v);
        Matrix(int n, int m);
        
        double get(int i, int j);
        void set(int i, int j, double value);
        
        void add(const Matrix &mx);
    };
}
#endif /* Matrix_hpp */
