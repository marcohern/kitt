//
//  SdlTime.hpp
//  kitt
//
//  Created by Marco Hernandez on 2/07/17.
//  Copyright © 2017 Marco Hernandez. All rights reserved.
//

#ifndef SdlTime_hpp
#define SdlTime_hpp

#include <stdio.h>
#include "Time.hpp"

namespace Core {
    class SdlTime : public Time {
    public:
        SdlTime();
        virtual ~SdlTime();
        
        void update();
    };
}
#endif /* SdlTime_hpp */
