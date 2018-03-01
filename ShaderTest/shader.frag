uniform sampler2D texture;
uniform vec2 mouse;
uniform float time;

#define M_PI 3.1415926535897932384626433832795
#define SIZE 0.9
#define INTENSITY 1.0

void main(){
  vec2 pos = gl_TexCoord[0].xy;
  vec2 dist = pos - mouse;

  if (length(dist) <= SIZE){
    vec2 x = normalize(dist) - dist/SIZE;
    // pos -= sin(x*abs(x)*M_PI/2)*INTENSITY;
    float f = (1 + sin(length(x) + time))/2*M_PI - M_PI/2;
    pos -= x*INTENSITY*mat2(cos(f), -sin(f), sin(f), cos(f));
  }

  gl_FragColor = texture2D(texture, pos);
}
