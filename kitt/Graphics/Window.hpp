#pragma once

#include "Renderer.hpp"

namespace Graphics {
	class Window {
	protected:
		Renderer *renderer;

	public:
		Window();

		virtual ~Window();
		Renderer *getRenderer();

		virtual int w() const = 0;
		virtual int h() const = 0;
		virtual bool fullscreen() const = 0;
	};
}