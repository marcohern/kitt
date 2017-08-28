
#include "SdlSignalManager.hpp"
#include "SignalManager.hpp"
#include "../SDL.h"

namespace Input {
	SdlSignalManager::SdlSignalManager() : SignalManager() {

	}

	SdlSignalManager::~SdlSignalManager() {
		SignalManager::~SignalManager();
	}

	void SdlSignalManager::updateSignalKeys(Signal &signal, bool value) {
		switch (ev.key.keysym.sym) {
		case SDLK_LEFT:
			signal.left = value;
			break;
		case SDLK_RIGHT:
			signal.right = value;
			break;
		case SDLK_UP:
			signal.up = value;
			break;
		case SDLK_DOWN:
			signal.down = value;
			break;
		case SDLK_SPACE:
			signal.jump = value;
			break;
		case SDLK_LCTRL:
			signal.fire = value;
			break;
		case SDLK_LSHIFT: 
			signal.walklock = value;
			break;
		case SDLK_LALT:
			signal.aimlock = value;
			break;
		case SDLK_ESCAPE:
			signal.quit = value;
			break;
		case SDLK_F1:
			signal.zoomIn = value;
			break;
		case SDLK_F2:
			signal.zoomOut = value;
			break;
		case SDLK_F3:
			signal.zoomReset = value;
			break;
		}
	}
	
	void SdlSignalManager::updateSignal(Signal &signal) {
		switch (ev.type) {
		case SDL_QUIT:
			signal.quit = true;
			break;
		case SDL_KEYDOWN:
			updateSignalKeys(signal, true);
			break;
		case SDL_KEYUP:
			updateSignalKeys(signal, false);
			break;
		}
	}

	Signal *SdlSignalManager::getSignals() {
		if (SDL_PollEvent(&ev) != 0) {
			updateSignal(signals[0]);
			//updateSignal(signals[1]);
		}
		return signals;
	}
}