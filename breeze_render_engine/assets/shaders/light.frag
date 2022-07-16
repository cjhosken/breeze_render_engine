#version 330 core

in vec2 outUV;

out vec4 FragColor;

uniform sampler2D light;
uniform mat4 view;

void main() {
	vec2 uv = outUV * vec2(1.0, -1.0);

    vec4 texColor = texture(light, uv);
	if (texColor.r < 0.9) {
		discard;
	} 

	FragColor = vec4(vec3(0.9), 1.0);
}