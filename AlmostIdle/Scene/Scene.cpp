#include "Scene.h"

Scene::Scene(const sf::Font& font): 
	m_RenderSystem(m_Registry), m_PlayerSystem(m_Registry, font), m_MovementSystem(m_Registry), m_DebugSystem(m_Registry) {

}

Scene::~Scene() {}

void Scene::Update() {
	m_PlayerSystem.Update();
	m_MovementSystem.Update();
}

void Scene::Draw(sf::RenderWindow& window, float deltaTime) {
	m_RenderSystem.Draw(window, deltaTime);
	m_PlayerSystem.Draw(window, deltaTime);
	m_DebugSystem.Draw(window, deltaTime);
}

