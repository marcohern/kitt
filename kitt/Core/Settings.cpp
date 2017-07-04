#include <string>
#include <algorithm>
#include "Settings.hpp"
#include "../constants.hpp"

namespace Core {
	using namespace std;
	Settings *Settings::instance = NULL;

	Settings::Settings() {

	}

	Settings::~Settings() {

	}

	Settings *Settings::get() {
		if (instance == NULL) {
			instance = new Settings();
		}
		return instance;
	}

	void Settings::setRootFromArgs(const char *arg) {
		string exe(arg);
		int pos;
		char app[2] = { DS, '\0' };
		pos = exe.find_last_of(DS); //Debug or Release
		exe = exe.substr(0, pos);
		pos = exe.find_last_of(DS); //root
		string root = exe.substr(0, pos);
		root.append(app);
		root.append("content");
		this->setRoot(root);
	}

	void Settings::setRoot(const string &root) {
		this->root = root;
	}

	string Settings::getRoot() const {
		return this->root;
	}

	string Settings::getFullPath(const string &path) const {
#ifdef _WIN32
		string result = path;
		replace(result.begin(), result.end(), UDS, WDS);
		return result;
#else
		return path;
#endif
	}
}