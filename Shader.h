#ifndef SHADER_H
#define SHADER_H

#include <string>

#include <glad/glad.h>
#include <glm/gtc/type_ptr.hpp>

class Shader
{
private:
	GLuint ID{};
public:
	Shader();
	void init(const char*, const char*);
	void use() const;
	template <typename T>
	inline void setUniform(void(*uniformFunc)(GLint, T), const char* name, T value) const
	{
		uniformFunc(glGetUniformLocation(ID, name), value);
	}
	template <typename T>
	inline void setUniform(void(*uniformFunc)(GLint, GLsizei, GLboolean, T), const char* name, T value) const
	{
		uniformFunc(glGetUniformLocation(ID, name), 1, GL_FALSE, value);
	}
};

#endif