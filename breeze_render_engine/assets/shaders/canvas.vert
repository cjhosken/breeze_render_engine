#version 450 core

layout (location = 0) in vec3 inPosition;
layout (location = 1) in vec3 inNormal;
layout (location = 2) in vec2 inUV;

uniform mat4 model;

out vec2 outUV;

void main() {
	outUV = inUV;
	gl_Position = vec4(inPosition, 1.0);
}