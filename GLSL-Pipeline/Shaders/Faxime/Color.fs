#version 130

in vec4 fragColor;
in vec2 fragUV;

out vec4 color;

uniform float time;

void main()
{
	//color = fragColor;

	
	color = vec4(fragColor.r*(cos(time)+ 1.0)*0.5,
				 fragColor.g*(cos(time + 2) + 1.0)*0.5,
				 fragColor.b*(cos(time + 5) + 1.0)*0.5, 
				 fragColor.a);
}