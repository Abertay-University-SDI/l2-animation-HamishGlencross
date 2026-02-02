#pragma once
#include "Framework/Animation.h"
#include "Framework/GameObject.h"
class Pig : public GameObject
{
public:

	Pig();
	virtual ~Pig() = default;

	void update(float dt);

	float getTimer();
	void setTimer(float time);

	float getTimerLength();
	void setTimerLength(float time);

	GameObject getTarget();
	void setTarget(GameObject target);

private:

	GameObject m_target;

	Animation m_walkDown;
	Animation m_walkDownRight;
	Animation m_walkUp;
	Animation m_walkUpRight;
	Animation m_walkRight;

	Animation* m_currentAnimation;

	//Member Variables

	sf::Vector2f m_targetPos;

	int m_targetAngleIndex;

	enum class Direction { UP, DOWN, LEFT, RIGHT, UP_RIGHT, DOWN_RIGHT, DOWN_LEFT, UP_LEFT, NONE };
	Direction m_direction = Direction::NONE;
	float m_speed = 200.0f;

	const float APPROX_PI = 3.14159265f;
	const float APPROX_ONE_OVER_ROOT_TWO = 0.70710678f;	// 1 / sqrt(2)
};