//
//  Time.hpp
//  kitt
//
//  Created by Marco Hernandez on 2/07/17.
//  Copyright © 2017 Marco Hernandez. All rights reserved.
//

#ifndef Time_hpp
#define Time_hpp

#include <stdio.h>

namespace Core {
    class Time {
    protected:
        double start;
        double prev;
        double now;
        double delta;
        
        void setStart(double start);
        void setNow(double now);
    public:
        Time();
        
        double getStart();
        double getNow();
        double getDelta();
        
        virtual void update() = 0;
    };
}
#endif /* Time_hpp */
