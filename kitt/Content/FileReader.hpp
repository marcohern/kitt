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
#include "../SDL.h"
#include "IReader.hpp"
#include "../Graphics/Texture.hpp"
#include "../Graphics/Renderer.hpp"

namespace Content {
    using namespace std;
	using namespace Graphics;
    
    class FileReader : public IReader {
    private:
		Renderer *renderer;
        string root;
    public:
		FileReader(const string &path, Renderer *renderer, bool fullpath=true);

		bool exists(const string &path);
        void open();
        string readString(const string &path);
        Texture* readSurface(const string &path);
        void close();
    };
}

#endif /* FileReader_hpp */
