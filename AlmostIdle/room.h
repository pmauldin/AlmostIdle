#pragma once
#include <SFML/Graphics.hpp>

class Room {
public:
  Room(const sf::Font& font);
  ~Room();

  void Update();
  void Draw(sf::RenderWindow& window);
  const std::vector<int>& GetTiles(int x, int y) const;
private:
  sf::Text wallSprite;
  std::vector<std::vector<int>> tiles;
};
