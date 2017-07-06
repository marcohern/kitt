#include <string>
#include "SdlWindow.hpp"
#include "../Core/Trigonometry.hpp"
#include "../constants.hpp"

namespace Graphics
{
	using namespace std;
	using namespace Core;

	SdlWindow::SdlWindow(string title, int width, int height, bool fullscreen, Trigonometry *trigonometry)
	: Window() {
		this->width = width;
		this->height = height;
		this->_fullscreen = fullscreen;
		int flags = SDL_WINDOW_SHOWN;
		if (_fullscreen) flags |= SDL_WINDOW_FULLSCREEN;
		this->window = SDL_CreateWindow(TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flags);
		this->renderer = new SdlRenderer(this->window, trigonometry);
	}

	SdlWindow::~SdlWindow() {
		SDL_DestroyWindow(window);
		delete renderer;
	}

	int SdlWindow::w() const {
		return this->width;
	}

	int SdlWindow::h() const {
		return this->height;
	}

	bool SdlWindow::fullscreen() const {
		return this->_fullscreen;
	}
}