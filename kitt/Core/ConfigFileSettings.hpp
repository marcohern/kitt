//
//  ConfigFileSettings.hpp
//  kitt
//
//  Created by Marco Hernandez on 6/07/17.
//  Copyright © 2017 Marco Hernandez. All rights reserved.
//

#ifndef ConfigFileSettings_hpp
#define ConfigFileSettings_hpp

#include <string>
#include "Settings.hpp"

namespace Core {
    class ConfigFileSettings : public Settings {
    private:
        string filename;
        
    public:
        ConfigFileSettings(const string &rootpath, const string &filename);
        
        ~ConfigFileSettings();
        
        void load();
        void save();
    };
}

#endif /* ConfigFileSettings_hpp */
