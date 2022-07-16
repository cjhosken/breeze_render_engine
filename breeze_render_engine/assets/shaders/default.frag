#version 330 core

in vec2 outUV;
in vec3 outNormal;

out vec4 FragColor;

struct Material {
	vec3 color;
	float roughness;
	float specular;
};

uniform Material material;
uniform sampler2D matcap;
uniform mat4 view;

void main() {
	vec2 muv = vec2(view * vec4(normalize(outNormal), 0))*0.5+vec2(0.5,0.5);

	FragColor = texture(matcap, vec2(muv.x, 1.0-muv.y)) * vec4(material.color, 1.0f);
}