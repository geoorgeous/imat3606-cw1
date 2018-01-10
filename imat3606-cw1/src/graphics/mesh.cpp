/*!
 * @file mesh.cpp
 * @brief Implimentation file for the Mesh class.
 * @author George McDonagh */


// Local includes

#include "graphics/mesh.h"


// Namespaces

using namespace engine::graphics;


engine::graphics::Mesh::MeshEntry::MeshEntry(aiMesh* mesh)
{
	// Vertex buffers NULL by default.
	vbo[VERTEX_BUFFER] = NULL;
	vbo[TEXCOORD_BUFFER] = NULL;
	vbo[NORMAL_BUFFER] = NULL;
	vbo[INDEX_BUFFER] = NULL;

	// Generate our meshes Vertex Array Object to store it's buffer states.
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	elementCount = mesh->mNumFaces * 3;

	// Vertex position data.
	if (mesh->HasPositions()) 
	{
		float *vertices = new float[mesh->mNumVertices * 3];

		// Get the raw data from the Assimp mesh.
		for (int i = 0; i < mesh->mNumVertices; ++i) 
		{
			vertices[i * 3] = mesh->mVertices[i].x;
			vertices[i * 3 + 1] = mesh->mVertices[i].y;
			vertices[i * 3 + 2] = mesh->mVertices[i].z;
		}

		// Generate, bind, and fill VBO for vertex positions.
		glGenBuffers(1, &vbo[VERTEX_BUFFER]);
		glBindBuffer(GL_ARRAY_BUFFER, vbo[VERTEX_BUFFER]);
		glBufferData(GL_ARRAY_BUFFER, 3 * mesh->mNumVertices * sizeof(GLfloat), vertices, GL_STATIC_DRAW);

		// Set vertex attribute [0] for currently bound buffer: 3 x GL_FLOATs
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);
		glEnableVertexAttribArray(0);

		delete[] vertices;
	}

	// Vertex UV/Texture Coordinate data.
	if (mesh->HasTextureCoords(0)) 
	{
		float *texCoords = new float[mesh->mNumVertices * 2];

		// Get the raw data from the Assimp mesh.
		for (int i = 0; i < mesh->mNumVertices; ++i) 
		{
			texCoords[i * 2] = mesh->mTextureCoords[0][i].x;
			texCoords[i * 2 + 1] = mesh->mTextureCoords[0][i].y;
		}

		// Generate, bind, and fill VBO for vertex texture coordinates.
		glGenBuffers(1, &vbo[TEXCOORD_BUFFER]);
		glBindBuffer(GL_ARRAY_BUFFER, vbo[TEXCOORD_BUFFER]);
		glBufferData(GL_ARRAY_BUFFER, 2 * mesh->mNumVertices * sizeof(GLfloat), texCoords, GL_STATIC_DRAW);

		// Set vertex attribute [1] for currently bound buffer: 2 x GL_FLOATs.
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, NULL);
		glEnableVertexAttribArray(1);

		delete[] texCoords;
	}

	// Vertex normal data.
	if (mesh->HasNormals()) 
	{
		float *normals = new float[mesh->mNumVertices * 3];

		// Get raw normal data from Assimp mesh.
		for (int i = 0; i < mesh->mNumVertices; ++i) 
		{
			normals[i * 3] = mesh->mNormals[i].x;
			normals[i * 3 + 1] = mesh->mNormals[i].y;
			normals[i * 3 + 2] = mesh->mNormals[i].z;
		}

		// Generate, bind, fill VBO for vertex normals.
		glGenBuffers(1, &vbo[NORMAL_BUFFER]);
		glBindBuffer(GL_ARRAY_BUFFER, vbo[NORMAL_BUFFER]);
		glBufferData(GL_ARRAY_BUFFER, 3 * mesh->mNumVertices * sizeof(GLfloat), normals, GL_STATIC_DRAW);

		// Set vertex attribute [2] for currently bound buffer: 3 x GL_FLOATs.
		glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 0, NULL);
		glEnableVertexAttribArray(2);

		delete[] normals;
	}

	// Index buffer data.
	if (mesh->HasFaces()) 
	{
		unsigned int *indices = new unsigned int[mesh->mNumFaces * 3];
		
		// Get raw vertex indices from Assimp mesh.
		for (int i = 0; i < mesh->mNumFaces; ++i)
		{
			indices[i * 3] = mesh->mFaces[i].mIndices[0];
			indices[i * 3 + 1] = mesh->mFaces[i].mIndices[1];
			indices[i * 3 + 2] = mesh->mFaces[i].mIndices[2];
		}

		// Generate, bind, and fill VBO for the meshes faces' vertex indices.
		glGenBuffers(1, &vbo[INDEX_BUFFER]);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vbo[INDEX_BUFFER]);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, 3 * mesh->mNumFaces * sizeof(GLuint), indices, GL_STATIC_DRAW);

		// Set vertex attribute [3] for currently bound buffer: 3 x GL_FLOAT.
		glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, 0, NULL);
		glEnableVertexAttribArray(3);

		delete[] indices;
	}

	// Tidy up... unbind buffers.
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

engine::graphics::Mesh::MeshEntry::~MeshEntry() 
{
	// Realease all used buffer memory.

	if (vbo[VERTEX_BUFFER])
		glDeleteBuffers(1, &vbo[VERTEX_BUFFER]);

	if (vbo[TEXCOORD_BUFFER])
		glDeleteBuffers(1, &vbo[TEXCOORD_BUFFER]);

	if (vbo[NORMAL_BUFFER])
		glDeleteBuffers(1, &vbo[NORMAL_BUFFER]);

	if (vbo[INDEX_BUFFER])
		glDeleteBuffers(1, &vbo[INDEX_BUFFER]);

	glDeleteVertexArrays(1, &vao);
}

void engine::graphics::Mesh::MeshEntry::render() const
{
	glBindVertexArray(vao);
	glDrawElements(GL_TRIANGLES, elementCount, GL_UNSIGNED_INT, NULL);
	glBindVertexArray(0);
}

engine::graphics::Mesh::Mesh(const char* filepath)
	: Asset(filepath)
{
	load();
}

engine::graphics::Mesh::~Mesh() 
{ 
	unload();
}

void engine::graphics::Mesh::load()
{
	if (!m_isLoaded)
	{
		Assimp::Importer importer;
		const aiScene* scene = importer.ReadFile(m_filepath, NULL);

		// Make sure load error string is reset.

		m_loadErrorString = "";

		if (!scene)
			m_loadErrorString = importer.GetErrorString();
		else
		{
			for (int i = 0; i < scene->mNumMeshes; ++i)
				m_entries.push_back(new Mesh::MeshEntry(scene->mMeshes[i]));

			m_isLoaded = true;
		}
	}
}

void engine::graphics::Mesh::unload()
{
	if (m_isLoaded)
	{
		// Destroy all mesh entries so to release all their memory.

		for (int i = 0; i < m_entries.size(); ++i)
			delete m_entries.at(i);

		m_entries.clear();

		m_isLoaded = false;
	}
}

void engine::graphics::Mesh::render() const
{
	for (int i = 0; i < m_entries.size(); ++i)
		m_entries.at(i)->render();
}