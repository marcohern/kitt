//
//  FileReader.cpp
//  kitt
//
//  Created by Marco Hernandez on 29/06/17.
//  Copyright © 2017 Marco Hernandez. All rights reserved.
//

#include "FileReader.hpp"

namespace Content {
    
    using namespace std;
    
    FileReader::FileReader(string root) {
        this->root = root;
    }
    
    void FileReader::open() {
        
    }
    
    string FileReader::readString(string path) {
        return "";
    }
    
    SDL_Surface* FileReader::readSurface(string path) {
        return NULL;
    }
    
    void FileReader::close() {
        
    }
    
}
