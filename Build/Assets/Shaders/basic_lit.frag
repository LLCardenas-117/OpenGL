#version 460 core

in vec2 v_texcoord;
/*flat*/ in vec3 v_color;
out vec4 f_color;

uniform float u_time;

uniform struct Material 
{
	sampler2D baseMap;
	vec3 baseColor;

	float shininess;
	vec2 tiling;
	vec2 offset;
} u_material;

void main() {
	//f_color = vec4(0, 1, 1, 1);
	//float offset = sin(u_time + (gl_FragCoord.x - gl_FragCoord.y));
	//f_color = vec4(v_color * offset, 1);

	f_color = texture(u_material.baseMap, v_texcoord) * vec4(v_color, 1); // * f_color;
}