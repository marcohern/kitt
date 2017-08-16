#pragma once

#include "Renderable.hpp"
#include "Color.hpp"

namespace Graphics {
	class Tintable : public Renderable {
	private:
		Color tint;

	public:
		Color getTint() const;
		Color setTint(const Color &color);
		
		virtual void render(Renderer *render, Camera *camera);
		virtual void update(double interval);
	};
}