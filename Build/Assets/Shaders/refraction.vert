#version 460 core

// a_### = attributes/inputs
layout (location = 0) in vec3 a_position;
layout (location = 2) in vec3 a_normal;

// v_### = varyings (vertex -> fragment)
out vec3 v_texcoord;

// u_### = uniform
uniform mat4 u_model;
uniform mat4 u_view;
uniform mat4 u_projection;

uniform float u_ior = 1.3;

void main() {
	// Transform position and normal to world space
	vec3 position = vec3(u_model * vec4(a_position, 1));
	vec3 normal = normalize(mat3(u_model) * a_normal);

	// inverse of view space -> world space
	vec3 viewPosition = inverse(u_view)[3].xyz;
	vec3 viewDir = normalize(position - viewPosition);

	// get refraction vector (refract view direction abour normal)
	v_texcoord = refract(viewDir, normal, 1.0 / u_ior);

	gl_Position = u_projection * u_view * u_model * vec4(a_position, 1.0);
}