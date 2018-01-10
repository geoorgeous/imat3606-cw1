#pragma once

/*! @file mesh.h
  * @brief Header file for Mesh class.
  * @author George McDonagh */


// External includes

#include <assimp\Importer.hpp>
#include <assimp\mesh.h>
#include <assimp\scene.h>
#include <GL\glew.h>
#include <vector>


// Local includes

#include "asset.h"


// Namespaces

namespace engine { namespace graphics {

	//! A 3D mesh.
	/*! Contains all of a 3D mesh's data. */
	class Mesh : public Asset
	{
	public:
		//! A 3D mesh's mesh entry containing its own vertex data.
		struct MeshEntry
		{
			//! Vertex Buffer Object names.
			enum VertexBufferNames {
				VERTEX_BUFFER, 
				TEXCOORD_BUFFER, 
				NORMAL_BUFFER, 
				INDEX_BUFFER
			};

			GLuint vao; /*!< OpenGL Vertex Array Buffer handle. */
			GLuint vbo[4]; /*!< OpenGL Vertex Buffer Objects' handles - one for each of the MeshEntry's VBO type. */
			unsigned int elementCount; /*!< Number of  */

			//! MeshEntry constructor.
			/*! Constructs a MeshEntry given a pointer to an Assimp mesh object.
			  * @param mesh A pointer to an Assimp mesh. */
			MeshEntry(aiMesh* mesh);

			//! MeshEntry destructor.
			~MeshEntry();

			//! Render the MeshEntry's elements.
			void render() const;
		};

		//! Mesh constructor.
		/*! Construct a Mesh from file.
		  * @param filepath The relative path to a mesh file. */
		Mesh(const char* filepath);

		//! Mesh destructor.
		~Mesh();

		//! Load the Mesh in to memory.
		bool load() override;

		//! Release all of the Mesh's memory.
		void unload() override;

		//! Render the Mesh.
		void render() const;

	private:

		std::vector<MeshEntry*> m_entries; /*!< Collection of the Mesh's MeshEntrys. */
	};

} }