#version 330

in vec3 texCoord;

uniform samplerCube uSkybox;

out vec4 fFragColor;

void main(){
	fFragColor = vec4(texCoord, 1.f); //texture(uSkybox, texCoord);
}