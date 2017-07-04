#include "SdlTexture.hpp"

namespace Graphics {
	SdlTexture::SdlTexture(SDL_Surface *surface)
	: Texture() {
		this->surface = surface;
	}

	SdlTexture::~SdlTexture() {
		Texture::~Texture();
	}

	int SdlTexture::w() const {
		return this->surface->w;
	}

	int SdlTexture::h() const {
		return this->surface->h;
	}
}