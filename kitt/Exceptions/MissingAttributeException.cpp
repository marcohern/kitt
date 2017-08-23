
#include "MissingAttributeException.hpp"

namespace Exceptions {
	MissingAttributeException::MissingAttributeException(string message)
		: KittException(message) { }
}