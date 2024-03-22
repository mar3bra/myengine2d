#version 450 core
out vec4 FragColor;
  
in vec2 TexCoord;
in vec3 ourColor;

uniform sampler2D myTexture;
uniform vec3 color;

void main()
{
	// linearly interpolate between both textures (80% container, 20% awesomeface)
	/*
    vec4 texColor = texture(myTexture, TexCoord);
    if(texColor.a < 0.1)
        discard;
    */
    FragColor = vec4(ourColor, 1.0);//texColor;texColor;//mix(texture(texture1, TexCoord), texture(texture2, TexCoord), 0.2);
}

