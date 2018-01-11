#pragma once

/*!
  * @file game.h 
  * @brief Header file for Game class.
  * @author George McDonagh */


// External includes

#include <memory>


// Internal includes

#include "graphics\scene_3d.h"
#include "utils\asset_manager.h"
#include "mesh_component.h"


// Namespaces

namespace engine {

	//! A class for a game within the engine.
	class Game
	{
	public:
		//! Game constructor.
		Game();

		//! Game destructor.
		~Game();

		void load(const char* filepath);

		std::shared_ptr<graphics::Scene3D>& currentScene();

	private:
		 int m_currentSceneIndex;
		 std::vector<std::shared_ptr<graphics::Scene3D>> m_scenes;
	};
	
}