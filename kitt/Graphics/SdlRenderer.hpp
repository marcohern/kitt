#pragma once


#include "../SDL.h"
#include "../Core/Vector2D.hpp"
#include "Renderer.hpp"
#include "Texture.hpp"

namespace Graphics {
	using namespace Core;

	class SdlRenderer : public Renderer {
	private:
		SDL_Renderer *renderer;
		SDL_Surface *font_surface;
		SDL_Texture *font_texture;
	public:
		SdlRenderer(SDL_Window *window);
		virtual ~SdlRenderer();

		void texture(int x, int y, Texture *t);
		void vector2d(int x, int y, int color, const Vector2D &v);

		SDL_Renderer *getRenderer();
	};
}