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

	class SceneObject
	{
	public:
		SceneObject();

		~SceneObject();

		template <typename T>
		void addComponent(T* component)
		{
			m_components[typeid(T)] = component;
		}

		template <typename T>
		T* getComponent()
		{
			if (std::is_base_of<Component, T>())
			{
				if (m_components.find(typeid(T)) != m_components.end())
					return dynamic_cast<T*>(m_components[typeid(T)]);
			}
			else
				utils::Logger::log("WARNING::SCENE_OBJECT::GET_COMPONENT - Type argument is not a valid Component type.");

			return nullptr;
		}

		std::vector<Component*> getComponents();

	private:
		std::unordered_map<std::type_index, Component*> m_components;
	};

}