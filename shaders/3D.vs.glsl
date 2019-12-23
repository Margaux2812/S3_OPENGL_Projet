#version 330

layout(location = 0) in vec3 aVertexPosition;
layout(location = 1) in vec3 aVertexNormal;
layout(location = 2) in vec3 aColor3D;
layout(location = 3) in vec3 aPositionCubes;
layout(location = 4) in vec2 aTexCoord;

out vec3 vPosition;
out vec3 vNormale;
out vec3 vColor3D;
out vec2 vTexCoord;

uniform mat4 uMVPMatrix;
uniform mat4 uMVMatrix;
uniform mat4 uNormalMatrix;

void main() {
	vPosition = vec3(uMVMatrix*vec4(aVertexPosition, 1));
	vNormale = vec3(uNormalMatrix*vec4(aVertexNormal, 0));
	vColor3D = aColor3D;
	vTexCoord = aTexCoord;
	
    gl_Position = uMVPMatrix * vec4(aVertexPosition + aPositionCubes - vec3(0., 1., 3), 1);
}
