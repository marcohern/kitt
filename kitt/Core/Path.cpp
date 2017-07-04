#include <string>
#include <algorithm>
#include "Path.hpp"
#include "../constants.hpp"

namespace Core {
	using namespace std;
	Path *Path::instance = NULL;

	Path::Path() {

	}

	Path::~Path() {

	}

	Path *Path::get() {
		if (instance == NULL) {
			instance = new Path();
		}
		return instance;
	}

	void Path::setRootFromArgs(const char *arg, const char *folder) {
		string exe(arg);
		int pos;
		char app[2] = { DS, '\0' };
		pos = exe.find_last_of(DS); //Debug or Release
		exe = exe.substr(0, pos);
		pos = exe.find_last_of(DS); //root
		string root = exe.substr(0, pos);
		root.append(app);
		root.append(folder);
		this->setRoot(root);
	}

	void Path::setRoot(const string &root) {
		this->root = root;
	}

	string Path::getRoot() const {
		return this->root;
	}

	string Path::getFullPath(const string &path) const {
#ifdef _WIN32
		string result = path;
		replace(result.begin(), result.end(), UDS, WDS);
		result = root + result;
		return result;
#else
		return path;
#endif
	}
}