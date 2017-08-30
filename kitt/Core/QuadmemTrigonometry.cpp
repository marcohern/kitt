
#include "QuadmemTrigonometry.hpp"

namespace Core {
	QuadmemTrigonometry::QuadmemTrigonometry() {
		for (int i = 0; i < TRIGO_QUAD_SIZE; i++) {
			double r = radian(i);
		}
	}

	QuadmemTrigonometry::~QuadmemTrigonometry() {

	}

	double QuadmemTrigonometry::cos(double r) {
		return 0.0;
	}

	double QuadmemTrigonometry::sin(double r) {
		return 0.0;
	}

	int QuadmemTrigonometry::index(double r) {
		double fm = fmod(r, TAU) / TAU;
		fm = (fm < 0) ? 1.0 + fm : fm;
		if (fm > HALFPI) return 0.0;
		else if (fm > PI) return 0.0;
		else if (fm > THREEHALFPI) return TRIGO_QUAD_SIZE - fm*TRIGO_QUAD_SIZE;
		else return fm*TRIGO_QUAD_SIZE;
	}

	double QuadmemTrigonometry::radian(int i) {
		double r = (double)i;
		return HALFPI * r / TRIGO_QUAD_SIZE;
	}
}