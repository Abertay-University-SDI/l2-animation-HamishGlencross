#pragma once
#include "Framework/Animation.h"
#include "Framework/GameObject.h"
class Worm : public GameObject
{
public:
	Worm();
	virtual ~Worm() = default;

	void update(float dt);

	float getTimer();
	void setTimer(float time);

	float getTimerLength();
	void setTimerLength(float time);

	void setKnownScreenSize(sf::Vector2u screenSize);

private:

	Animation m_wiggleRight;

	Animation* m_currentAnimation;

	sf::Vector2u m_knownScreenSize;

	float m_wormHeight;

	float m_levelTimer;
	float m_levelTimerLength;
};

