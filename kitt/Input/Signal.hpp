#pragma once

namespace Input {
	class Signal {
	public:
		bool quit = false;

		//INGAME SIGNALS
		bool left = false;
		bool right = false;
		bool up = false;
		bool down = false;
		int updown = 0;
		int leftright = 0;
		bool jump = false;
		bool aimlock = false;
		bool walklock = false;
		bool fire = false;
		

		//MENU SIGNALS
		bool pause = false;
		bool accept = false;
		bool cancel = false;
	};
}