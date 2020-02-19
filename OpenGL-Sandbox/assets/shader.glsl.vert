#version 450 core

layout (location = 0) in vec3 a_Position;

uniform mat4 u_ViewProj;
uniform mat4 u_Transform;

void main()
{
	gl_Position = u_ViewProj * u_Transform * vec4(a_Position, 1.0);
}
