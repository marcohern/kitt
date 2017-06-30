#pragma once

#include <string>
#include <exception>

namespace Exceptions {
	using namespace std;

	class KittException: public exception {
	private:
		string message;
	public:
		KittException(std::string msg);
		string getMessage() const throw();
		virtual const char *what() const throw();
	};

}