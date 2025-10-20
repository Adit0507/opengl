#version 330 core
out vec4 FragColor;

in vec3 ourColor;
in vec2 TexCoord;

uniform sampler2D t1;
uniform sampler2D t2;

void main()
{
    FragColor = mix(texture(t1, TexCoord), texture(t2, TexCoord), 0.2);
}