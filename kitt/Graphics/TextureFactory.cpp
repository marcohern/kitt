#include "../SDL.h"
#include "./SdlTexture.hpp"
#include "TextureFactory.hpp"

namespace Graphics {
	Texture *TextureFactory::load(const string &fullpath) {
		return new SdlTexture(IMG_Load(fullpath.c_str()));
	}
}