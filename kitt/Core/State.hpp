//
//  State.hpp
//  kitt
//
//  Created by Marco Hernandez on 1/07/17.
//  Copyright © 2017 Marco Hernandez. All rights reserved.
//

#ifndef State_hpp
#define State_hpp

#include <stdio.h>
#include "./Trigonometry.hpp"

namespace Core{
    class State {
    private:
        Trigonometry *trigonometry;
    public:
        State();
        virtual ~State();
        
        Trigonometry *getTrigonometry();
    };
}
#endif /* State_hpp */
