//
//  Settings.cpp
//  kitt
//
//  Created by Marco Hernandez on 6/07/17.
//  Copyright © 2017 Marco Hernandez. All rights reserved.
//

#include "Settings.hpp"

namespace Core {
    Settings::Settings() {
        
    }
    
    Settings::~Settings() {
        
    }
    
    string Settings::getRoot() const {
        return this->root;
    }
    
    int Settings::getScreenWidth() const {
        return this->screen_width;
    }
    
    int Settings::getScreenHeight() const {
        return this->screen_height;
    }
    
    bool Settings::getFullscreen() const {
        return this->fullscreen;
    }
}
