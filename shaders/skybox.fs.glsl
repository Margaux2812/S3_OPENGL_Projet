#version 330

in vec3 texCoord;

uniform samplerCube uSkybox;

out vec4 fFragColor;

void main(){
	fFragColor = texture(uSkybox, texCoord);
}