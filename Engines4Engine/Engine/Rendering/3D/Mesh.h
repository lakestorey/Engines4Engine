#ifndef MESH_H
#define MESH_H

#include <glew.h>
#include <vector>
#include <glm/glm.hpp>
//.hpp specifies c++ header files,
//glm/whatever = header files in glm folder

struct Vertex {
	glm::vec3 position;
	glm::vec3 normal;
	glm::vec2 textureCoordinates;
	glm::vec3 colour; //temp for testing
};

class Mesh {
public:
	Mesh(std::vector<Vertex>& vertexList_); //using reference for faster computation.
	~Mesh();

	void Render();

private:
	void GenerateBuffers();
	GLuint VAO, VBO;
	std::vector<Vertex> vertexList;
};
#endif // !MESH_H