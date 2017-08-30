#pragma once

#include "../constants.hpp"
#include "Trigonometry.hpp"

namespace Core {
	class QuadmemTrigonometry : public Trigonometry {
	private:
		double quad[TRIGO_QUAD_SIZE];

	public:
		QuadmemTrigonometry();
		~QuadmemTrigonometry();

		double sin(double r);
		double cos(double r);

		inline int index(double r);
		inline double radian(int i);
	};
}