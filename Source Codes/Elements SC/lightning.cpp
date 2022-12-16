#ifdef _APPLE_CC_
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#define SCREEN_WIDTH 1000
#define SCREEN_HEIGHT 600

void display() {


    glClear(GL_COLOR_BUFFER_BIT);

    glColor3ub(0, 0, 128);
    glBegin(GL_POLYGON);
    glVertex3f(-0.04, -0.15, 0.2);
    glVertex3f(0.02, -0.2, 0);
    glVertex3f(0.2, 0.35, 0);
    glEnd();

    glFlush();
}

int main(int argc, char** argv) {

    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);

    glutCreateWindow("Lightning");

    glutDisplayFunc(display);
    glutMainLoop();
}