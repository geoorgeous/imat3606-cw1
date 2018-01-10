/*!
  * @file shader.cpp
  * @brief Implimentation file for the Shader class.
  * @author George McDonagh */


// Local includes

#include "graphics/shader_program.h"


// Namespaces

using namespace engine::graphics;


ShaderProgram::ShaderProgram(const char* filepath)
	: Asset(filepath)
{
	load();
}

ShaderProgram::~ShaderProgram()
{
	unload();
}

void ShaderProgram::load()
{
	if (!m_isLoaded)
	{
		m_id = glCreateProgram();

		std::ifstream stream(m_filepath);

		if (stream.is_open())
		{
			std::string line;
			std::stringstream ss[SHADER_TYPES_COUNT];
			graphics::ShaderType sourceType = graphics::ShaderType::NONE;

			while (std::getline(stream, line))
			{
				if (line.find("#shader") != std::string::npos)
				{
					if (line.find("vertex") != std::string::npos)
						sourceType = graphics::ShaderType::VERTEX;
					else if (line.find("geometry") != std::string::npos)
						sourceType = graphics::ShaderType::GEOMETRY;
					else if (line.find("fragment") != std::string::npos)
						sourceType = graphics::ShaderType::FRAGMENT;
				}
				else if (sourceType != graphics::ShaderType::NONE)
					ss[sourceType] << line << std::endl;
			}

			Shader* shaders[SHADER_TYPES_COUNT];
			for (int s = 0; s < SHADER_TYPES_COUNT; s++)
			{
				shaders[s] = nullptr;

				const std::string source = ss[s].str();
				if (source != "")
				{
					shaders[s] = new Shader((graphics::ShaderType)s, source.c_str());
					attachShader(shaders[s]);
				}
			}

			link();

			for (int s = 0; s < SHADER_TYPES_COUNT; s++)
				if (shaders[s] != nullptr)
					delete shaders[s];
		}
		else
			m_loadErrorString = "Failed to open shader program file.";

		if (linked())
			m_isLoaded = true;
	}
}

void ShaderProgram::unload()
{
	if (m_isLoaded)
	{
		glDeleteProgram(m_id);
		m_isLoaded = false;
	}
}

void ShaderProgram::link() const
{
	GL_CALL(glLinkProgram(m_id));

	if (!linked())
	{
		GLint maxLength = 0;
		glGetProgramiv(m_id, GL_INFO_LOG_LENGTH, &maxLength);

		std::vector<GLchar> errorLog(maxLength);
		glGetProgramInfoLog(m_id, maxLength, &maxLength, &errorLog[0]);

		utils::Logger::log("ERROR::SHADER_PROGRAM::LINK - Shader program \"%s\" failed to link:\n%s.\n", m_filepath, errorLog.data());

		glDeleteProgram(m_id); 
	}
}

GLuint ShaderProgram::getID() const
{
	return m_id;
}

GLuint ShaderProgram::getUniformLoc(const char* uniformName) const
{
	GLint loc = glGetUniformLocation(m_id, uniformName);

	if (loc == -1)
		utils::Logger::log("ERROR::SHADER_PROGRAM::GET_UNIFORM_LOC - Cannot find uniform \"%s\".\n", uniformName);

	return loc;
}

void ShaderProgram::setUniform_1i(const char* uniformName, const GLint i) const
{
	GL_CALL(glUniform1i(getUniformLoc(uniformName), i));
}

void ShaderProgram::setUniform_1f(const char* uniformName, const GLfloat f) const
{
	GL_CALL(glUniform1f(getUniformLoc(uniformName), f));
}

void ShaderProgram::setUniform_2f(const char* uniformName, const GLfloat f[2]) const
{
	GL_CALL(glUniform2f(getUniformLoc(uniformName), f[0], f[1]));
}

void ShaderProgram::setUniform_3f(const char* uniformName, const GLfloat f[3]) const
{
	GL_CALL(glUniform3f(getUniformLoc(uniformName), f[0], f[1], f[2]));
}

void ShaderProgram::setUniform_4f(const char* uniformName, const GLfloat f[4]) const
{
	GL_CALL(glUniform4f(getUniformLoc(uniformName), f[0], f[1], f[2], f[3]));
}

void ShaderProgram::setUniform_mat4(const char* uniformName, const GLfloat f[16]) const
{
	GL_CALL(glUniformMatrix4fv(getUniformLoc(uniformName), 1, GL_FALSE, f));
}

void ShaderProgram::enable() const
{
	if (m_id)
		GL_CALL(glUseProgram(m_id));
}

bool ShaderProgram::linked() const
{
	GLint isLinked = 0;
	glGetProgramiv(m_id, GL_LINK_STATUS, &isLinked);
	return isLinked != GL_FALSE;
}

void ShaderProgram::attachShader(const Shader* shader) const
{
	glAttachShader(m_id, shader->id());
}