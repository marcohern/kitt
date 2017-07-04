#pragma once

#include <string>
#include "IReader.hpp"
#include "../Graphics/Texture.hpp"

namespace Content {
	using namespace std;
	using namespace Graphics;

	class Load {
	private:
		static Load *instance;
		
		IReader *reader;
		
		Load();
	public:
		virtual ~Load();
		static Load *get();

		Texture *getTexture(const string &path);

		static Texture *texture(const string &path);
	};
}