#pragma once
#include "Framework/Animation.h"
#include "Framework/GameObject.h"
class Worm : public GameObject
{
public:
	Worm();
	virtual ~Worm() = default;

	void update(float dt);

private:

	Animation m_wiggleRight;

};

