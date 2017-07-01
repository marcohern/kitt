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

namespace Core {
    class Injector {
    private:
        static Injector *instance;
        Trigonometry *trigonometry;
        
        Injector();
        
    public:
        ~Injector();
        static Injector *get();
        
        Trigonometry *getTrigonometry();
    };
}
#endif /* Injector_hpp */
