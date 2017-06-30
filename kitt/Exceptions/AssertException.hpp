#pragma once

#include <string>

#include "KittException.hpp"

namespace Exceptions {
	class AssertException : public KittException {
	public:
		AssertException(string message);
	};
}