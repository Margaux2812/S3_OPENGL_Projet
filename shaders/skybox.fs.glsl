#version 330

in vec3 texCoord;

uniform samplerCube uSkybox;

out vec3 fFragColor;

void main(){
	fFragColor = normalize(texCoord);
}