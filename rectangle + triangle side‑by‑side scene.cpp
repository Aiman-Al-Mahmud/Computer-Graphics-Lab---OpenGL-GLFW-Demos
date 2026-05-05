#include <GLFW/glfw3.h>
#include <stdio.h>
#include <stdlib.h>

int windowWidth = 800;
int windowHeight = 600;

GLFWwindow* window;

void rectangle()
{
    glBegin(GL_QUADS);
        glColor3f(1.0, 0.0, 0.0);
        glVertex2f(0.0, 0.0);
        glColor3f(0.0, 1.0, 0.0);
        glVertex2f(2.0, 0.0);
        glColor3f(0.0, 0.0, 1.0);
        glVertex2f(2.0, 1.0);
        glColor3f(1.0, 1.0, 0.0);
        glVertex2f(0.0, 1.0);
    glEnd();
}

void triangle()
{
    glBegin(GL_TRIANGLES);
        glColor3f(1.0, 1.0, 1.0);
        glVertex2f(2.0, 2.0);
        glColor3f(0.0, 1.0, 0.0);
        glVertex2f(2.0, 0.0);
        glColor3f(0.0, 1.0, 0.0);
        glVertex2f(0.0, 0.0);
    glEnd();
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-3, 3, -3, 3, -1, 1);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glViewport(0, 0, windowWidth, windowHeight);

    glPushMatrix();
    glTranslatef(-1.5, 0, 0);
    rectangle();
    glPopMatrix();

    glPushMatrix();
    triangle();
    glPopMatrix();

    glFlush();
}

int main(int argc, char** argv)
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);

    window = glfwCreateWindow(windowWidth, windowHeight, "Classwork-1", NULL, NULL);
    glfwSetWindowPos(window, 100, 100);
    glfwMakeContextCurrent(window);
    
    glShadeModel(GL_SMOOTH);
    glEnable(GL_DEPTH_TEST);
    
    while (!glfwWindowShouldClose(window))
    {
        display();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}