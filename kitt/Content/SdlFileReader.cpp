
#include "SdlFileReader.hpp"
#include "../Graphics/Texture.hpp"
#include "../Graphics/SdlTexture.hpp"
#include "../Exceptions/MissingAttributeException.hpp"
#include "../Core/Path.hpp"
#include "../json.hpp"
#include <fstream>

namespace Content {

	using namespace std;
	using namespace Core;
	using namespace Collisions;
	using namespace Exceptions;

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

	void SdlFileReader::extractSprites(SpriteSheet *sheet, const json &j) const {
		int i = 0;
		for (auto s : j["sprites"]) {
			stringstream ss;
			if (s["id"].empty()) {
				ss << "sprites[" << i << "]: expected 'id' in spritesheet json, but not found.";
				throw new MissingAttributeException(ss.str());
			}
			if (s["x"].empty()) {
				ss << "sprites[" << i << "]: expected 'x' in spritesheet json, but not found.";
				throw new MissingAttributeException(ss.str());
			}
			if (s["y"].empty()) {
				ss << "sprites[" << i << "]: expected 'y' in spritesheet json, but not found.";
				throw new MissingAttributeException(ss.str());
			}
			if (s["w"].empty()) {
				ss << "sprites[" << i << "]: expected 'w' in spritesheet json, but not found.";
				throw new MissingAttributeException(ss.str());
			}
			if (s["h"].empty()) {
				ss << "sprites[" << i << "]: expected 'h' in spritesheet json, but not found.";
				throw new MissingAttributeException(ss.str());
			}

			string id = s["id"].get<string>();
			int x = s["x"].get<int>();
			int y = s["y"].get<int>();
			int w = s["w"].get<int>();
			int h = s["h"].get<int>();
			int px = (s["px"].empty()) ? 0 : s["px"].get<int>();
			int py = (s["py"].empty()) ? 0 : s["py"].get<int>();
			Sprite *sprite = sheet->addSprite(id, x, y, w, h, px, py);
			string colliderId = (s["collider"].empty()) ? "" : s["collider"].get<string>();

			if (!colliderId.empty()) {
				vector<CollisionShape *> colliders = sheet->getColliders(colliderId);
				for (auto cc : colliders) sprite->addCollider(cc);
			}
			i++;
		}
	}

	void SdlFileReader::extractAnimations(SpriteSheet *sheet, const json &j) const {
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
	}

	void SdlFileReader::extractColliders(SpriteSheet *sheet, const json &j) const {
		for (auto c : j["colliders"]) {
			string id = c["id"].get<string>();
			for (auto s : c["shapes"]) {
				string type = s["type"].get<string>();
				if (type == "rect") sheet->addCollider(id, s["x"].get<double>(), s["y"].get<double>(), s["w"].get<double>(), s["h"].get<double>());
				else if (type == "circle") sheet->addCollider(id, s["x"].get<double>(), s["y"].get<double>(), s["r"].get<double>());
			}
		}
	}

	SpriteSheet *SdlFileReader::readSpriteSheet(const string &path) {
		string fullpath = this->root;
		int i;
		json j;

		fullpath.append(Path::normalize(path));
		ifstream f(fullpath);
		f >> j;

		if (j["source"].empty()) throw new MissingAttributeException("root: expected 'source' but not found.");
		string texturefile = j["source"].get<string>();
		Texture *texture = this->readSurface(texturefile);

		SpriteSheet *sheet = new SpriteSheet(texture);

		this->extractColliders(sheet, j);
		this->extractSprites(sheet, j);
		this->extractAnimations(sheet, j);
		
		return sheet;
	}

	void SdlFileReader::close() {
		//nothing to do
	}

}
