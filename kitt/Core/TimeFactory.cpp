//
//  TimeFactory.cpp
//  kitt
//
//  Created by Marco Hernandez on 2/07/17.
//  Copyright © 2017 Marco Hernandez. All rights reserved.
//

#include "TimeFactory.hpp"
#include "SdlTime.hpp"

namespace Core {
    Time *TimeFactory::create() {
        return new SdlTime();
    }
}
