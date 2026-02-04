#include "Pig.h"
#include <iostream>

Pig::Pig()
{
	for (int i = 0; i < 4; i++)
	{
		Pig::m_walkDown.addFrame(sf::IntRect({ i * 64, 0 }, { 64, 64 }));
	}
	m_currentAnimation = &m_walkDown;
	m_walkDown.setLooping(true);
	m_walkDown.setFrameSpeed(1.f / 4.f);
	//m_currentAnimation->setFlipped(false);
	for (int i = 5; i < 8; i++)
	{
		Pig::m_walkUp.addFrame(sf::IntRect({ i * 64, 0 }, { 64, 64 }));
	}
	m_walkUp.setLooping(true);
	m_walkUp.setFrameSpeed(1.f / 4.f);
	for (int i = 0; i < 4; i++)
	{
		Pig::m_walkUpRight.addFrame(sf::IntRect({ i * 64, 64 }, { 64, 64 }));
	}
	m_walkUpRight.setLooping(true);
	m_walkUpRight.setFrameSpeed(1.f / 4.f);
	for (int i = 5; i < 8; i++)
	{
		Pig::m_walkRight.addFrame(sf::IntRect({ i * 64, 64 }, { 64, 64 }));
	}
	m_walkRight.setLooping(true);
	m_walkRight.setFrameSpeed(1.f / 4.f);
	for (int i = 0; i < 4; i++)
	{
		Pig::m_walkDownRight.addFrame(sf::IntRect({ i * 64, 128 }, { 64, 64 }));
	}
	m_walkDownRight.setLooping(true);
	m_walkDownRight.setFrameSpeed(1.f / 4.f);

	setTextureRect(m_currentAnimation->getCurrentFrame());
}

void Pig::update(float dt)
{
	m_currentAnimation->animate(dt);
	setTextureRect(m_currentAnimation->getCurrentFrame());

	//find target location
	
	m_targetPos = m_target.getPosition();

	float m_targetAngle = atan2((m_targetPos.y - getPosition().y), (m_targetPos.x - getPosition().x));

	//std::cout << m_targetPos.x << " , " << m_targetPos.y << " : " << m_targetAngle << std::endl;

	m_targetAngleIndex = (m_targetAngle / APPROX_PI) * 5; //approximates an index that allows a switch case to read the direction

	//std::cout << m_targetAngleIndex << std::endl;

	// for diagonal movement
	float diagonal_speed = m_speed * APPROX_ONE_OVER_ROOT_TWO * dt;
	float orthog_speed = m_speed * dt;	// orthogonal movement

	switch (m_targetAngleIndex)
	{
	case -4:
		move({ -orthog_speed,0 });
		m_currentAnimation = &m_walkRight;
		m_currentAnimation->setFlipped(true);
		break;
	case -3:
		move({ -diagonal_speed, -diagonal_speed });
		m_currentAnimation = &m_walkUpRight;
		m_currentAnimation->setFlipped(true);
		break;
	case -2:
		move({ 0, -orthog_speed });
		m_currentAnimation = &m_walkUp;
		m_currentAnimation->setFlipped(false);
		break;
	case -1:
		move({ diagonal_speed, -diagonal_speed });
		m_currentAnimation = &m_walkUpRight;
		m_currentAnimation->setFlipped(false);
		break;
	case 0:
		move({ orthog_speed,0 });
		m_currentAnimation = &m_walkRight;
		m_currentAnimation->setFlipped(false);
		break;
	case 1:
		move({ diagonal_speed, diagonal_speed });
		m_currentAnimation = &m_walkDownRight;
		m_currentAnimation->setFlipped(false);
		break;
	case 2:
		move({ 0, orthog_speed });
		m_currentAnimation = &m_walkDown;
		m_currentAnimation->setFlipped(false);
		break;
	case 3:
		move({ -diagonal_speed, diagonal_speed });
		m_currentAnimation = &m_walkDownRight;
		m_currentAnimation->setFlipped(true);
		break;
	case 4:
		move({ -orthog_speed,0 });
		m_currentAnimation = &m_walkRight;
		m_currentAnimation->setFlipped(true);
		break;
	}
}

GameObject Pig::getTarget()
{
	return m_target;
}

void Pig::setTarget(GameObject target)
{
	m_target = target;
}

void Pig::setKnownScreenSize(sf::Vector2u screenSize)
{
	m_knownScreenSize = screenSize;
}