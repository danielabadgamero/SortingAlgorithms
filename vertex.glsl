#version 460 core
layout (location = 0) in vec2 pos;
uniform int index;
uniform int val;
uniform int maxNums;

void main()
{
	gl_Position = vec4(pos, 0, 0);
}