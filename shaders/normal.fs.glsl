#version 330

in vec3 vPosition;
in vec3 vNormale;
in vec2 vTexCoord;
in vec3 vRelPosition;

out vec4 fFragColor;

uniform sampler2D u_Texture;
uniform vec3 uLightDir;
uniform vec3 uLightPonct[10];

/*L'ambiance de jour on va mettre 0.8 et l'ambiance de nuit 0.2*/
uniform float uAmbiantLight;

float getPonctLuminosity(vec3 lights){
	vec3 dirLightPixel = normalize(vRelPosition-lights);
	float ponctLuminosity = max(-dot(vNormale, dirLightPixel ), 0.);
	return ponctLuminosity;
}

void main() {
	vec4 texColor = texture(u_Texture, vTexCoord);

	/*Luminosité ponctuelle*/

	float luminositePonct = 0;
	for(int i=0; i < 10; i++){
        if(uLightPonct[i] != vec3(0,0,0)){
            luminositePonct += getPonctLuminosity(uLightPonct[i]);
        }
    }
    vec4 PonctualLight = vec4(luminositePonct, luminositePonct, luminositePonct, 1.f);
	
	/*Luminosité directionnelle*/
	float luminositeDir = max(dot(normalize(vNormale), -uLightDir), 0.f);
	vec4 DirectionnalLight = vec4(luminositeDir, luminositeDir, luminositeDir, 1.f);
	
	vec4 ambiantLight = vec4(uAmbiantLight, uAmbiantLight, uAmbiantLight, 1.f);

	
	vec4 globalLuminosity = min(ambiantLight+DirectionnalLight+PonctualLight, 1);
    fFragColor = texColor*vec4(globalLuminosity.xyz, 1.f);
}
