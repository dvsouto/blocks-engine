#version 330 core
layout (location = 0) in vec3 aPos; // Posição dos vértices
layout (location = 1) in vec3 aColor; // Cor dos vértices

out vec3 vertexColor; // Envia a cor para o fragment shader

uniform mat4 transform; // Matriz de transformação

void main() {
    gl_Position = transform * vec4(aPos, 1.0);
    vertexColor = aColor;
}
