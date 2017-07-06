
#include "../SDL.h"
#include "SdlRenderer.hpp"
#include "SdlTexture.hpp"
#include "../constants.hpp"

namespace Graphics
{
	SdlRenderer::SdlRenderer(SDL_Window *window, Trigonometry *trigonometry) 
		: tip1(trigonometry), tip2(trigonometry)
	{
		this->renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	}

	SdlRenderer::~SdlRenderer() {
		SDL_DestroyRenderer(this->renderer);
	}

	void SdlRenderer::clear() {
		SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
		SDL_RenderClear(renderer);
	}

	void SdlRenderer::present() {
		SDL_RenderPresent(renderer);
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
		dstrect.w = texture->w();
		dstrect.h = texture->h();
		
		SDL_RenderCopy(renderer, txt->getSdlTexture(), &srcrect, &dstrect);
	}

	void SdlRenderer::vector2d(int x, int y, int color, const Vector2D &v) {
		double l = v.magnitude()*0.20;
		tip1 = v.u();
		tip2 = v.u();
		
		tip1.multiply(l);
		tip2.multiply(l);
		
		tip1.rotate(PI/2 + PI/4);
		tip2.rotate(TAU - PI/2 - PI/4);

		int fx = v.iX() + x;
		int fy = v.iY() + y;

		SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
		SDL_RenderDrawLine(renderer, x, y, fx, fy);
		SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0x00, 0xFF);
		SDL_RenderDrawLine(renderer, fx, fy, tip1.iX() + fx, tip1.iY() + fy);
		SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0xFF, 0xFF);
		SDL_RenderDrawLine(renderer, fx, fy, tip2.iX() + fx, tip2.iY() + fy);
		/*
		SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0x00, 0xFF);
		SDL_RenderDrawLine(renderer, x, y, t1fx, t1fy);
		SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0xFF, 0xFF);
		SDL_RenderDrawLine(renderer, x, y, t2fx, t2fy);
		*/
	}

	SDL_Renderer *SdlRenderer::getRenderer() {
		return this->renderer;
	}
}