//
//  IReader.hpp
//  kitt
//
//  Created by Marco Hernandez on 29/06/17.
//  Copyright © 2017 Marco Hernandez. All rights reserved.
//

#ifndef IReader_hpp
#define IReader_hpp

#include <stdio.h>
#include <string>
#include <SDL2/SDL.h>

namespace Content {

    using namespace std;

    class IReader {
    public:
        virtual void open() = 0;
        virtual string readString(string path) = 0;
        virtual SDL_Surface* readSurface(string path) = 0;
        virtual void close() = 0;
    };
    
}
#endif /* IReader_hpp */
