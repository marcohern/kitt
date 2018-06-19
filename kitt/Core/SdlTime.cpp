//
//  SdlTime.cpp
//  kitt
//
//  Created by Marco Hernandez on 2/07/17.
//  Copyright © 2017 Marco Hernandez. All rights reserved.
//

#include "SdlTime.hpp"
#include "SDL.h"

namespace Core {
    SdlTime::SdlTime()
    : Time() {
        double ticks = (double)SDL_GetTicks();
        double seconds = ticks/1000;
        this->setStart(seconds);
    }
    
    SdlTime::~SdlTime() {
        Time::~Time();
    }
    
    void SdlTime::update() {
        double ticks = (double)SDL_GetTicks();
        double seconds = ticks/1000;
        this->setNow(seconds);
    }
}
