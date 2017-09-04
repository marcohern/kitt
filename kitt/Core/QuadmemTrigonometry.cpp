
#include "QuadmemTrigonometry.hpp"

namespace Core {
		QuadmemTrigonometry::QuadmemTrigonometry() {
		for (int i = 0; i < TRIGO_QUAD_SIZE; i++) {
			double r = radian(i);
			int ix = index(r);
			quad[ix] = ::sin(r);
		}
	}

	QuadmemTrigonometry::~QuadmemTrigonometry() {

	}

	double QuadmemTrigonometry::cos(double r) {
		int i = index(r);
		double fm = fmod(r, TAU) / TAU;
		fm = (fm < 0) ? 1.0 + fm : fm;

		if (fm < TAU             ) return  quad[i];
		else if (fm < THREEHALFPI) return -quad[TRIGO_QUAD_SIZE - i - 1];
		else if (fm < PI         ) return -quad[i];
		else                       return  quad[TRIGO_QUAD_SIZE - i - 1];
	}

	double QuadmemTrigonometry::sin(double r) {
		int i = index(r);
		double fm = fmod(r, TAU) / TAU;
		fm = (fm < 0) ? 1.0 + fm : fm;
		
		if      (fm < TAU        ) return -quad[TRIGO_QUAD_SIZE - i - 1];
		else if (fm < THREEHALFPI) return -quad[i];
		else if (fm < PI         ) return  quad[TRIGO_QUAD_SIZE - i - 1];
		else                       return  quad[i];
	}

	int QuadmemTrigonometry::index(double r) {
		double fm = fmod(r, HALFPI) / HALFPI;
		fm = (fm < 0) ? 1.0 + fm : fm;
		return fm*TRIGO_QUAD_SIZE;
	}

	double QuadmemTrigonometry::radian(int i) {
		double r = (double)i;
		return HALFPI * r / TRIGO_QUAD_SIZE;
	}
}