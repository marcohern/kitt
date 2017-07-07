#pragma once


#include "../SDL.h"
#include "../Core/Vector2D.hpp"
#include "Renderer.hpp"
#include "Texture.hpp"
#include "../Core/Trigonometry.hpp"
#include "Color.hpp"

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
		virtual ~SdlRenderer();

		void clear();
		void present();
		void texture(int x, int y, Texture *t);
		void vector2d(int x, int y, const Color &color, const Vector2D &v);

		SDL_Renderer *getRenderer();
	};
}
