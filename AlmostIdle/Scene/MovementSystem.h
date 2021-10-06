#pragma once
#include <entt/entt.hpp>
#include "../constants.h"
#include "Components.h"

class MovementSystem {
public:
	MovementSystem(entt::registry& registry);

	void Update();
private:
	entt::registry& m_Registry;
};
