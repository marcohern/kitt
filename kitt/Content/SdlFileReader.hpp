#pragma once

#include <string>
#include "../Content/IReader.hpp"
#include "../Graphics/Renderer.hpp"

namespace Content {
    
	class SdlFileReader : public IReader {
	private:
		Renderer *renderer;
		string root;
	public:
		SdlFileReader(const string &path, Renderer *renderer, bool fullpath = true);

		bool exists(const string &path);
		void open();
		string readString(const string &path);
		Texture* readSurface(const string &path);
		SpriteSheet *readSpriteSheet(const string &path);
		void close();
	};
}
