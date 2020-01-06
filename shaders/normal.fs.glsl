#version 330

in vec3 vPosition;
in vec3 vNormale;
in vec2 vTexCoord;
in vec3 vRelPosition;

out vec4 fFragColor;

uniform sampler2D u_Texture;
uniform vec3 uLightDir;
uniform mat4x3 uLightPonct;

/*L'ambiance de jour on va mettre 0.8 et l'ambiance de nuit 0.2*/
uniform float uAmbiantLight;

void main() {
	vec4 texColor = texture(u_Texture, vTexCoord);

	/*Luminosité ponctuelle
	vec3 ponct1 = normalize(uLightPonct[0]);
	vec3 ponct2 = normalize(uLightPonct[1]);
	vec3 ponct3 = normalize(uLightPonct[2]);
	vec3 ponct4 = normalize(uLightPonct[3]);

	vec3 dirLightPixel1 = normalize(vRelPosition-ponct1);
	vec3 dirLightPixel2 = normalize(vRelPosition-ponct2);
	vec3 dirLightPixel3 = normalize(vRelPosition-ponct3);
	vec3 dirLightPixel4 = normalize(vRelPosition-ponct4);

	float ponctLuminosity1 = max(-dot(vNormale, dirLightPixel1 ), 0.2);
	float ponctLuminosity2 = max(-dot(vNormale, dirLightPixel2 ), 0.2);
	float ponctLuminosity3 = max(-dot(vNormale, dirLightPixel3 ), 0.2);
	float ponctLuminosity4 = max(-dot(vNormale, dirLightPixel4 ), 0.2);

	float totalLuminosity = min(ponctLuminosity1 + ponctLuminosity2 + ponctLuminosity3 + ponctLuminosity4, 1.);
    vec4 ponctualLuminosity = vec4(totalLuminosity, totalLuminosity, totalLuminosity, 1.f);
	*/
	
	/*Luminosité directionnelle*/
	float luminositeDir = max(dot(normalize(vNormale), -uLightDir), 0.f);
	vec4 DirectionnalLight = vec4(luminositeDir, luminositeDir, luminositeDir, 1.f);
	
	vec4 ambiantLight = vec4(uAmbiantLight, uAmbiantLight, uAmbiantLight, 1.f);

	
	vec4 globalLuminosity = ambiantLight+DirectionnalLight;//+ponctualLuminosity;
    fFragColor = texColor*vec4(globalLuminosity.xyz, 1.f);
}
