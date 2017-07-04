#pragma once

#include "../SDL.h"
#include "./Texture.hpp"



namespace Graphics {
	class SdlTexture : public Texture {
	private:
		SDL_Surface *surface;
	public:
		SdlTexture(SDL_Surface *surface);
		virtual ~SdlTexture();

		int w() const;
		int h() const;
	};
}