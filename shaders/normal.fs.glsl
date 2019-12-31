#version 330

in vec3 vPosition;
in vec3 vNormale;
in vec2 vTexCoord;
in vec3 vRelPosition;

out vec4 fFragColor;

uniform sampler2D u_Texture;
uniform vec3 uLightDir;
uniform vec3 uLightPonct;

uniform float ambiantLight;

void main() {
	vec4 texColor = texture(u_Texture, vTexCoord);

	vec3 tmp = vRelPosition-uLightPonct;
	vec3 dirLightPixel = normalize(tmp);

	float luminositeDir = max(-dot(vNormale, uLightDir), 0.f);
	float luminositePonct = max(-dot(vNormale, dirLightPixel), 0.f)/(length(tmp)*length(tmp));

	float globalLuminosity = min(luminositeDir + luminositePonct + ambiantLight, 1.f);

    fFragColor = texColor*globalLuminosity;
}
