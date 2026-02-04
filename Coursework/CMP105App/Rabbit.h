#pragma once
#include "Framework/Animation.h"
#include "Framework/GameObject.h"
class Rabbit :
    public GameObject
{
public:
	Rabbit();
	virtual ~Rabbit() = default;

	void update(float dt);


	void setPlayer(GameObject player);
	void setKnownScreenSize(sf::Vector2u screenSize);

private:

	Animation m_walkDown;
	Animation m_walkDownRight;
	Animation m_walkUp;
	Animation m_walkUpRight;
	Animation m_walkRight;

	Animation* m_currentAnimation;

	//Member Variables

	GameObject m_player;

	sf::Vector2u m_knownScreenSize;

	sf::Vector2f m_playerPos;

	int m_playerAngleIndex;

	//enum class Direction { UP, DOWN, LEFT, RIGHT, UP_RIGHT, DOWN_RIGHT, DOWN_LEFT, UP_LEFT, NONE };
	//Direction m_direction = Direction::NONE;
	float m_speed = 200.0f;

	float m_personalSpace;

	bool m_isScared;

	const float APPROX_PI = 3.14159265f;
	const float APPROX_ONE_OVER_ROOT_TWO = 0.70710678f;	// 1 / sqrt(2)
};

