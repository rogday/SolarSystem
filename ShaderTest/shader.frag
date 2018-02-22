uniform sampler2D texture;
uniform vec2 mouse;

#define M_PI 3.1415926535897932384626433832795
#define SIZE 0.7
#define INTENSITY 1.5

void main(){
  vec2 pos = gl_TexCoord[0].xy;
  vec2 dist = pos - mouse;

  if (length(dist) <= SIZE){
    vec2 x = normalize(dist) - dist/SIZE;
    //pos -= x*abs(x)*INTENSITY;
    pos -= sin(x*abs(x)*M_PI/2)*INTENSITY;
  }

  gl_FragColor = texture2D(texture, pos);
}
