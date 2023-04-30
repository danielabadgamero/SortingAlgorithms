#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Column.h"
#include "Shader.h"

Column::Column(size_t index, int value, size_t max, bool selected) : selected{ selected }
{
	x = (static_cast<float>(index) / max) * 2 - 1;
	h = (static_cast<float>(value) / max) * 2 - 1;
	float w{ 2.0f / max };
	vertices[0] = x;
	vertices[1] = 0;

	vertices[2] = x + w;
	vertices[3] = 0;

	vertices[4] = x + w;
	vertices[5] = h;

	vertices[6] = x;
	vertices[7] = h;
}

void Column::draw()
{
	Shader shader{};
	shader.init("vertex.glsl", "fragment.glsl");
	shader.use();
	shader.setUniform(glUniform1i, "selected", static_cast<int>(selected));

	GLuint VAO{};
	GLuint VBO{};
	GLuint EBO{};
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);

	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indeces), indeces, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), (void*)(0 * sizeof(GLfloat)));
	glEnableVertexAttribArray(0);
	
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}