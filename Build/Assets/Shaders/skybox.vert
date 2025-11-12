#version 460 core

// a_### = attributes/inputs
layout (location = 0) in vec3 a_position;

// v_### = varyings (vertex -> fragment)
out vec3 v_texcoord;

// u_### = uniform
uniform mat4 u_model;
uniform mat4 u_view;
uniform mat4 u_projection;

void main() {
	v_texcoord = a_position;

	mat4 vp = u_projection * mat4(mat3(u_view));

	gl_Position = vp * vec4(a_position, 1.0);
}