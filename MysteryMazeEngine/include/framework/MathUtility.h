#pragma once
#include <SFML/Graphics.hpp>

namespace mz
{
	//convertion functions
	sf::Vector2f RotationToVector(float rotation);
	float DegreesToRadians(float degrees);
	float RadiansToDegrees(float radians);

	//template in case vector can be int or float
	template<typename T>
	float GetVectorLength(const sf::Vector2<T>& vector)
	{
		return std::sqrt(vector.x * vector.x + vector.y * vector.y);
	}

	template<typename T>
	//vectorToScale is not const because we change it
	sf::Vector2<T> ScaleVector(sf::Vector2<T>& vectorToScale, float scaleAmount)
	{
		vectorToScale.x *= scaleAmount;
		vectorToScale.y *= scaleAmount;
		return vectorToScale;
	}

	template<typename T>
	sf::Vector2<T>& Normalise(sf::Vector2<T>& vectorToNormalise)
	{
		float vectorLength = GetVectorLength<T>(vectorToNormalise);
		if (vectorLength == 0.f) return sf::Vector2<T>{}; //cannot normalise 0 vector, return nothing

		ScaleVector(vectorToNormalise, 1.0/vectorLength);

		return vectorToNormalise;
	}
}