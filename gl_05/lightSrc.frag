#version 330 core
out vec4 color;

uniform float light;

void main()
{
    float color1 = light* 0.6 + 0.4;
    color = vec4(color1, color1, color1, 1.0f); // Set all 4 vector values to 1.0f
}