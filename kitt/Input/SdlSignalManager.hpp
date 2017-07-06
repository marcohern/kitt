#pragma once

#include "SignalManager.hpp"
#include "Signal.hpp"
#include "../SDL.h"

namespace Input {
	class SdlSignalManager : public SignalManager {
	private:
		SDL_Event ev;

	public:
		SdlSignalManager();
		~SdlSignalManager();
		void updateSignal(Signal &signal);
		void updateSignalKeys(Signal &signal, bool value);

		Signal *getSignals();
	};
}