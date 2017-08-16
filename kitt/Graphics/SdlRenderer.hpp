#pragma once


#include "../SDL.h"
#include "../Core/Vector2D.hpp"
#include "Renderer.hpp"
#include "Texture.hpp"
#include "../Core/Trigonometry.hpp"
#include "Color.hpp"
#include "Sprite.hpp"

namespace Graphics {
	using namespace Core;

	class SdlRenderer : public Renderer {
	private:
		Trigonometry *trigonometry;
		SDL_Renderer *renderer;
		SDL_Surface *font_surface;
		SDL_Texture *font_texture;
		Vector2D tip1, tip2;
	public:
		SdlRenderer(SDL_Window *window, Trigonometry *trigonometry);
		SdlRenderer(SDL_Window *window);
		virtual ~SdlRenderer();

		void clear();
		void present();
		void texture(const Vector2D &position, Texture *t);
		void vector2d(const Vector2D &position, const Color &color, const Vector2D &v);
		void sprite(const Vector2D &location, Sprite *s);
		void animation(const Vector2D &position, Animation *animation);
		void animation(const Vector2D &position, const Vector2D &area, const Vector2D &pivot, double angle, bool hflip, Animation *animation);

		SDL_Renderer *getRenderer();
	};
}
