#version 330 core

in vec2 outUV;
in vec3 outNormal;

out vec4 FragColor;

uniform sampler2D light;

void main() {
	vec2 uv = outUV * vec2(1.0, -1.0);

    vec4 texColor = texture(light, uv);
	if (texColor.r < 0.9) {
		discard;
	} 

	vec3 color = vec3(0.9f);

	FragColor = vec4(color, 1.0)  + (0.001 * vec4(outUV + outNormal.xy, outNormal.z, 0.0));
}