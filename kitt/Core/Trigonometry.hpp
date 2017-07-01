//
//  Trigonometry.hpp
//  kitt
//
//  Created by Marco Hernandez on 1/07/17.
//  Copyright © 2017 Marco Hernandez. All rights reserved.
//

#ifndef Trigonometry_hpp
#define Trigonometry_hpp

#include <stdio.h>
#include <map>


//TRIGO_MAX = int(PI << 10)

namespace Core {
    using namespace std;
    
    class Trigonometry {
    private:
        map<double,double> sint;
        map<double,double> cost;
    public:
        Trigonometry();
        virtual ~Trigonometry();
        
        double sin(double r);
        double cos(double r);
        
        void print_cos();
        void print_sin();
    };
}
#endif /* Trigonometry_hpp */
