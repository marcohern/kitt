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
		unsigned long pos;
		char app[2] = { DS, '\0' };
        pos = exe.find_last_of(DS); //Debug or Release
        exe = exe.substr(0, pos);
        pos = exe.find_last_of(DS); //root (win)
#ifdef __APPLE__
        exe = exe.substr(0, pos);
        pos = exe.find_last_of(DS);
        exe = exe.substr(0, pos);
        pos = exe.find_last_of(DS);
        exe = exe.substr(0, pos);
        pos = exe.find_last_of(DS);
        exe = exe.substr(0, pos);
        pos = exe.find_last_of(DS);
        exe = exe.substr(0, pos);
        pos = exe.find_last_of(DS);
#endif
		string root = exe.substr(0, pos);
		root.append(app);
		root.append(folder);
		this->setRoot(root);
	}

	void Path::setRoot(const string &root) {
		this->_root = root;
	}

	string Path::getRoot() const {
		return this->_root;
	}

	string Path::getFullPath(const string &path) const {
#ifdef _WIN32
		string result = path;
		replace(result.begin(), result.end(), UDS, WDS);
		result = _root + result;
		return result;
#else
		return _root + path;
#endif
	}

	string Path::root() {
		return Path::get()->getRoot();
	}
}
