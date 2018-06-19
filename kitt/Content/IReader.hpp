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
#include "../SDL.h"
#include "../Graphics/Texture.hpp"
#include "../Graphics/SpriteSheet.hpp"

namespace Content {

    using namespace std;
	using namespace Graphics;

    class IReader {
    public:
        virtual ~IReader();
        virtual void open() = 0;
		virtual bool exists(const string &path) = 0;
        virtual string readString(const string &path) = 0;
        virtual Texture* readSurface(const string &path) = 0;
		virtual SpriteSheet *readSpriteSheet(const string &path) = 0;
        virtual void close() = 0;
    };
    
}
#endif /* IReader_hpp */
