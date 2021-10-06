#include "MovementSystem.h"
#include <cmath>

MovementSystem::MovementSystem(entt::registry& registry): m_Registry(registry) {}

void MovementSystem::Update() {
	auto view = m_Registry.view<PositionComponent, MovementComponent>();

	for (auto entity : view) {
		PositionComponent& position = m_Registry.get<PositionComponent>(entity);
		MovementComponent& movementComponent = m_Registry.get<MovementComponent>(entity);

		if (position.getX() == movementComponent.x && position.getY() == movementComponent.y) {
			m_Registry.remove<MovementComponent>(entity);
			return;
		}

		// TODO Check collision
		m_Registry.patch<PositionComponent>(entity, [movementComponent](auto& pos) {
			float diffX = movementComponent.x - pos.getX();
			float diffY = movementComponent.y - pos.getY();

			float newX = pos.getX();
			float newY = pos.getY();

			if (std::abs(diffX) < movementComponent.speed) {
				newX = movementComponent.x;
			} else {
				newX += movementComponent.speed * ((diffX > 0) - (diffX < 0));
			}

			if (std::abs(diffY) < movementComponent.speed) {
				newY = movementComponent.y;
			}
			else {
				newY += movementComponent.speed * ((diffY > 0) - (diffY < 0));
			}

			pos.SetPosition(newX, newY);
		});
	}
}
