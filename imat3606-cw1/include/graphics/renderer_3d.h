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


namespace engine { namespace graphics {

	class Renderer3D {
	public:
		Renderer3D();

		~Renderer3D();

		void renderScene(graphics::Scene3D& scene);

	private:
		ShaderProgram* m_shaderProgram;
	};

} }