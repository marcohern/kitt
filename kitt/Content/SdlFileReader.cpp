
#include "SdlFileReader.hpp"
#include "../Graphics/Texture.hpp"
#include "../Graphics/SdlTexture.hpp"
#include "../Core/Path.hpp"
#include "../json.hpp"
#include <fstream>

namespace Content {

	using namespace std;
	using namespace Core;
	using json = nlohmann::json;

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
		string base = fullpath;
		SDL_Surface *surf = IMG_Load(fullpath.c_str());
		SdlTexture *txt = new SdlTexture((SdlRenderer *)renderer, surf);
		return txt;
	}

	SpriteSheet *SdlFileReader::readSpriteSheet(const string &path) {
		string fullpath = this->root;
		fullpath.append(Path::normalize(path));
		ifstream f(fullpath);
		json j;
		f >> j;

		string texturefile = j["source"].get<string>();
		Texture *texture = this->readSurface(texturefile);

		SpriteSheet *sheet = new SpriteSheet(texture);
		for (auto s : j["sprites"]) {
			sheet->addSprite(s["id"].get<string>(),
				s["x"].get<int>(), s["y"].get<int>(),
				s["w"].get<int>(), s["h"].get<int>(),
				s["px"].get<int>(), s["py"].get<int>()
			);
		}
		for (auto a : j["animations"]) {
			string animId = a["id"].get<string>();
			double duration = a["duration"].get<double>();
			int qty = a["frames"].size();
			int i = 0;
			Animation *anim = new Animation(qty, duration);
			for (auto f : a["frames"]) {
				string spriteId = f.get<string>();
				anim->setSprite(i++, sheet->getSprite(spriteId));
			}
			sheet->addAnimation(animId, anim);
		}
		return sheet;
	}

	void SdlFileReader::close() {
		//nothing to do
	}

}
