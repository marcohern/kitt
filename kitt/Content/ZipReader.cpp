
#include <string>
#include "ZipReader.hpp"
#include "../Core/Path.hpp"

namespace Content
{
	using namespace Core;
	ZipReader::ZipReader(const string &zipfile) {
		filepath = Path::get()->getRoot();
		filepath.append(zipfile);
	}

	ZipReader::~ZipReader() {

	}

	void ZipReader::open() {
		PHYSFS_mount(filepath.c_str(), "/", 1);
	}

	void ZipReader::close() {
		
	}

	bool ZipReader::exists(const string &path) {
		return PHYSFS_exists(path.c_str());
	}

	string ZipReader::readString(const string &path) {
		return "";
	}

	Texture *ZipReader::readSurface(const string &path) {
		return NULL;
	}
}