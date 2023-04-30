#version 460 core
out vec4 color;
uniform int selected;

void main()
{
	if (selected == 1)
		color = vec4(1, 0, 0, 1);
	else
		color = vec4(1, 1, 1, 1);
}