#include<GL/glut.h>

void myInit(void)
{
    glClearColor(0.0, 0.0, 0.0, 1.0);

    glPointSize(1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluOrtho2D(-780, 780, -420, 420);
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POINTS);
    glColor3f(1.0, 1.0, 1.0);
    for (int i = -15 * 15 * 15; i < 15 * 15 * 15; i++)
    {
        glVertex2i(0, i);
    }
    for (int i = -15 * 15 * 15; i < 15 * 15 * 15; i++)
    {
        glVertex2i(i, 0);
    }
    GLfloat x = -100;
    GLfloat y;
    float max = 15 * 15;
    while (x < 100)
    {
        y = x*x; //Square function
        glColor3f(1.0, y / max, 0.0);
        glVertex2i(x, y);
        x += 0.01;
    }
    glEnd();
    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowSize(1000, 700);
    glutInitWindowPosition(0, 0);

    glutCreateWindow("Square function graphing");
    myInit();

    glutDisplayFunc(display);
    glutMainLoop();
}
