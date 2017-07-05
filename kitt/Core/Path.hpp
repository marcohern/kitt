#pragma once

#include <string>

namespace Core {
	using namespace std;

	class Path {
	private:
		static Path *instance;
		string _root;
		Path();

	public:
		virtual ~Path();
		
		static Path *get();

		void setRoot(const string &root);
		void setRootFromArgs(const char *arg);
		string getRoot() const;
		string getFullPath(const string &base, const string &path) const;

		static string root();
		
	};
}