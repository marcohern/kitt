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
#include "../constants.hpp"

namespace Core {
    using namespace std;
    
    class MemoizedTrigonometry : public Trigonometry {
    private:
        static const double novalue;
        double sint[TRIGO_TABLE_SIZE];
        double cost[TRIGO_TABLE_SIZE];
        
    public:
        MemoizedTrigonometry();
        ~MemoizedTrigonometry();
        
        double sin(double r);
        double cos(double r);
        
        inline int index(double r);
        inline double radian(int i);
    };
}
#endif /* MemoizedTrigonometry_hpp */
