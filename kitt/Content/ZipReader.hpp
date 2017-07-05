#pragma once

#include <physfs.h>
#include <string>
#include "IReader.hpp"

namespace Content
{
	using namespace std;

	class ZipReader : public IReader {
	private:
		string filepath;
	public:
		ZipReader(const string &zipfile);
		virtual ~ZipReader();

		void open();
		bool exists(const string &path);
		string readString(const string &path);
		Texture* readSurface(const string &path);
		void close();
	};
}