#pragma once

#include <string>
#include "Texture.hpp"

namespace Graphics {
	using namespace std;

	class TextureFactory {
	public:
		static Texture *load(const string &fullpath);
	};
}