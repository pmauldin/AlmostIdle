#include "room.h"
#include "constants.h"

static const int MAP_WIDTH = 21;
static const int MAP_HEIGHT = 16;

Room::Room(const sf::Font& font): tiles(MAP_WIDTH * MAP_HEIGHT, std::vector<int>(0)) {
  wallSprite.setFont(font);
  wallSprite.setString('#');
  wallSprite.setCharacterSize(CHARACTER_SIZE);
  wallSprite.setFillColor(sf::Color::Black);
  wallSprite.setStyle(sf::Text::Bold);

  for (int x = 0; x < MAP_WIDTH; x++) {
      for (int y = 0; y < MAP_HEIGHT; y++) {
          if (x == 0 || x == MAP_WIDTH - 1 || y == 0 || y == MAP_HEIGHT - 1 || x == 12) {
              if (x == MAP_WIDTH - 1 && y == (int)8) {
                tiles.at(x + y * MAP_WIDTH).push_back(2);
              } else if (!(x == 12 && y == 4)) {
                tiles.at(x + y * MAP_WIDTH).push_back(1);
              }
          };
      }
  }

}

Room::~Room() {}

const std::vector<int>& Room::GetTiles(int x, int y) const {
    return tiles.at(x + y * MAP_WIDTH);
}

void Room::Update() {}

void Room::Draw(sf::RenderWindow& window) {
    for (int x = 0; x < MAP_WIDTH; x++) {
        for (int y = 0; y < MAP_HEIGHT; y++) {
            if (GetTiles(x, y).size() == 0) continue;

            if (GetTiles(x, y).at(0) > 1) continue;

            wallSprite.setPosition(x * TILE_SIZE, y * TILE_SIZE);
            window.draw(wallSprite);
        }
    }
}
