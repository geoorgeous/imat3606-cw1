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

	//! A SceneObject component representing its 3D mesh.
	class MeshComponent : public Component
	{
	public:
		//! Mesh constructor.
		/*! @param mesh A pointer to a constant Mesh. The mesh to initialize the MeshComponent with. */
		MeshComponent(const graphics::Mesh* mesh);

		//! Mesh destructor.
		~MeshComponent() override;

		//! Get the MeshComponent's Mesh.
		/*! @return A reference to a mutable pointer to a constant Mesh. */
		const graphics::Mesh*& mesh();

	private:
		const graphics::Mesh* m_mesh; /*!< A pointer to the Mesh Asset which the MeshComponent currently has. */
	};

}