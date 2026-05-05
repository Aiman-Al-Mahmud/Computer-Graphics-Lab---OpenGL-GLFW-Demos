#include <GLFW/glfw3.h>
#include <stdio.h>
#include <stdlib.h>

int windowWidth = 1000;
int windowHeight = 800;

GLFWwindow* window;

float rotationAngle = 0.0;
bool flagRotate = true;

void triangle()
{
    glBegin(GL_TRIANGLES);
        glColor3f(1.0, 1.0, 1.0);
        glVertex2f(2.0, 2.0);
        glColor3f(0.0, 1.0, 0.0);
        glVertex2f(3.0, 0.0);
        glColor3f(0.0, 1.0, 0.0);
        glVertex2f(0.0, 0.0);
    glEnd();
}

void myKeyboardFunc(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (action == GLFW_PRESS)
    {
        switch (key)
        {
            case GLFW_KEY_SPACE:
                flagRotate = !flagRotate;
                break;
            case GLFW_KEY_ESCAPE:
                glfwSetWindowShouldClose(window, GLFW_TRUE);
                break;
        }
    }
}

void animate()
{
    if (flagRotate == true)
    {
        rotationAngle += 1.0;
        if (rotationAngle >= 360.0)
            rotationAngle = 0.0;
    }
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-3, 3, -3, 3, -1, 1);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glPushMatrix();
    glViewport(400,300,400,300);
    glRotatef(rotationAngle, 0, 0, 1);
    triangle();
    glPopMatrix();

    glFlush();
}

int main(int argc, char** argv)
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);

    window = glfwCreateWindow(windowWidth, windowHeight, "Lab-Work-2", NULL, NULL);
    glfwSetWindowPos(window, 100, 100);
    glfwMakeContextCurrent(window);
    
    glShadeModel(GL_SMOOTH);
    glEnable(GL_DEPTH_TEST);
    
    glfwSetKeyCallback(window, myKeyboardFunc);
    
    while (!glfwWindowShouldClose(window))
    {
        animate();
        display();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}