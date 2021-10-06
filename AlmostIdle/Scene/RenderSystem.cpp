#include "RenderSystem.h"

RenderSystem::RenderSystem(entt::registry& registry): m_Registry(registry) {
	
}

void RenderSystem::Draw(sf::RenderWindow& window, float deltaTime) {
	auto view = m_Registry.view<PositionComponent, SpriteComponent>();
	for (auto entity : view) {
		PositionComponent& position = m_Registry.get<PositionComponent>(entity);
		SpriteComponent& spriteComponent = m_Registry.get<SpriteComponent>(entity);

		auto sprite = spriteComponent.sprite;

		sprite.setPosition(position.getX(), position.getY());
		
		window.draw(sprite);
	}
}
