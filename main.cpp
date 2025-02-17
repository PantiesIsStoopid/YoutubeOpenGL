#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

#include"shaderClass.h"
#include"VAO.h"
#include"VBO.h"
#include "EBO.h"


 GLfloat vertices[] = {
    // Main Triangle
    -0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f,    // Left vertex
    0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f,     // Right vertex
    0.0f, 0.5f * float(sqrt(3)) * 2 / 3, 0.0f,  // Top vertex

    // Additional Points (Fixing the syntax)
    -0.5f / 2, 0.5f * float(sqrt(3)) / 6, 0.0f,  // Point 1
    0.5f / 2, 0.5f * float(sqrt(3)) / 6, 0.0f,   // Point 2
    0.0f / 2, -0.5f * float(sqrt(3)) / 3, 0.0f,  // Point 3
};

GLuint indices[] = {0, 3, 5, 3, 2, 4, 5, 4, 1};

int main() {
  // Initialize GLFW
  glfwInit();

  // Set OpenGL version to 3.3 Core Profile
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  // Create a window
  GLFWwindow* window = glfwCreateWindow(800, 800, "YoutubeOpenGL", NULL, NULL);
  if (window == NULL) {
    std::cout << "Failed to make GLFW Window" << std::endl;
    glfwTerminate();
    return -1;
  }
  glfwMakeContextCurrent(window);

  gladLoadGL();

  // Set viewport size
  glViewport(0, 0, 800, 800);

 Shader shaderProgram("default.vert", "default.frag");


 VAO VAO1;
 VAO1.Bind();

 VBO VBO1(vertices, sizeof(vertices));
 EBO EBO1(indices, sizeof(indices));

 VAO1.LinkVBO(VBO1, 0);
 VAO1.Unbind();
 VBO1.Unbind();

 EBO1.Unbind();



  // Render loop
  while (!glfwWindowShouldClose(window)) {
    // Clear the screen with a dark color
    glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    // Use the shader program
    shaderProgram.Activate();

    VAO1.Bind();
    glDrawElements(GL_TRIANGLES, 9, GL_UNSIGNED_INT,0);  // Draw the triangle

    // Swap buffers and poll events
    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  // Cleanup resources
  VAO1.Delete();
  VBO1.Delete();
  EBO1.Delete();
  shaderProgram.Delete();


  // Destroy window and terminate GLFW
  glfwDestroyWindow(window);
  glfwTerminate();
  return 0;
}
