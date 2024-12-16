#pragma once
#include <SFML/Graphics.hpp>

namespace mz
{
	//convertion functions
	sf::Vector2f RotationToVector(float rotation);
	float DegreesToRadians(float degrees);
	float RadiansToDegrees(float radians);

}