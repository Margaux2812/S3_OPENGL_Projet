#version 330
layout (location = 0) in vec3 aPos;

out vec3 texCoord;

uniform mat4 uMVPMatrix;
uniform mat4 uMVMatrix;

void main()
{
    texCoord = aPos;
    vec4 pos = uMVMatrix * vec4(aPos, 1.0);
    gl_Position = pos.xyww;
}  