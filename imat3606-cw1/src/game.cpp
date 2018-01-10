/*!
 * @file game.cpp
 * @brief Implementation file for the Game class.
 * @author George McDonagh */


// Local includes

#include "game.h"


// Namespaces

using namespace engine;


Game::Game()
{
	m_currentScene = std::shared_ptr<graphics::Scene3D>(new graphics::Scene3D());

	m_currentScene->add(new SceneObject());

	m_currentScene->getObjects()[0]->addComponent<MeshComponent>(new MeshComponent(utils::AssetManager::loadAsset<graphics::Mesh>("res/meshes/sphere.dae")));
}

Game::~Game() { }

graphics::Scene3D& Game::currentScene() const
{
	return *m_currentScene;
}