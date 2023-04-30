#ifndef COLUMN_H
#define COLUMN_H

#include <GLFW/glfw3.h>

class Column
{
private:
	float x{};
	float h{};
	bool selected{};
	GLfloat vertices[8]{};
	const GLuint indeces[6]{ 0, 1, 2, 2, 3, 0 };
public:
	Column(size_t, int, size_t, bool);
	void draw();
};

#endif