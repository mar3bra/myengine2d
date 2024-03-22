#version 450 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;
layout (location = 2) in vec2 aTexCoord;

uniform vec3 col;

out vec3 ourColor;
out vec2 TexCoord;

uniform mat4 view;
uniform mat4 projection;
uniform mat4 model;
uniform vec2 tilePos;


void main()
{
    gl_Position = projection * view * model * vec4(aPos, 1.0);
	TexCoord = aTexCoord + tilePos;
    ourColor = col;
}