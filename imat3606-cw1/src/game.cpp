/*!
 * @file game.cpp
 * @brief Implementation file for the Game class.
 * @author George McDonagh */


// Local includes

#include "game.h"
#include "utils\serializer_json.h"


// Namespaces

using namespace engine;


Game::Game()
{
	m_scenes.push_back(std::shared_ptr<graphics::Scene3D>(new graphics::Scene3D()));

	currentScene()->add(new SceneObject());

	currentScene()->getObjects()[0]->addComponent<MeshComponent>(new MeshComponent(utils::AssetManager::loadAsset<graphics::Mesh>("res/meshes/sphere.dae")));

	utils::SerializerJSON::write<graphics::Scene3D>(*currentScene());

	currentScene() = std::shared_ptr<graphics::Scene3D>(utils::SerializerJSON::read<graphics::Scene3D>("res/data/scene.json"));
}

Game::~Game() { }

void load(const char* filepath)
{

}

std::shared_ptr<graphics::Scene3D>& Game::currentScene()
{
	return m_scenes[m_currentSceneIndex];
}