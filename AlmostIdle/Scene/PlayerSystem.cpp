#include "PlayerSystem.h"
#include <imgui.h>

static const int INPUT_COOLDOWN = 80;

PlayerSystem::PlayerSystem(entt::registry& registry, const sf::Font& font): m_Registry(registry) {
	m_Player = registry.create();

	sf::Text sprite;
	sprite.setFont(font);
	sprite.setString("@");
	sprite.setCharacterSize(CHARACTER_SIZE);
	sprite.setStyle(sf::Text::Bold);
	sprite.setFillColor(sf::Color(255, 215, 0));

	registry.emplace<PositionComponent>(m_Player, 7 * TILE_SIZE, 4 * TILE_SIZE);
	registry.emplace<SpriteComponent>(m_Player, sprite);
	registry.emplace<PlayerComponent>(m_Player);
	registry.emplace<DebugTileComponent>(m_Player);

	cooldown = 200.0f;
}

sf::Vector2i getPlayerMove();

void PlayerSystem::Update() {
	cooldown += MS_PER_UPDATE;
	
	if (cooldown < INPUT_COOLDOWN) return;

	sf::Vector2i playerMove = getPlayerMove();
	if (playerMove.x == 0 && playerMove.y == 0) return;

	cooldown = 0;

	//if (playerMove.x != 0 && playerMove.y != 0) {
	//	playerMove.y = 0; // prioritize horizontal movement
	//}

	auto pos = m_Registry.get<PositionComponent>(m_Player);

	float destinationX = (pos.getTileX() + playerMove.x) * TILE_SIZE;
	float destinationY = (pos.getTileY() + playerMove.y) * TILE_SIZE;

	m_Registry.emplace_or_replace<MovementComponent>(m_Player, destinationX, destinationY, 2.0f);
}

void PlayerSystem::Draw(sf::RenderWindow& window, float deltaTime) {
	auto pos = m_Registry.get<PositionComponent>(m_Player);
	ImGui::Begin("AlmostIdle");
	ImGui::Text("Player tile position: %i, %i", pos.getTileX(), pos.getTileY());
	ImGui::End();
}

sf::Vector2i getPlayerMove() {
	sf::Vector2i playerMove;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		playerMove.x -= 1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		playerMove.x += 1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		playerMove.y -= 1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		playerMove.y += 1;
	}

	return playerMove;
}
