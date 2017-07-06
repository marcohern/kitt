#pragma once

#include "Signal.hpp"

namespace Input {
	class SignalManager {
	protected:
		Signal signals[2];

	public:
		SignalManager();
		virtual ~SignalManager();

		virtual Signal *getSignals() = 0;
	};
}