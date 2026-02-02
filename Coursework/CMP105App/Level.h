#pragma once

#include "Framework/BaseLevel.h"
#include "Framework/GameObject.h"
#include "Sheep.h"
#include "Worm.h"
#include "Pig.h"

class Level : BaseLevel {
public:
	Level(sf::RenderWindow& window, Input& input);
	~Level() override = default;

	void handleInput(float dt) override;
	void update(float dt);
	void render();

	bool isGameOver();

private:
	// Default functions for rendering to the screen.

	// Default variables for level class.
	bool m_gameOver = false;

	Sheep m_sheepPlayer;
	sf::Texture m_sheepTexture;

	Worm m_wormTimer;
	sf::Texture m_wormTexture;

	Pig m_pigEnemy;
	sf::Texture m_pigTexture;
};