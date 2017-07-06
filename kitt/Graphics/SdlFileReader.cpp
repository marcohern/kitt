
#include "SdlFileReader.hpp"
#include "Texture.hpp"
#include "SdlTexture.hpp"
#include "../Core/Path.hpp"

namespace Graphics {

	using namespace std;
	using namespace Core;

	SdlFileReader::SdlFileReader(const string &path, Renderer *renderer, bool fullpath) {
		this->renderer = renderer;
		if (fullpath) {
			this->root = path;
		}
		else {
			this->root = Path::root();
			this->root.append(Path::normalize(path));
		}
	}

	bool SdlFileReader::exists(const string &path) {
		string fullpath = this->root;
		fullpath.append(Path::normalize(path));
		if (FILE *f = fopen(fullpath.c_str(), "r")) {
			fclose(f);
			return true;
		}
		return false;
	}

	void SdlFileReader::open() {
		//nothing to do
	}

	string SdlFileReader::readString(const string &path) {
		return "";
	}

	Texture* SdlFileReader::readSurface(const string &path) {

		string fullpath = this->root;
		fullpath.append(Path::normalize(path));
		SDL_Surface *surf = IMG_Load(fullpath.c_str());
		SdlTexture *txt = new SdlTexture((SdlRenderer *)renderer, surf);
		return txt;
	}

	void SdlFileReader::close() {
		//nothing to do
	}

}