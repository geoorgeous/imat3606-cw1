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

	//! A 3D game scene.
	class Scene3D {
	public:
		//! Scene3D constructor.
		Scene3D();

		//! Scene3D destructor.
		~Scene3D();

		//! Update the scene's logic.
		void update();

		//! Get the scene's Camera.
		/*! @return A reference to an immutable Camera object; the scene's Camera. */
		const Camera& getCamera() const;

		//! Get the scene's Camera.
		/*! @return A reference to a mutable Camera object; the scene's Camera. */
		Camera& getCamera();

		//! Get the scene's collection of SceneObjects.
		/*! @return A reference to an immutable vector of SceneObject pointers. */
		const std::vector<engine::SceneObject*>& getObjects() const;

		//! Get the scene's collection of SceneObjects.
		/*! @return A reference to a mutable vector of SceneObject pointers. */
		std::vector<engine::SceneObject*>& getObjects();

		//! Add a SceneObject to the scene.
		/*! @param sceneObject A pointer to a new SceneObject to be added to the scene. */
		void add(engine::SceneObject* sceneObject);

	private:
		Camera m_camera; /*!< The scene's Camera. */
		std::vector<engine::SceneObject*> m_objects; /*!< The scene's collection of SceneObjects. */
	};

} }