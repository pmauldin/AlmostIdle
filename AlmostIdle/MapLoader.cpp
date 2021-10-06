#include "MapLoader.h"
#include "Scene/Components.h"

void MapLoader::LoadMap(entt::registry registry) {
	// TODO Read in from file
	int mapWidth = 30;
	int mapHeight = 20;

	auto entity = registry.create();

	auto map = registry.emplace<MapComponent>(entity, 0, mapWidth, mapHeight);

    for (int x = 0; x < mapWidth; x++) {
        for (int y = 0; y < mapHeight; y++) {
            if (x == 0 || x == mapWidth - 1 || y == 0 || y == mapHeight - 1 || x == 12 || x == 23) {
                if (x == mapWidth - 1 && y == (int)8) {
                    map.tiles.at(x + y * mapWidth).push_back(registry.create());
                }
                else if (!(x == 12 && y == 4)) {
                    map.tiles.at(x + y * mapHeight).push_back(registry.create());
                }
            };
        }
    }
}
