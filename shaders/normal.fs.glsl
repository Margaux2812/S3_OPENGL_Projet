#version 330

in vec3 vPosition;
in vec3 vNormale;
in vec3 vColor3D;

out vec3 fFragColor;

void main() {
    fFragColor = normalize(vColor3D);
}
