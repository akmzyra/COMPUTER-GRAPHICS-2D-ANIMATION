#include <Windows.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define window_width  1000  
#define window_height 600

GLfloat yrot;

void reshape(int width, int height)
{
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1, 1, -1, 1, -1, 1);
    glMatrixMode(GL_MODELVIEW);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glRotatef(yrot, 0, 1, 0);


    //hair_tail
    glBegin(GL_POLYGON);
    glColor3ub(36, 36, 36);
    glVertex3f(-0.3, 0.2, 4.0);
    glVertex3f(0.22, 0.2, -0.5);
    glVertex3f(0.22, 0.6, -0.5);
    glVertex3f(-0.3, 0.6, 4.0);

    glEnd();

    //cape
    glBegin(GL_TRIANGLES);
    glColor3ub(136, 6, 206);
    glVertex3f(0, 0.6, 0);

    glColor3ub(76, 40, 130);
    glVertex3f(-0.4, -0.2, 0);

    glColor3ub(76, 40, 130);
    glVertex3f(0.4, -0.2, 0);

    glEnd();

    //skirt
    glBegin(GL_TRIANGLES);
    glColor3ub(136, 6, 206);
    glVertex3f(0, 0.3, 0);

    glColor3ub(76, 40, 130);
    glVertex3f(-0.3, -0.5, 0);

    glColor3ub(76, 40, 130);
    glVertex3f(0.3, -0.5, 0);

    glEnd();

    glTranslatef(0.0, 0.6, 0.0);

    //upperbody
    glBegin(GL_POLYGON);
    glColor3ub(76, 40, 130);
    glVertex3f(-0.12, -0.5, 0.0);

    glColor3ub(76, 40, 130);
    glVertex3f(0.12, -0.5, 0.0);

    glColor3ub(136, 6, 206);
    glVertex3f(0.12, -0.2, -0.0);

    glColor3ub(136, 6, 206);
    glVertex3f(-0.12, -0.2, -0.0);

    glEnd();
    glTranslatef(0.0, 0.01, 0.0);
    glutSwapBuffers();

    //neck
    glBegin(GL_POLYGON);
    glColor3ub(255, 206, 180);
    glVertex3f(-0.05, -0.22, 0.0); 
    glVertex3f(0.05, -0.22, 0.0);
    glVertex3f(0.05, 0.05, -0.0);
    glVertex3f(-0.05, 0.05, -0.0);

    glEnd();

    //hair_body
    glBegin(GL_POLYGON);
    glColor3ub(36, 36, 36);
    glVertex3f(-0.2, -0.0, 0.0);
    glVertex3f(0.22, -0.0, -0.0);
    glVertex3f(0.22, -0.06, -0.0);
    glVertex3f(-0.2, -0.06, 0.0);

    glEnd();

    //head
    glBegin(GL_POLYGON);
    glColor3ub(255, 206, 180);
    double radius = 0.17;
    double ori_x = 0.0;
    double ori_y = 0.0;
    for (int i = 0; i <= 300; i++) {
        double angle = 2 * 3.142 * i / 300;
        double x = cos(angle) * radius;
        double y = sin(angle) * radius;
        glVertex2d(ori_x + x, ori_y + y);
    }
    glEnd();

    glutSwapBuffers();

    //hat
    glBegin(GL_TRIANGLES);
    glColor3ub(136, 6, 206);
    glVertex3f(0, 0.3, 0);

    glColor3ub(76, 40, 130);
    glVertex3f(-0.3, -0.002, 0);

    glColor3ub(76, 40, 130);
    glVertex3f(0.3, -0.002, 0);

    glEnd();

    glTranslatef(0.0, 0.6, 0.0);


    glFlush();

}

void init()
{
    glClearColor(0, 0, 0, 0);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(50, 50);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Witch");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutIdleFunc(display);
    glutMainLoop();
    return 0;
}