#version 460 core
layout (location = 0) in vec2 pos;
uniform float x;
uniform float h;
uniform float w;

void main()
{
	gl_Position = vec4(x + w * pos.x, h * pos.y - 1, 0, 1.0);
}