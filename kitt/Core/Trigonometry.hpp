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

namespace Core {
    using namespace std;
    
    class Trigonometry {
    public:
        Trigonometry();
        virtual ~Trigonometry();
        
        virtual double sin(double r) = 0;
        virtual double cos(double r) = 0;
    };
}
#endif /* Trigonometry_hpp */
