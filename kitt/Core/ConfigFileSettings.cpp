//
//  ConfigFileSettings.cpp
//  kitt
//
//  Created by Marco Hernandez on 6/07/17.
//  Copyright © 2017 Marco Hernandez. All rights reserved.
//

#include "ConfigFileSettings.hpp"

namespace Core {
    
    ConfigFileSettings::ConfigFileSettings(const string &rootpath, const string &filename)
    : Settings() {
        this->root = rootpath;
        this->filename = filename;
    }
    
    ConfigFileSettings::~ConfigFileSettings() {
        Settings::~Settings();
    }
    
    void ConfigFileSettings::load() {
        this->screen_width = 1280;
        this->screen_height = 720;
        this->fullscreen = false;
    }
    
    void ConfigFileSettings::save() {
        
    }
}
