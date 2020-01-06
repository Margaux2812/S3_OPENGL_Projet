#version 330

layout(location = 0) in vec3 aVertexPosition;
layout(location = 2) in vec3 aPositionCube;

uniform mat4 uMVPMatrix;
uniform mat4 uMVMatrix;
uniform mat4 uNormalMatrix;

void main() {
    gl_Position = uMVPMatrix * vec4(aVertexPosition + aPositionCube - vec3(0., 1., 3), 1);
}