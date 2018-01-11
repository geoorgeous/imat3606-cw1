/*!
 * @file scene_3d.cpp
 * @brief Implimentation file for the Scene3D class.
 * @author George McDonagh */


// Local includes

#include "graphics/scene_3d.h"


// Namespaces

using namespace engine::graphics;


Scene3D::Scene3D()
{
	m_camera = Camera(engine::maths::Vec3(0, 0, 15), engine::maths::Vec3(0, -1, 0), 67.0f, 1, 0.01f, 1000.0f);
}

Scene3D::~Scene3D()
{
	for (auto it : m_objects)
		delete it;

	m_objects.clear();
}

void Scene3D::update()
{

}

const Camera& Scene3D::getCamera() const
{
	return m_camera;
}

Camera& Scene3D::getCamera()
{
	return m_camera;
}

const std::vector<engine::SceneObject*>& Scene3D::getObjects() const
{
	return m_objects;
}

std::vector<engine::SceneObject*>& Scene3D::getObjects()
{
	return m_objects;
}

void Scene3D::add(engine::SceneObject* sceneObject)
{
	m_objects.push_back(sceneObject);
}