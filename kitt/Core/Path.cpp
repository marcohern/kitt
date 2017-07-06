#include <string>
#include <algorithm>
#include "Path.hpp"
#include "../constants.hpp"

namespace Core {
	using namespace std;
	Path *Path::instance = NULL;

	string Path::normalize(const string &fullpath) {
		string rpath = fullpath;
#ifdef _WIN32
		replace(rpath.begin(), rpath.end(), UDS, WDS);
#endif
		return rpath;
	}

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

	void Path::setRootFromArgs(const char *arg) {
		string exe(arg);
		unsigned long pos;
		//char app[2] = { DS, '\0' };
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
		this->setRoot(root);
	}

	void Path::setRoot(const string &root) {
		this->_root = root;
	}

	string Path::getRoot() const {
		return this->_root;
	}

	string Path::getFullPath(const string &path) const {
		string rpath = this->_root;
		rpath.append(normalize(path));
		return rpath;
	}

	string Path::root() {
		return Path::get()->getRoot();
	}
}
