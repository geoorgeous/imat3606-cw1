#pragma once

/*! @file scene_3d.h 
  * @brief Header file for Scene3D class.
  * @author George McDonagh */


// External includes

#include <vector>


// Internal includes

#include "graphics\camera.h"
#include "maths\maths.h"
#include "scene_object.h"


// Namespaces

namespace engine { namespace graphics {

	//! A 3D game scene
	class Scene3D {
	public:
		Scene3D();

		~Scene3D();

		void update();

		Camera& getCamera();

		std::vector<engine::SceneObject*>& getObjects();

		void add(engine::SceneObject* sceneObject);

	private:
		Camera m_camera;

		std::vector<engine::SceneObject*> m_objects;
	};

} }