//
//  Injector.hpp
//  kitt
//
//  Created by Marco Hernandez on 1/07/17.
//  Copyright © 2017 Marco Hernandez. All rights reserved.
//

#ifndef Injector_hpp
#define Injector_hpp

#include <stdio.h>
#include "./Trigonometry.hpp"
#include "./Time.hpp"

namespace Core {
    class Injector {
    private:
        static Injector *instance;
        Trigonometry *trigonometry;
        Time *time;
        
        Injector();
        
    public:
        ~Injector();
        static Injector *get();
        
        Trigonometry *getTrigonometry();
        Time *getTime();
    };
}
#endif /* Injector_hpp */
