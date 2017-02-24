#version 130

// In Variables
in vec4 fragColor;
in vec2 fragUV;

// Out Variables
out vec4 color;

// Uniform Variables
uniform sampler2D _MainTex;
uniform float time;

void main()
{
	vec4 _MainTexColor = texture(_MainTex, fragUV);

	//color = fragColor;
	//color = _MainTexColor;

	color = vec4((_MainTexColor.r * fragColor.r)*(cos(time * 8.0F) + 1.0F)*0.5F, 
				 (_MainTexColor.g * fragColor.g)*(cos(time + 20.0F) + 1.0F)*0.5F,
				 (_MainTexColor.b * fragColor.b)*(sin(time) + 1.0F)*0.5F, 
				 fragColor.a);
}