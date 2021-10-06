#pragma once
#include <cmath>
#include <SFML/Graphics.hpp>
#include <entt/entt.hpp>
#include "../constants.h"

struct PositionComponent {
public:
	PositionComponent(float xPos, float yPos) {
		SetPosition(xPos, yPos);
	}

	void SetPosition(float xPos, float yPos) {
		x = xPos;
		y = yPos;
	}

	float getX() { return x; }
	float getY() { return y; }
	int getTileX() { return std::round(x / TILE_SIZE); }
	int getTileY() { return std::round(y / TILE_SIZE); }
private:
	float x, y;
};

struct MovementComponent {
	float x;
	float y;
	float speed;
};

struct SpriteComponent {
	sf::Text sprite;

	SpriteComponent(sf::Text& sprite) : sprite(sprite) {}
};

struct PlayerComponent {};

struct DebugTileComponent {};

struct MapComponent
{
	int id;
	std::vector<std::vector<entt::entity>> tiles;

	MapComponent(int id, int MAP_WIDTH, int MAP_HEIGHT): tiles(MAP_WIDTH * MAP_HEIGHT, std::vector<entt::entity>(0)) {
		this->id = id;
	}
};
