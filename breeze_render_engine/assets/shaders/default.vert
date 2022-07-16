#version 330 core
layout (location = 0) in vec3 inPosition;
layout (location = 1) in vec3 inNormal;
layout (location = 2) in vec2 inUV;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

out vec2 outUV;
out vec3 outNormal;

void main() {
	outUV = inUV;
	outNormal = normalize(vec3(model * vec4(inNormal, 0.0)));

	gl_Position = projection * view * model * vec4(inPosition, 1.0);
}