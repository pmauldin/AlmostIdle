#include "DebugSystem.h"

DebugSystem::DebugSystem(entt::registry& registry): m_Registry(registry), m_DebugRect(sf::Vector2f(TILE_SIZE, TILE_SIZE)) {
	m_DebugRect.setOutlineColor(sf::Color::Red);
	m_DebugRect.setOutlineThickness(2);
	m_DebugRect.setFillColor(sf::Color(0, 0, 0, 0));
}

void DebugSystem::Draw(sf::RenderWindow& window, float deltaTime) {
	auto view = m_Registry.view<PositionComponent, DebugTileComponent>();
	for (auto entity : view) {
		PositionComponent& position = m_Registry.get<PositionComponent>(entity);

		m_DebugRect.setPosition(position.getTileX() * TILE_SIZE, (position.getTileY() + 1) * TILE_SIZE);
		
		window.draw(m_DebugRect);
	}
}
