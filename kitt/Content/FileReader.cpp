//
//  FileReader.cpp
//  kitt
//
//  Created by Marco Hernandez on 29/06/17.
//  Copyright © 2017 Marco Hernandez. All rights reserved.
//

#include "../SDL.h"
#include <stdio.h>
#include "../Graphics/Texture.hpp"
#include "../Graphics/TextureFactory.hpp"
#include "../Core/Path.hpp"
#include "FileReader.hpp"

namespace Content {
    
    using namespace std;
	using namespace Core;
	using namespace Graphics;
    
	FileReader::FileReader() {
		this->root = Path::get()->getRoot();
	}

    FileReader::FileReader(const string &root) {
        this->root = root;
    }

	bool FileReader::exists(const string &path) {
		string fullpath = this->root;
		fullpath.append(path);
		if (FILE *f = fopen(fullpath.c_str(), "r")) {
			fclose(f);
			return true;
		}
		return false;
	}
    
    void FileReader::open() {
        //nothing to do
    }
    
    string FileReader::readString(const string &path) {
        return "";
    }
    
    Texture* FileReader::readSurface(const string &path) {
		string fullpath = this->root;
		fullpath.append(path);
		return TextureFactory::load(fullpath.c_str());
    }
    
    void FileReader::close() {
		//nothing to do
    }
    
}
