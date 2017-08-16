
#include "../SDL.h"
#include "SdlRenderer.hpp"
#include "SdlTexture.hpp"
#include "../constants.hpp"
#include "Color.hpp"
#include "../Core/TrigonometryInjector.hpp"

namespace Graphics
{
	using namespace Core;

	SdlRenderer::SdlRenderer(SDL_Window *window, Trigonometry *trigonometry) 
		: tip1(trigonometry), tip2(trigonometry)
	{
		this->renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	}

	SdlRenderer::SdlRenderer(SDL_Window *window)
		: SdlRenderer(window, TrigonometryInjector::inject())
	{
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

	void SdlRenderer::texture(const Vector2D &position, Texture *texture) {
		SdlTexture *txt = (SdlTexture*)texture;
		
		SDL_Rect srcrect;
		srcrect.x = 0;
		srcrect.y = 0;
		srcrect.w = texture->w();
		srcrect.h = texture->h();

		SDL_Rect dstrect;
		dstrect.x = position.iX();
		dstrect.y = position.iY();
		dstrect.w = texture->w();
		dstrect.h = texture->h();
		
		SDL_RenderCopy(renderer, txt->getSdlTexture(), &srcrect, &dstrect);
	}

	void SdlRenderer::vector2d(const Vector2D &position, const Color &color, const Vector2D &v) {
		double l = v.magnitude()*0.20;
		tip1 = v.u();
		tip2 = v.u();
		
		tip1.multiply(l);
		tip2.multiply(l);
		
		tip1.rotateDeg(135);
		tip2.rotateDeg(-135);

		int fx = v.iX() + position.iX();
		int fy = v.iY() + position.iY();

        SDL_SetRenderDrawColor(renderer, color.iR(), color.iG(), color.iB(), color.iA());
		SDL_RenderDrawLine(renderer, position.iX(), position.iY(), fx, fy);
		SDL_RenderDrawLine(renderer, fx, fy, tip1.iX() + fx, tip1.iY() + fy);
		SDL_RenderDrawLine(renderer, fx, fy, tip2.iX() + fx, tip2.iY() + fy);
		
	}

	void SdlRenderer::sprite(const Vector2D &location, Sprite *sprite) {
		SdlTexture *tx = (SdlTexture *)sprite->getTexture();

		SDL_Rect src, dst;
		SDL_Point pnt;

		src.x = sprite->getX();  src.y = sprite->getY();  src.w = sprite->getW(); src.h = sprite->getH();
		dst.x = location.getX(); dst.y = location.getY(); dst.w = sprite->getW(); dst.h = sprite->getH();
		pnt.x = 0; pnt.y = 0;
		SDL_RenderCopy(renderer, tx->getSdlTexture(), &src, &dst);
		//SDL_RenderCopyEx(renderer, tx->getSdlTexture(), &src, &dst, 0.0, &pnt, SDL_RendererFlip::SDL_FLIP_NONE);
	}

	void SdlRenderer::animation(const Vector2D &position, Animation *animation) {
		Sprite *sprite = animation->getCurrentSprite();
		SdlTexture *tx = (SdlTexture *)sprite->getTexture();
		SDL_Rect src, dst;
		SDL_Point pnt;

		src.x = sprite->getX();  src.y = sprite->getY();  src.w = sprite->getW(); src.h = sprite->getH();
		dst.x = position.getX()-sprite->getPX(); dst.y = position.getY()-sprite->getPY(); dst.w = sprite->getW(); dst.h = sprite->getH();
		SDL_RenderCopy(renderer, tx->getSdlTexture(), &src, &dst);
	}

	void SdlRenderer::animation(const Vector2D &position, const Vector2D &area, const Vector2D &pivot, double angle, bool hflip, Animation *animation) {
		Sprite *sprite = animation->getCurrentSprite();
		SdlTexture *tx = (SdlTexture *)sprite->getTexture();
		SDL_Rect src, dst;
		SDL_Point pnt;
		
		src.x = sprite->getX(); src.y = sprite->getY(); src.w = sprite->getW(); src.h = sprite->getH();
		dst.x = position.getX() - sprite->getPX(); dst.y = position.getY() - sprite->getPY(); dst.w = area.getX(); dst.h=area.getY();
		pnt.x = pivot.iX(); pnt.y = pivot.iY();

		SDL_RendererFlip flip = (hflip) ? SDL_RendererFlip::SDL_FLIP_HORIZONTAL : SDL_RendererFlip::SDL_FLIP_NONE;
		
		SDL_SetRenderDrawColor(renderer,0xFF,0x00,0x00,0xFF);
		SDL_RenderDrawRect(renderer, &dst);
		SDL_RenderCopyEx(renderer, tx->getSdlTexture(), &src, &dst, angle, &pnt, flip);
	}

	SDL_Renderer *SdlRenderer::getRenderer() {
		return this->renderer;
	}
}
