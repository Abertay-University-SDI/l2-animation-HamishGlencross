#include "Level.h"

Level::Level(sf::RenderWindow& hwnd, Input& in) :
	BaseLevel(hwnd, in)
{
	m_sheepPlayer.setInput(&m_input);

	if (!m_sheepTexture.loadFromFile("gfx/sheep_sheet.png"))
	{
		std::cerr << "Error: No sheep sheet\n";
	}
	m_sheepPlayer.setTexture(&m_sheepTexture, true);
	m_sheepPlayer.setTextureRect(sf::IntRect({ 0, 0 }, { 64, 64 }));
	m_sheepPlayer.setSize({ 50, 50 });
	m_sheepPlayer.setPosition({ 400, 300 });

	if (!m_wormTexture.loadFromFile("gfx/worm_sheet.png"))
	{
		std::cerr << "Error: No worm sheet\n";
	}
	m_wormTimer.setTexture(&m_wormTexture, true);
	m_wormTimer.setTextureRect(sf::IntRect({ 0, 0 }, { 64, 64 }));
	m_wormTimer.setSize({ 50, 50 });

	if (!m_pigTexture.loadFromFile("gfx/pig_sheet.png"))
	{
		std::cerr << "Error: No pig sheet\n";
	}
	m_pigEnemy.setTexture(&m_pigTexture, true);
	m_pigEnemy.setTextureRect(sf::IntRect({ 0, 0 }, { 64, 64 }));
	m_pigEnemy.setSize({ 50, 50 });
	//m_pigEnemy.setPosition({ rand() % m_window.getSize().x, rand() % m_window.getSize().y });

	if (!m_rabbitTexture.loadFromFile("gfx/rabbit_sheet.png"))
	{
		std::cerr << "Error: No rabbit sheet\n";
	}
	m_rabbit.setTexture(&m_rabbitTexture, true);
	m_rabbit.setTextureRect(sf::IntRect({ 0, 0 }, { 64, 64 }));
	m_rabbit.setSize({ 50, 50 });
	m_rabbit.setPosition({ 200, 200 });
	//m_rabbit.setPosition({ rand() % m_window.getSize().x, rand() % m_window.getSize().y });
}

// handle user input
void Level::handleInput(float dt)
{
	m_sheepPlayer.handleInput(dt);
}

// Update game objects
void Level::update(float dt)
{
	if (m_input.isKeyDown(sf::Keyboard::Scancode::Space) && m_gameOver)
	{
		std::cout << "Reset Game\n";

		m_gameOver = false;
		m_wormTimer.setTimer(m_wormTimer.getTimerLength());
		m_sheepPlayer.resetPosition();
	}

	m_sheepPlayer.setKnownScreenSize(m_window.getSize());
	m_pigEnemy.setKnownScreenSize(m_window.getSize());
	m_wormTimer.setKnownScreenSize(m_window.getSize());
	m_rabbit.setKnownScreenSize(m_window.getSize());

	if (m_gameOver) return;

	m_pigEnemy.setTarget(m_sheepPlayer);
	m_rabbit.setPlayer(m_sheepPlayer);

	// check wall collision
	sf::Vector2f pos = m_sheepPlayer.getPosition();
	float radius = m_sheepPlayer.getCollisionBox().size.x / 2.f;

	if (pos.x < 0 || pos.x + radius > m_window.getSize().x || pos.y < 0 || pos.y + radius > m_window.getSize().y)
	{
		m_gameOver = true;
		std::cout << "Game over\n";
	}

	m_sheepPlayer.update(dt);
	m_pigEnemy.update(dt);
	m_wormTimer.update(dt);
	m_rabbit.update(dt);

	if (m_wormTimer.getTimer() < 0)
	{
		m_gameOver = true;
		std::cout << "Game over";
	}
}

bool Level::isGameOver()
{
	return m_gameOver;
}

// Render level
void Level::render()
{
	beginDraw();
	m_window.draw(m_sheepPlayer);
	m_window.draw(m_pigEnemy);
	m_window.draw(m_wormTimer);
	m_window.draw(m_rabbit);
	endDraw();
}