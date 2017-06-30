
#include "Placeable.hpp"

namespace Core {
	
	Vector2D Placeable::getLocation() {
		return this->location;
	}

	void Placeable::setLocation(double x, double y) {
		this->location.set(x, y);
	}

	void Placeable::setLocation(const Vector2D &v) {
		this->location = v;
	}

	void Placeable::move(double x, double y) {
		this->location.add(x, y);
	}

	void Placeable::move(const Vector2D &v) {
		this->location.add(v);
	}
}