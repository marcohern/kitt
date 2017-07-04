#pragma once

#include "../SDL.h"
#include "./Texture.hpp"
#include "./SdlRenderer.hpp"

namespace Graphics {
	class SdlTexture : public Texture {
	private:
		SDL_Surface *surface;
		SDL_Texture *texture;

	public:
		SdlTexture(SdlRenderer *renderer, SDL_Surface *surface);
		virtual ~SdlTexture();

		int w() const;
		int h() const;

		SDL_Surface *getSdlSurface();
		SDL_Texture *getSdlTexture();
	};
}