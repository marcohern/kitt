#pragma once

#include "Time.hpp"

namespace Core {
	class TimeInjector {
	private:
		static Time *time;
	public:
		static void init(int type);
		static Time *inject();
	};
}