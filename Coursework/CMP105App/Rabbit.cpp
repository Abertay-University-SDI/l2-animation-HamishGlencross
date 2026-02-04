#include "Rabbit.h"
#include <iostream>

Rabbit::Rabbit()
{
	//animations

	Rabbit::m_walkDown.addFrame(sf::IntRect({ 64, 0 }, { 64, 64 }));
	Rabbit::m_walkDown.addFrame(sf::IntRect({ 128, 0 }, { 64, 64 }));
	m_walkDown.setLooping(true);
	m_walkDown.setFrameSpeed(1.f / 2.f);

	Rabbit::m_walkUp.addFrame(sf::IntRect({ 192, 0 }, { 64, 64 }));
	Rabbit::m_walkUp.addFrame(sf::IntRect({ 256, 0 }, { 64, 64 }));

	Rabbit::m_walkRight.addFrame(sf::IntRect({ 320, 0 }, { 64, 64 }));
	Rabbit::m_walkRight.addFrame(sf::IntRect({ 384, 0 }, { 64, 64 }));
	Rabbit::m_walkRight.addFrame(sf::IntRect({ 0, 0 }, { 64, 64 }));

	Rabbit::m_walkUpRight.addFrame(sf::IntRect({ 448, 0 }, { 64, 64 }));
	Rabbit::m_walkUpRight.addFrame(sf::IntRect({ 0, 64 }, { 64, 64 }));

	Rabbit::m_walkDownRight.addFrame(sf::IntRect({ 64, 64 }, { 64, 64 }));
	Rabbit::m_walkDownRight.addFrame(sf::IntRect({ 128, 64 }, { 64, 64 }));
	Rabbit::m_walkRight.addFrame(sf::IntRect({ 0, 0 }, { 64, 64 }));
	
	m_currentAnimation = &m_walkDown;

	setTextureRect(m_currentAnimation->getCurrentFrame());

	m_isScared = false;
	m_personalSpace = 200;
}

void Rabbit::update(float dt)
{
	m_currentAnimation->animate(dt);
	setTextureRect(m_currentAnimation->getCurrentFrame());

	m_playerPos = m_player.getPosition();

	float m_playerAngle = atan2((m_playerPos.y - getPosition().y), (m_playerPos.x - getPosition().x));

	float m_playerSquareDistance = ((m_playerPos.x - getPosition().x)* (m_playerPos.x - getPosition().x) + (m_playerPos.y - getPosition().y)* (m_playerPos.y - getPosition().y));
	//ask about ^2 not working

	// for diagonal movement
	float diagonal_speed = m_speed * APPROX_ONE_OVER_ROOT_TWO * dt;
	float orthog_speed = m_speed * dt;	// orthogonal movement

	if (m_playerSquareDistance < (m_personalSpace * m_personalSpace))
	{
		m_isScared = true;
		//std::cout << "Scared\n";
	}
	else
	{
		m_isScared = false;
	}

	if (m_isScared)
	{
		m_playerAngleIndex = (m_playerAngle / APPROX_PI) * 5; //approximates an index that allows a switch case to read the direction
	}
	else
	{
		m_playerAngleIndex = 5;
		//wandering code
	}

	switch (m_playerAngleIndex) //The same mechanism as the pig follow but all directions are flipped
	{
	case -4:
		move({ orthog_speed,0 });
		m_currentAnimation = &m_walkRight;
		m_currentAnimation->setFlipped(false);
		break;
	case -3:
		move({ diagonal_speed, diagonal_speed });
		m_currentAnimation = &m_walkDownRight;
		m_currentAnimation->setFlipped(false);
		break;
	case -2:
		move({ 0, orthog_speed });
		m_currentAnimation = &m_walkDown;
		m_currentAnimation->setFlipped(false);
		break;
	case -1:
		move({ -diagonal_speed, diagonal_speed });
		m_currentAnimation = &m_walkDownRight;
		m_currentAnimation->setFlipped(true);
		break;
	case 0:
		move({ -orthog_speed,0 });
		m_currentAnimation = &m_walkRight;
		m_currentAnimation->setFlipped(true);
		break;
	case 1:
		move({ -diagonal_speed, -diagonal_speed });
		m_currentAnimation = &m_walkUpRight;
		m_currentAnimation->setFlipped(true);
		break;
	case 2:
		move({ 0, -orthog_speed });
		m_currentAnimation = &m_walkUp;
		m_currentAnimation->setFlipped(false);
		break;
	case 3:
		move({ diagonal_speed, -diagonal_speed });
		m_currentAnimation = &m_walkUpRight;
		m_currentAnimation->setFlipped(false);
		break;
	case 4:
		move({ orthog_speed,0 });
		m_currentAnimation = &m_walkRight;
		m_currentAnimation->setFlipped(false);
		break;
	case 5:
		m_currentAnimation = &m_walkDown;
		m_currentAnimation->setFlipped(false);
		break;
	}

	if (getPosition().x < 0)
	{
		setPosition({ 0, getPosition().y });
	}
	if (getPosition().x > m_knownScreenSize.x)
	{
		setPosition({ (float)m_knownScreenSize.x, getPosition().y });
	}
	if (getPosition().y < 0)
	{
		setPosition({ getPosition().x, 0 });
	}
	if (getPosition().y > m_knownScreenSize.y)
	{
		setPosition({ getPosition().x, (float)m_knownScreenSize.y});
	}
}

void Rabbit::setPlayer(GameObject player)
{
	m_player = player;
}

void Rabbit::setKnownScreenSize(sf::Vector2u screenSize)
{
	m_knownScreenSize = screenSize;
}