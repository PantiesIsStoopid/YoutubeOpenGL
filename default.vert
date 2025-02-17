#version 330 core
layout (location = 0) in vec3 aPos;    // Position
layout (location = 1) in vec3 aColor;  // Color

out vec3 FragColor;  // Output color to fragment shader

uniform float scale;


void main() {
  gl_Position = vec4(aPos.x +aPos.x*scale,aPos.y +aPos.y * scale ,aPos.z + aPos.z * scale,1.0);
  FragColor = aColor;  // Pass color to fragment shader
}
