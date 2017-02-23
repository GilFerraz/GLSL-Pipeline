#version 130

in vec2 vertexPosition;
in vec4 vertexColor;
in vec2 vertexUV;

// Fragment Shader Attributes
out vec4 fragColor;
out vec2 fragUV;

void main()
{
	//posição no ecrã
	gl_Position = vec4(vertexPosition.x, vertexPosition.y, 0.0f, 1.0f);

	fragColor = vertexColor;
	fragUV = vertexUV;
}