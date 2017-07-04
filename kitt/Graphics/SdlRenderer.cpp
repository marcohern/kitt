
#include "../SDL.h"
#include "SdlRenderer.hpp"
#include "SdlTexture.hpp"

namespace Graphics
{
	SdlRenderer::SdlRenderer(SDL_Window *window) {
		this->renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	}

	SdlRenderer::~SdlRenderer() {
		SDL_DestroyRenderer(this->renderer);
	}

	void SdlRenderer::texture(int x, int y, Texture *texture) {
		SdlTexture *txt = (SdlTexture*)texture;
		
		SDL_Rect srcrect;
		srcrect.x = 0;
		srcrect.y = 0;
		srcrect.w = texture->w();
		srcrect.h = texture->h();

		SDL_Rect dstrect;
		dstrect.x = x;
		dstrect.y = y;
		srcrect.w = texture->w();
		srcrect.h = texture->h();

		SDL_RenderCopy(renderer, txt->getSdlTexture(), &srcrect, &dstrect);
	}

	void SdlRenderer::vector2d(int x, int y, int color, const Vector2D &v) {
		int fx = v.getX() + x;
		int fy = v.getY() + y;
		SDL_RenderDrawLine(renderer, x, y, fx, fy);
	}

	SDL_Renderer *SdlRenderer::getRenderer() {
		return this->renderer;
	}
}