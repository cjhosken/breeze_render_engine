#version 330 core

in vec2 outUV;

out vec4 fragColor;

uniform vec3 inner;
uniform vec3 outer;

void main() {
	vec2 pos_ndc = 2.0 * outUV - 1.0;
	float dist = length(pos_ndc);

	vec3 color = mix(inner, outer, dist);

	fragColor = vec4(color, 1.0f);
}