#version 400

layout (location = 0) in vec3 vPos;

uniform vec3 uCameraPos;
uniform float uSize;
uniform vec3 uOffset;
uniform vec4 uColor;
uniform mat4 uVP;

out vec4 color;
out vec2 uv;

void main()
{
   color = uColor;
   uv = vPos.xy;

   mat4 scale = mat4(uSize, 0.0, 0.0, 0.0,
                     0.0, uSize, 0.0, 0.0,
                     0.0, 0.0, uSize, 0.0,
                     0.0, 0.0, 0.0, 1.0);

   vec3 t = uOffset - (uSize/2.0);
   mat4 translate = mat4(1.0, 0.0, 0.0, 0.0,
                        0.0, 1.0, 0.0, 0.0,
                        0.0, 0.0, 1.0, 0.0,
                        t, 1.0);

   vec3 n = vec3(0.0, 0.0, 1.0);
   float cosine = dot(uCameraPos, n)/(length(uCameraPos));
   float sine = -cross(uCameraPos, n).y/(length(uCameraPos));
   mat4 rotate = mat4(cosine, 0.0, -sine, 0.0,
                     0.0, 1.0, 0.0, 0.0,
                     sine, 0.0, cosine, 0.0,
                     0.0, 0.0, 0.0, 1.0);

   vec4 uPos = vec4(vPos, 1.0);
   gl_Position = uVP * rotate * translate * scale * uPos; 
}
