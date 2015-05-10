#include "Math/ExtendedMath.h"

namespace Math {
	
	const float PI = 3.14159265358979323846f;
	
	float radiansToDegrees(float r) {
		return r * (180.0f / PI);
	}
	
	float degreesToRadians(float d) {
		return d * (PI / 180.0f);
	}
	
}
