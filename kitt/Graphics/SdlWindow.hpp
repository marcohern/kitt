#pragma once

#include <string>
#include "../SDL.h"
#include "../Core/Vector2D.hpp"
#include "Window.hpp"
#include "SdlRenderer.hpp"

namespace Graphics {
	using namespace std;

	class SdlWindow : public Window {
	private:
		int width;
		int height;
		bool _fullscreen;

		SDL_Window *window;

	public:
		SdlWindow(string title, int width, int height, bool fullscreen);
		SdlWindow(string title, int width, int height, bool fullscreen, Trigonometry *trigonometri);
		virtual ~SdlWindow();

		int w() const;
		int h() const;
		bool fullscreen() const;
	};
}