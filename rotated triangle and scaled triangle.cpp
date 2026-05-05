#include <GLFW/glfw3.h>
#include <stdio.h>
#include <stdlib.h>

int windowWidth = 800;   //pop-up window size 
int windowHeight = 600;

GLFWwindow* window;

float Txval = 0.0;      //transform matrix value 
float Tyval = 0.0;
float sval = 1.0;
bool flagScale = false;  // scsle value 

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

void myKeyboardFunc(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (action == GLFW_PRESS || action == GLFW_REPEAT)
    {
        switch (key)
        {
            case GLFW_KEY_R:
                Txval += 0.2;
                break;
            case GLFW_KEY_L:
                Txval -= 0.2;
                break;
            case GLFW_KEY_U:
                Tyval += 0.2;
                break;
            case GLFW_KEY_D:
                Tyval -= 0.2;
                break;
            case GLFW_KEY_S:
                if (mods & GLFW_MOD_SHIFT)
                    flagScale = true;
                else
                    flagScale = false;
                break;
            case GLFW_KEY_ESCAPE:
                glfwSetWindowShouldClose(window, GLFW_TRUE);
                break;
        }
    }
}

void animate()
{
    if (flagScale == true)
    {
        sval += 0.005;
        if (sval > 3)
            sval = 0.005;
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
    glViewport(400, 300, 400, 300);
    glTranslatef(Txval, Tyval, 0);
    glRotatef(45, 0, 0, 1);
    triangle();
    glPopMatrix();

    glPushMatrix();
    glViewport(0, 0, 400, 300);
    glScalef(sval, sval, 1);
    triangle();
    glPopMatrix();

    glFlush();
}

int main(int argc, char** argv)
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);

    window = glfwCreateWindow(windowWidth, windowHeight, "Triangle-Demo", NULL, NULL);
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
