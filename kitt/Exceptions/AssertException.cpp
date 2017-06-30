#include "AssertException.hpp"

#include <string>

namespace Exceptions {
	using namespace std;

	AssertException::AssertException(string message): KittException(message) {

	}
}