/*!
 * @file mesh_component.cpp
 * @brief Implementation file for the MeshComponent class.
 * @author George McDonagh */


// Local includes

#include "utils\asset_manager.h"
#include "mesh_component.h"


// Namespaces

using namespace engine;


MeshComponent::MeshComponent(const graphics::Mesh* mesh)
	: Component()
{
	m_mesh = mesh;
}

MeshComponent::~MeshComponent() { }

const graphics::Mesh*& MeshComponent::mesh()
{
	return m_mesh;
}