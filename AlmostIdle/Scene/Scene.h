#pragma once

#include "RenderSystem.h"
#include "PlayerSystem.h"
#include "MovementSystem.h"
#include "DebugSystem.h"

class Scene {
public:
	Scene(const sf::Font& font);
	~Scene();

	void Update();
	void Draw(sf::RenderWindow& window, float deltaTime);
private:
	entt::registry m_Registry;
	RenderSystem m_RenderSystem;
	PlayerSystem m_PlayerSystem;
	MovementSystem m_MovementSystem;
	DebugSystem m_DebugSystem;
};