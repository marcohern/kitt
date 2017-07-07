//
//  Settings.cpp
//  kitt
//
//  Created by Marco Hernandez on 6/07/17.
//  Copyright © 2017 Marco Hernandez. All rights reserved.
//

#include "Settings.hpp"

namespace Core {
    Settings::Settings() : contentpath("/content") {
        
    }
    
    Settings::~Settings() {
        
    }
    
    string Settings::getRoot() const {
        return this->root;
    }

	string Settings::getContentPath() const {
		return this->contentpath;
	}

	string Settings::getContentFullPath() const {
		return this->root + this->contentpath;
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
