#pragma once
#include "Framework/Animation.h"
#include "Framework/GameObject.h"
class Sheep : public GameObject
{
public:
	Sheep();
	virtual ~Sheep() = default;

	void update(float dt);
	void handleInput(float dt);

	void resetPosition();

	void setKnownScreenSize(sf::Vector2u screenSize);

private:

	Animation m_walkDown;
	Animation m_walkDownRight;
	Animation m_walkUp;
	Animation m_walkUpRight;
	Animation m_walkRight;

	Animation* m_currentAnimation;
	//sheep member variables here

	sf::Vector2u m_knownScreenSize;

	enum class Direction { UP, DOWN, LEFT, RIGHT, UP_RIGHT, DOWN_RIGHT, DOWN_LEFT, UP_LEFT, NONE };
	Direction m_direction = Direction::NONE;
	float m_speed = 300.0f;
	float m_inputBuffer = 0.f;

	const float INPUT_BUFFER_LENGTH = 0.1f;
	const float APPROX_ONE_OVER_ROOT_TWO = 0.70710678f;	// 1 / sqrt(2)
};

