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
	

private:

	Animation m_wiggleRight;

	Animation* m_currentAnimation;

	float m_speed;
	float m_wormHeight;

	float m_levelTimer;
	float m_levelTimerLength;
};

