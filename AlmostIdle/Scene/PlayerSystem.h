#pragma once
#include <SFML/Graphics.hpp>
#include <entt/entt.hpp>
#include "../constants.h"
#include "Components.h"

class PlayerSystem {
public:
	PlayerSystem(entt::registry& registry, const sf::Font& font);

	void Update();
	void Draw(sf::RenderWindow& window, float deltaTime);
private:
	entt::registry& m_Registry;
	entt::entity m_Player;
	float cooldown;
};
