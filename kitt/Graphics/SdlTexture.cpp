#include "SdlTexture.hpp"
#include "SdlRenderer.hpp"

namespace Graphics {
	SdlTexture::SdlTexture(SdlRenderer *renderer, SDL_Surface *surface)
	: Texture() {
		this->surface = surface;
		this->texture = SDL_CreateTextureFromSurface(renderer->getRenderer(), this->surface);
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

	SDL_Surface *SdlTexture::getSdlSurface() {
		return this->surface;
	}

	SDL_Texture *SdlTexture::getSdlTexture() {
		return this->texture;
	}
}