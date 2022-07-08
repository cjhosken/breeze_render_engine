#version 460 core

in vec2 outUV;

out vec4 fragColor;

void main() {
	vec2 pos_ndc = 2.0 * outUV - 1.0;
	float dist = length(pos_ndc);

	vec3 col = vec3(255.0f / 255.0f, 170.0f / 255.0f, 255.0f / 255.0f);

	vec3 outer = col / 10.0f;;
	vec3 inner = col / 5.0f;

	vec3 color = mix(inner, outer, dist);

	fragColor = vec4(color, 1.0f);
}