#pragma once

#include <string>

namespace Core {
	using namespace std;

	class Settings {
	private:
		static Settings *instance;
		string root;
		Settings();

	public:
		virtual ~Settings();
		
		static Settings *get();

		void setRoot(const string &root);
		void setRootFromArgs(const char *arg);
		string getRoot() const;
		string getFullPath(const string &path) const;
		
	};
}