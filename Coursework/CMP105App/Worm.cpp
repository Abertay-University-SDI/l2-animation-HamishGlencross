#include "Worm.h"
#include <iostream>

Worm::Worm()
{
	m_levelTimerLength = 15;
	m_levelTimer = m_levelTimerLength;

	m_wormHeight = 50;

	for (int i = 0; i < 6; i++)
	{
		Worm::m_wiggleRight.addFrame(sf::IntRect({ i * 64, 0 }, { 64, 64 }));
	}
	m_currentAnimation = &m_wiggleRight;
	m_wiggleRight.setLooping(true);
	m_wiggleRight.setFrameSpeed(1.f / 4.f);
	m_currentAnimation->setFlipped(false);

	setTextureRect(m_currentAnimation->getCurrentFrame());
}

void Worm::update(float dt)
{
	m_currentAnimation->animate(dt);
	setTextureRect(m_currentAnimation->getCurrentFrame());

	float wormYPos = m_knownScreenSize.y - m_wormHeight;
	float wormXPos = ((m_levelTimerLength - m_levelTimer) / m_levelTimerLength) * m_knownScreenSize.x;

	setPosition({wormXPos, wormYPos }); 
	//the worm's position is determined by the dividing the time remaining by the total time, and mulitplying by the screen width
	
	m_currentAnimation = &m_wiggleRight;
	m_currentAnimation->setFlipped(false);

	m_levelTimer -= dt;
}

float Worm::getTimer()
{
	return m_levelTimer;
}

void Worm::setTimer(float time)
{
	m_levelTimer = time;
}

float Worm::getTimerLength()
{
	return m_levelTimerLength;
}

void Worm::setTimerLength(float time)
{
	m_levelTimerLength = time;
}

void Worm::setKnownScreenSize(sf::Vector2u screenSize)
{
	m_knownScreenSize = screenSize;
}