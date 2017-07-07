//
//  Settings.hpp
//  kitt
//
//  Created by Marco Hernandez on 6/07/17.
//  Copyright © 2017 Marco Hernandez. All rights reserved.
//

#ifndef Settings_hpp
#define Settings_hpp

#include <string>

namespace Core {
    using namespace std;
    
    class Settings {
    protected:
        string root;
        int screen_width;
        int screen_height;
        bool fullscreen;
        
    public:
        Settings();
        virtual ~Settings();
        
        virtual void load() = 0;
        virtual void save() = 0;
        
        string getRoot() const;
        int getScreenWidth() const;
        int getScreenHeight() const;
        bool getFullscreen() const;
        
        
    };
}
#endif /* Settings_hpp */
