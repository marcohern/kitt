//
//  MemoizedTrigonometry.hpp
//  kitt
//
//  Created by Marco Hernandez on 1/07/17.
//  Copyright © 2017 Marco Hernandez. All rights reserved.
//

#ifndef MemoizedTrigonometry_hpp
#define MemoizedTrigonometry_hpp

#include <stdio.h>
#include <map>
#include "Trigonometry.hpp"

namespace Core {
    using namespace std;
    
    class MemoizedTrigonometry : public Trigonometry {
    private:
        map<double,double> sint;
        map<double,double> cost;
    public:
        MemoizedTrigonometry();
        ~MemoizedTrigonometry();
        
        double sin(double r);
        double cos(double r);
    };
}
#endif /* MemoizedTrigonometry_hpp */
