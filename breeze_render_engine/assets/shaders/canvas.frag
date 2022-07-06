#version 460 core

in vec2 outUV;

out vec4 fragColor;

void main() {
	vec2 pos_ndc = 2.0 * outUV - 1.0;
	float dist = length(pos_ndc);

	vec3 outer = vec3(0.10f, 0.1f, 0.1f);
	vec3 inner = vec3(0.05f, 0.05f, 0.075f);

	vec3 color = mix(inner, outer, dist);

	fragColor = vec4(color, 1.0f);
}