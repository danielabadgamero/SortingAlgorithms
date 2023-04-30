#version 460 core
out vec4 color;
uniform bool selected;

void main()
{
	if (selected)
		color = vec4(1, 0, 0, 1);
	else
		color = vec4(1, 1, 1, 1);
}