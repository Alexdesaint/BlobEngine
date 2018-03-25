#include <BlobEngine/Geometrie.hpp>

#include <cmath>

namespace BlobEngine {

	template<typename T>
	float Mat2<T>::length() {
		return std::sqrt(length2());
	}

	template<typename T>
	float Mat2<T>::getOrientationRad() {
		return std::atan2(y, x);
	}

	template<typename T>
	float Mat2<T>::getOrientationDeg() {
		return std::atan2(y, x) * 180 / PI;
	}

	template<typename T>
	Mat2<T> Mat2<T>::setLength(float newLength) {
		float oldLength = length();
		float Rapport;

		if (oldLength != 0) {
			Rapport = newLength / oldLength;
			x *= Rapport;
			y *= Rapport;
		}
		return *this;
	}
}