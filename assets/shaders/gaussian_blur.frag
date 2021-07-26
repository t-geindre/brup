/*
uniform sampler2D 	source;
uniform vec2 		offsetFactor;

void main()
{
	vec2 textureCoordinates = gl_TexCoord[0].xy;
	vec4 color = vec4(0.0);
	color += texture2D(source, textureCoordinates - 4.0 * offsetFactor) * 0.0162162162;
	color += texture2D(source, textureCoordinates - 3.0 * offsetFactor) * 0.0540540541;
	color += texture2D(source, textureCoordinates - 2.0 * offsetFactor) * 0.1216216216;
	color += texture2D(source, textureCoordinates - offsetFactor) * 0.1945945946;
	color += texture2D(source, textureCoordinates) * 0.2270270270;
	color += texture2D(source, textureCoordinates + offsetFactor) * 0.1945945946;
	color += texture2D(source, textureCoordinates + 2.0 * offsetFactor) * 0.1216216216;
	color += texture2D(source, textureCoordinates + 3.0 * offsetFactor) * 0.0540540541;
	color += texture2D(source, textureCoordinates + 4.0 * offsetFactor) * 0.0162162162;
	gl_FragColor = color;
}
*/

uniform sampler2D texture;
uniform float blur_radius;

void main()
{
    vec2 offx = vec2(blur_radius, 0.0);
    vec2 offy = vec2(0.0, blur_radius);

    vec4 pixel = texture2D(texture, gl_TexCoord[0].xy)               * 4.0 +
                 texture2D(texture, gl_TexCoord[0].xy - offx)        * 2.0 +
                 texture2D(texture, gl_TexCoord[0].xy + offx)        * 2.0 +
                 texture2D(texture, gl_TexCoord[0].xy - offy)        * 2.0 +
                 texture2D(texture, gl_TexCoord[0].xy + offy)        * 2.0 +
                 texture2D(texture, gl_TexCoord[0].xy - offx - offy) * 1.0 +
                 texture2D(texture, gl_TexCoord[0].xy - offx + offy) * 1.0 +
                 texture2D(texture, gl_TexCoord[0].xy + offx - offy) * 1.0 +
                 texture2D(texture, gl_TexCoord[0].xy + offx + offy) * 1.0;

    gl_FragColor =  gl_Color * (pixel / 16.0);
}