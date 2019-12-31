#version 330

layout(location = 0) in vec3 aVertexPosition;
layout(location = 1) in vec3 aColor;
layout(location = 2) in vec3 aPositionCube;

out vec3 vColor;

uniform mat4 uMVPMatrix;
uniform mat4 uMVMatrix;
uniform mat4 uNormalMatrix;

void main() {
    vColor = aColor;
    gl_Position = uMVPMatrix * vec4(aVertexPosition + aPositionCube - vec3(0., 1., 3), 1);
}