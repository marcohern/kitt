
#include "Window.hpp"
#include "Renderer.hpp"

namespace Graphics {

	Window::Window() {
		this->renderer = NULL;
	}

	Window::~Window() {

	}

	Renderer *Window::getRenderer() {
		return this->renderer;
	}
}