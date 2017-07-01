//
//  RealtimeTrigonometry.hpp
//  kitt
//
//  Created by Marco Hernandez on 1/07/17.
//  Copyright © 2017 Marco Hernandez. All rights reserved.
//

#ifndef RealtimeTrigonometry_hpp
#define RealtimeTrigonometry_hpp

#include <stdio.h>
#include "Trigonometry.hpp"

namespace Core {
    class RealtimeTrigonometry : public Trigonometry {
    public:
        RealtimeTrigonometry();
        ~RealtimeTrigonometry();
        
        double sin(double r);
        double cos(double r);
    };
}

#endif /* RealtimeTrigonometry_hpp */
