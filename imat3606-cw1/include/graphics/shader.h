#pragma once

/*!
  * @file shader.h
  * @brief Header file for the Shader class.
  * @author George McDonagh */


// External includes

#include <fstream>
#include <GL\glew.h>
#include <sstream>
#include <string>
#include <vector>


// Local includes

#include "utils\logger.h"


// Macros

#define SHADER_TYPES_COUNT 3


// Namespaces

namespace engine { namespace graphics {

	//! The different types of shaders which can be created and attached to shader programs.
	enum ShaderType
	{
		NONE = -1,
		VERTEX = 0,
		GEOMETRY = 1,
		FRAGMENT = 2
	};

	//! Shader wraps around an OpenGL shader which controls the source code for a particular shader.
	class Shader
	{
	public:
		//! Shader constructor.
		/*! Construct a shader object by specifying its type and passing its source. 
		  * @param type The Shader's ShaderType.
		  * @param cstr The Shader's source code.
		  * @warning If ShaderType::NONE is passed as the argument for @p type it will default to ShaderType::VERTEX. */
		Shader(ShaderType type, const char* source);

		//! Destructor.
		~Shader();

		//! The Shader's type.
		/*! @return The type of OpenGL shader of the Shader object's source. */
		ShaderType type() const;

		//! Get the Shader's source as a string.
		/*! @return A nonmutable reference to the Shader's stored source string. */
		const std::string& source() const;

		//! Get the Shader's OpenGL ID.
		/*! @return OpenGL ID for the Shader object. */
		GLuint id() const;

		//! Get the Shader's compilation state.
		/*! @return If the Shader successfully compiled upon creation then this function will return @p true. */
		bool compiled() const;

	private:
		ShaderType m_type; /*!< The Shader's ShaderType. */
		std::string m_source; /*!< The shader's source code stored as a string. */
		GLuint m_id; /*!< The Shader's OpenGL ID. */

		//! Copy-prohibitting copy contructor.
		/*! @param shader The Shader object to copy from.
		  * @note This is made private so a Shader object cannot be copied. Shader object's should not be copied because they delete their OpenGL shader in their destructor. */
		Shader(const Shader& shader) = delete;

		//! Copy-prohibitting assignment operator.
		/*! @param shader The shader object to assign from.
		  * @note This is made private so Shader objects cannot be reassigned another Shader. */
		Shader& operator=(const Shader& shader) = delete;
	};

} }