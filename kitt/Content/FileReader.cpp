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
#include "../Graphics/SdlTexture.hpp"
#include "../Core/Path.hpp"
#include "FileReader.hpp"
#include "../constants.hpp"
#include "../Graphics/Renderer.hpp"

namespace Content {
    
    using namespace std;
	using namespace Core;
	using namespace Graphics;
    
	FileReader::FileReader(const string &path, Renderer *renderer, bool fullpath) {
		this->renderer = renderer;
		if (fullpath) {
			this->root = path;
		} else {
			this->root = Path::root();
			this->root.append(new char[2] { DS, '\0' });
			this->root.append(path);
		}
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
		SDL_Surface *surf= IMG_Load(fullpath.c_str());
		SdlTexture *txt = new SdlTexture((SdlRenderer *)renderer, surf);
		return txt;
    }
    
    void FileReader::close() {
		//nothing to do
    }
    
}
