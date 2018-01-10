#pragma once

/*!
  * @file renderer_3d.h
  * @brief Header file for the Renderer3D class.
  * @author George McDonagh */


// External includes

#include <GL\glew.h>
#include <GLFW\glfw3.h>


// Local includes

#include "graphics\scene_3d.h"
#include "graphics\shader_program.h"
#include "maths\maths.h"
#include "mesh_component.h"


// Namespaces

namespace engine { namespace graphics {

	//! Responsible for 3D rendering.
	class Renderer3D {
	public:
		//! Renderer3D constructor.
		Renderer3D();

		//! Renderer3D destructor.
		~Renderer3D();

		//! Renders a given Scene3D.
		/*! @param scene The 3D scene to be rendered by the renderer. */
		void renderScene(graphics::Scene3D& scene);

	private:
		ShaderProgram* m_shaderProgram; /*!< Pointer to the ShaderProgram which the renderer will use while rendering. */
	};

} }