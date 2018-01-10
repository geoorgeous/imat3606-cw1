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


	class Mesh : public Asset
	{
	public:
		struct MeshEntry
		{
			enum VertexBufferNames {
				VERTEX_BUFFER, 
				TEXCOORD_BUFFER, 
				NORMAL_BUFFER, 
				INDEX_BUFFER
			};

			GLuint vao, vbo[4];

			unsigned int elementCount;

			MeshEntry(aiMesh* mesh);

			~MeshEntry();

			void render() const;
		};

		Mesh(const char* filepath);

		~Mesh();

		void load() override;

		void unload() override;

		void render() const;

	private:

		std::vector<MeshEntry*> m_entries;
	};

} }