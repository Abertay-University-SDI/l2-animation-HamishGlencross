#include "Level.h"

Level::Level(sf::RenderWindow& hwnd, Input& in) :
	BaseLevel(hwnd, in)
{
	m_sheepObject.setInput(&m_input);

	if (!m_sheepTexture.loadFromFile("gfx/sheep_sheet.png"))
	{
		std::cerr << "Error: No sheep sheet\n";
	}
	m_sheepObject.setTexture(&m_sheepTexture, true);
	m_sheepObject.setTextureRect(sf::IntRect({ 0, 0 }, { 64, 64 }));
	m_sheepObject.setSize({ 50, 50 });

	if (!m_wormTexture.loadFromFile("gfx/worm_sheet.png"))
	{
		std::cerr << "Error: No worm sheet\n";
	}
	m_wormTimer.setTexture(&m_wormTexture, true);
}

// handle user input
void Level::handleInput(float dt)
{
	m_sheepObject.handleInput(dt);
}

// Update game objects
void Level::update(float dt)
{
	if (m_gameOver) return;

	// check wall collision
	sf::Vector2f pos = m_sheepObject.getPosition();
	float radius = m_sheepObject.getCollisionBox().size.x/2.f;

	if (pos.x < 0 || pos.x + radius > m_window.getSize().x || pos.y < 0 || pos.y + radius > m_window.getSize().y)
	{
		m_gameOver = true;
		std::cout << "Game over";
	}

	m_sheepObject.update(dt);
}

// Render level
void Level::render()
{
	beginDraw();
	m_window.draw(m_sheepObject);
	endDraw();
}

