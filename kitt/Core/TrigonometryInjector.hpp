#pragma once

#include "Trigonometry.hpp"

namespace Core {
	class TrigonometryInjector {
	private:
		static Trigonometry *trigonometry;

		TrigonometryInjector();
	public:
		static void init(int type);
		static Trigonometry *inject();
	};
}