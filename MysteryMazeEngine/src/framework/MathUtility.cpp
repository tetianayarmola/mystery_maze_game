#include "framework/MathUtility.h"

namespace mz
{
	const float PI = 3.1415926535;

	sf::Vector2f RotationToVector(float rotation)
	{
		//convert degrees to radians
		float radians = DegreesToRadians(rotation);
		return sf::Vector2f(std::cos(radians), std::sinf(radians));
	}
	float DegreesToRadians(float degrees)
	{
		return degrees * (PI / 180.f);
	}
	float RadiansToDegrees(float radians)
	{
		return radians * (180.f / PI);
	}
}