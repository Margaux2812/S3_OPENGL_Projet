#version 330

in vec3 vPosition;
in vec3 vNormale;
in vec2 vTexCoord;
in vec3 vRelPosition;

out vec4 fFragColor;

uniform sampler2D u_Texture;
//uniform vec3 uLightDir;
//uniform vec3 uLightPonct;

/*L'ambiance de jour on va mettre genre 0.8 et l'ambiance de nuit 0.2*/
uniform float uAmbiantLight;

void main() {
	vec4 texColor = texture(u_Texture, vTexCoord);

	/*vec3 tmp = vRelPosition-uLightPonct;
	vec3 dirLightPixel = normalize(tmp);

	float luminositeDir = max(-dot(vNormale, uLightDir), 0.f);
	float luminositePonct = max(-dot(vNormale, dirLightPixel), 0.f)/(length(tmp)*length(tmp));

	float globalLuminosity = min(luminositeDir + luminositePonct + ambiantLight, 1.f);
*/
	vec4 ambiantLight = vec4(uAmbiantLight, uAmbiantLight, uAmbiantLight, 1.f);
    fFragColor = texColor*ambiantLight;
}
