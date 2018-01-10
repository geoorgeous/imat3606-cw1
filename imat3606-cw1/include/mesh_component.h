#pragma once

/*! @file mesh_component.h
  * @brief Header file for MeshComponent class.
  * @author George McDonagh */


// Internal includes

#include "graphics\mesh.h"
#include "maths\maths.h"
#include "component.h"


// Namespaces

namespace engine {

	class MeshComponent : public Component
	{
	public:
		MeshComponent(const graphics::Mesh* mesh);

		~MeshComponent() override;

		const graphics::Mesh* mesh();

	private:
		const graphics::Mesh* m_mesh;
	};

}