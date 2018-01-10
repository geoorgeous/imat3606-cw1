#pragma once

/*!
  * @file scene_object.h 
  * @brief Header file for SceneObject class.
  * @author George McDonagh */


// External includes

#include <typeindex>
#include <unordered_map>
#include <vector>


// Internal includes

#include "component.h"


// Namespaces

namespace engine {

	//! An object within a scene.
	class SceneObject
	{
	public:
		//! SceneObject constructor.
		SceneObject();

		//! SceneObject destructor.
		~SceneObject();

		//! Add a component to the SceneObject.
		/*! @param component A pointer to the new Component object to give to the SceneObject. */
		template <typename T>
		void addComponent(T* component)
		{
			// Using the Component type as the component's key in the map of the SceneObject's components.
			// ... this limits the SceneObject to have only one component of each Component type.
			m_components[typeid(T)] = component;
		}

		//! Get the component of of type @p T.
		/*! @return A pointer to the retrieved component. Returns @p nullptr if no component of type @p T exists. */
		template <typename T>
		T* getComponent()
		{
			// Only bother to attempt to find the component if it is a valid Component type.
			if (std::is_base_of<Component, T>())
			{
				if (m_components.find(typeid(T)) != m_components.end())
					return dynamic_cast<T*>(m_components[typeid(T)]);
			}
			else
				utils::Logger::log("WARNING::SCENE_OBJECT::GET_COMPONENT - Type argument \"%s\" is not a valid Component type.", typeid(T).name());

			return nullptr;
		}

		//! Get the collection of SceneObject components.
		/*! @return A vector of pointers to Components. */
		std::vector<Component*> getComponents();

	private:
		std::unordered_map<std::type_index, Component*> m_components; /*!< An unordered map of pointers to Components. The Component type is used as the key. */
	};

}