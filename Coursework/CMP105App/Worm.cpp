#include "Worm.h"

Worm::Worm()
{
	m_levelTimerLength = 15;
	m_levelTimer = m_levelTimerLength;

	m_speed = 800 / 15; //screen width / time to cross screen
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
	setPosition({ 0, /*m_window->getSize().y nullptrs*/600 - m_wormHeight});
}

void Worm::update(float dt)
{
	m_currentAnimation->animate(dt);
	setTextureRect(m_currentAnimation->getCurrentFrame());

	float wormYPos = /*m_window->getSize().y nullptrs*/600 - m_wormHeight;
	float orthog_speed = m_speed * dt;	// orthogonal movement

	setPosition({getPosition().x + orthog_speed, wormYPos });
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