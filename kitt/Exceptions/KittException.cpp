
#include "KittException.hpp"

namespace Exceptions {
	using namespace std;

	KittException::KittException(string message) {
		this->message = message;
	}

	string KittException::getMessage() const throw() {
		return this->message;
	}

	const char *KittException::what() const throw() {
		return this->message.c_str();
	}
}