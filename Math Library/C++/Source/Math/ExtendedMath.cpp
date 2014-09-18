#include "Math/ExtendedMath.h"

const float Math::PI = 3.14159265358979323846f;

float Math::radiansToDegrees(float r) {
	return r * (180.0f / PI);
}

float Math::degreesToRadians(float d) {
	return d * (PI / 180.0f);
}
