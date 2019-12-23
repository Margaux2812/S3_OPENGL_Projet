#version 330

in vec3 vPosition;
in vec3 vNormale;
in vec3 vColor3D;
in vec2 vTexCoord;

out vec4 fFragColor;

uniform sampler2D u_Texture;

void main() {
	vec4 texColor = texture(u_Texture, vTexCoord);

	//Comment on calculait la couleur du vecteur
	//fFragColor = normalize(vColor3D);
    fFragColor = texColor;
}
