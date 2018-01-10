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

	class Game
	{
	public:
		Game();

		~Game();

		graphics::Scene3D& currentScene() const;

	private:
		std::shared_ptr<graphics::Scene3D> m_currentScene;
	};
	
}