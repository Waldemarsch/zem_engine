//
// Created by vovaz on 02.12.2025.
//

#include <cstdio>

#include <glad/glad.h>
#include <GLFW/glfw3.h>


GLuint VAO, VBO, shader;

GLfloat triangleVertices[] = {
    1.0f, 1.0f, 0.0f,
    1.0f, -1.0f, 0.0f,
    0.0f, 0.0f, 0.0f,
};

void DrawTriangle() {
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(triangleVertices), triangleVertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, nullptr);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

int main() {
    if (!glfwInit()) {
        std::printf("GLFW");
        glfwTerminate();
        return 1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

    // Хуйня, определяющая отношение к deprecated
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    GLFWwindow *mainWindow = glfwCreateWindow(640, 480, "HUI", NULL, NULL);

    if (!mainWindow) {
        printf("Наебнулось создание окна GLFW");
        glfwTerminate();
        return 1;
    }

    int bufferWidth, bufferHeight;
    glfwGetFramebufferSize(mainWindow, &bufferWidth, &bufferHeight);

    glfwMakeContextCurrent(mainWindow);

    if (!gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress))) {
        printf("Наебнулась инициализация GLAD");
        glfwTerminate();
        return 1;
    }

    while (!glfwWindowShouldClose(mainWindow)) {
        glfwPollEvents(); // Обработка инпута

        glClearColor(1.0f, 1.0f, 0.0f, 1.0f); // Очистка цвета
        glClear(GL_COLOR_BUFFER_BIT); // Очистка кадра

        glfwSwapBuffers(mainWindow);

    }

    return 0;
}