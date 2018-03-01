uniform sampler2D texture;

#define M_PI 3.1415926535897932384626433832795
#define SPEED 15

void main(){
	vec2 pos = gl_TexCoord[0].xy;

	vec4 color = texture2D(texture, pos);

	gl_FragColor = color;
}
