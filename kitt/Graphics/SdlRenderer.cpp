
#include "../SDL.h"
#include "SdlRenderer.hpp"
#include "SdlTexture.hpp"
#include "../constants.hpp"
#include "Color.hpp"
#include "../Core/TrigonometryInjector.hpp"

namespace Graphics
{
	using namespace Core;

	void SdlRenderer::renderColliders(Animation *animation, const Vector2D &position, const Vector2D &pivot) {
		SDL_Rect dst;
		Sprite *sprite= animation->getCurrentSprite();
		vector<CollisionShape *> shapes = sprite->getColliders();
		SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0xFF, 0x77);
		SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
		for (auto shape : shapes) {
			if (shape->getType() == CollisionShapeType::COLLSHAPE_RECT)
			{
				auto corners = shape->getCorners();
				Vector2D tl = corners[0];
				Vector2D br = corners[3];
				dst.x = position.getX() - sprite->getPX() - pivot.getX() + tl.getX();
				dst.y = position.getY() - sprite->getPY() - pivot.getY() + tl.getY();
				dst.w = br.getX() - tl.getX();
				dst.h = br.getY() - tl.getY();

				SDL_RenderFillRect(renderer, &dst);
			}
		}
	}

	SdlRenderer::SdlRenderer(SDL_Window *window) 
		: tip1(), tip2()
	{
		this->renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

		this->screen = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, 1280, 720);
		
	}

	SdlRenderer::~SdlRenderer() {
		SDL_DestroyRenderer(this->renderer);
	}

	void SdlRenderer::clear() {
		SDL_SetRenderTarget(renderer, screen);
		SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
		SDL_RenderClear(renderer);
	}

	void SdlRenderer::present() {

		SDL_SetRenderTarget(renderer, NULL);
		SDL_RenderCopyEx(renderer, screen, NULL, NULL, 0, NULL, SDL_FLIP_NONE);
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

	void SdlRenderer::animation(
		Animation *animation
		, const Vector2D &position, const Vector2D &area, const Vector2D &offset, const Vector2D &pivot
		, const Color &tint, int blendAdd, double angle, RendererFlip flip) {
		Sprite *sprite = animation->getCurrentSprite();
		SdlTexture *tx = (SdlTexture *)sprite->getTexture();
		SDL_Rect src, dst;
		SDL_Point pnt;

		src.x = sprite->getX(); src.y = sprite->getY(); src.w = sprite->getW(); src.h = sprite->getH();

		dst.x = position.getX() - sprite->getPX() - pivot.getX();
		dst.y = position.getY() - sprite->getPY() - pivot.getY();
		dst.w = area.getX(); dst.h = area.getY();
		if (dst.w == 0) dst.w = sprite->getW();
		if (dst.h == 0) dst.h = sprite->getH();
		pnt.x = pivot.iX(); pnt.y = pivot.iY();

		SDL_SetTextureAlphaMod(tx->getSdlTexture(), tint.iA());

		SDL_RendererFlip sflip = 
			(flip == RENDER_FLIP_HORIZONTAL) ? SDL_RendererFlip::SDL_FLIP_HORIZONTAL :
			(flip == RENDER_FLIP_HORIZONTAL) ? SDL_RendererFlip::SDL_FLIP_VERTICAL :
			SDL_RendererFlip::SDL_FLIP_NONE;

		SDL_SetTextureColorMod(tx->getSdlTexture(), tint.iR(), tint.iG(), tint.iB());

		SDL_RenderCopyEx(renderer, tx->getSdlTexture(), &src, &dst, angle, &pnt, sflip);

		if (blendAdd > 0) {
			SDL_SetTextureBlendMode(tx->getSdlTexture(), SDL_BLENDMODE_ADD);
			for (int i = 0; i < blendAdd; i++) {
				SDL_RenderCopyEx(renderer, tx->getSdlTexture(), &src, &dst, angle, &pnt, sflip);
			}
			SDL_SetTextureBlendMode(tx->getSdlTexture(), SDL_BLENDMODE_BLEND);
		}

		this->renderColliders(animation, position, pivot);

		SDL_SetTextureAlphaMod(tx->getSdlTexture(), 0xFF);
		SDL_SetTextureColorMod(tx->getSdlTexture(), 0xFF, 0xFF, 0xFF);
	}

	SDL_Renderer *SdlRenderer::getRenderer() {
		return this->renderer;
	}
}
