//
//  FileReader.hpp
//  kitt
//
//  Created by Marco Hernandez on 29/06/17.
//  Copyright © 2017 Marco Hernandez. All rights reserved.
//

#ifndef FileReader_hpp
#define FileReader_hpp

#include <stdio.h>
#include <string>
#include <SDL2/SDL.h>

#include "IReader.hpp"

namespace Content {
    using namespace std;
    
    class FileReader : public IReader {
    private:
        string root;
    public:
        FileReader(string root);
        
        void open();
        string readString(string path);
        SDL_Surface* readSurface(string path);
        void close();
    };
}

#endif /* FileReader_hpp */
