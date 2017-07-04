//
//  Texture.hpp
//  kitt
//
//  Created by Marco Hernandez on 2/07/17.
//  Copyright © 2017 Marco Hernandez. All rights reserved.
//

#ifndef Texture_hpp
#define Texture_hpp

#include <stdio.h>

namespace Graphics {
    class Texture {
    public:
		Texture();
		virtual ~Texture();

		virtual int w() const = 0;
		virtual int h() const = 0;
    };
}

#endif /* Texture_hpp */
