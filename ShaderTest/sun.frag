uniform sampler2D texture;
uniform int time;

#define M_PI 3.1415926535897932384626433832795
#define SPEED 15

void main(){
	vec2 pos = gl_TexCoord[0].xy;
	time *= SPEED;

	vec4 color = texture2D(texture, pos);

	color *= vec4(255.0/(time/65536),255.0/((time/256)%256), 255.0/(time%256), 1);

	gl_FragColor = color;
}
