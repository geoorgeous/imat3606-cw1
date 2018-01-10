/*!
 * @file scene_object.cpp
 * @brief Implementation file for the SceneObject class.
 * @author George McDonagh */


// Local includes

#include "scene_object.h"


// Namespaces

using namespace engine;


SceneObject::SceneObject()
{

}

SceneObject::~SceneObject() { }

std::vector<Component*> SceneObject::getComponents()
{
	std::vector<Component*> components;
	components.reserve(m_components.size());

	for (auto component : m_components) {
		components.push_back(component.second);

		return components;
	}
}