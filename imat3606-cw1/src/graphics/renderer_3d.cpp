/*!
 * @file renderer_3d.cpp
 * @brief Implimentation file for the Renderer3D class.
 * @author George McDonagh */


// Local includes

#include "graphics/renderer_3d.h"


// Namespaces

using namespace engine::graphics;


Renderer3D::Renderer3D()
{
	m_shaderProgram = new ShaderProgram("res/shaders/debug.shader");
}

Renderer3D::~Renderer3D() { delete m_shaderProgram; }

void Renderer3D::renderScene(engine::graphics::Scene3D& scene)
{
	m_shaderProgram->enable();
	m_shaderProgram->setUniform_mat4("view", scene.getCamera().getViewMatrix().data_ptr());
	m_shaderProgram->setUniform_mat4("projection", scene.getCamera().getPerspectiveMatrix().data_ptr());
	m_shaderProgram->setUniform_3f("eye", &(scene.getCamera().position().x()));

	std::vector<engine::SceneObject*>& objects = scene.getObjects();
	for (auto it = objects.begin(); it != objects.end(); it++)
	{
		m_shaderProgram->setUniform_mat4("model", maths::Mat4(1.0f).data_ptr());
		(*it)->getComponent<MeshComponent>()->mesh()->render();
	}
}