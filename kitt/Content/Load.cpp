
#include "Load.hpp"
#include "FileReader.hpp"

namespace Content
{
	Load *Load::instance = NULL;

	Load::Load() {
		reader = new FileReader();
	}

	Load::~Load() {
		delete reader;
	}

	Load *Load::get() {
		if (instance == NULL) {
			instance = new Load();
		}
		return instance;
	}

	Texture *Load::getTexture(const string &path) {
		return this->reader->readSurface(path);
	}

	Texture *Load::texture(const string &path) {
		return Load::get()->getTexture(path);
	}
}