#version 330

in vec3 vPosition;
in vec3 vNormale;
in vec2 vTexCoord;
in vec3 vRelPosition;

out vec4 fFragColor;

uniform sampler2D u_Texture;
uniform vec3 uLightDir;
//uniform mat4x3 uLightPonct;

/*L'ambiance de jour on va mettre 0.8 et l'ambiance de nuit 0.2*/
uniform float uAmbiantLight;

void main() {
	vec4 texColor = texture(u_Texture, vTexCoord);

	/*vec3 tmp = vRelPosition-uLightPonct;
	vec3 dirLightPixel = normalize(tmp);

	float luminositeDir = max(-dot(vNormale, uLightDir), 0.f);
	float luminositePonct = max(-dot(vNormale, dirLightPixel), 0.f)/(length(tmp)*length(tmp));

	float globalLuminosity = min(luminositeDir + luminositePonct + ambiantLight, 1.f);
*/
	float luminositeDir = max(dot(normalize(vNormale), -uLightDir), 0.f);
	vec4 DirectionnalLight = vec4(luminositeDir, luminositeDir, luminositeDir, 1.f);
	
	vec4 ambiantLight = vec4(uAmbiantLight, uAmbiantLight, uAmbiantLight, 1.f);

	/*vec4 ponctuelleLight = vec4(0.f, 0.f, 0.f, 1.f);

	for(int i=0; i<4; i++){
		vec3 tmp = vPosition-uLightPonct[i];
		vec3 dirLightPixel = normalize(tmp);
		float luminositePonct = max(dot(normalize(vNormale), -dirLightPixel), 0.f)/(length(tmp)*length(tmp));
		ponctuelleLight += vec4(luminositePonct, luminositePonct, luminositePonct, 0.f);
	}*/


    
	vec4 globalLuminosity = ambiantLight+DirectionnalLight;
    fFragColor = texColor*vec4(globalLuminosity.xyz, 1.f);
}
