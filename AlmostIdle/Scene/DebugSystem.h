#pragma once
#include <SFML/Graphics.hpp>
#include <entt/entt.hpp>
#include "Components.h"
#include "../constants.h"

class DebugSystem {
public:
	DebugSystem(entt::registry& registry);

	void Draw(sf::RenderWindow& window, float deltaTime);
private:
	entt::registry& m_Registry;
	sf::RectangleShape m_DebugRect;
};
