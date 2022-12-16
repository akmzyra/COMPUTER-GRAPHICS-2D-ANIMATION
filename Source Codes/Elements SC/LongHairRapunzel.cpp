
#include<GL/glut.h>

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


    //skirt
    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 0.0, 1.0); glVertex3f(-0.3, -0.3, 0);
    glColor3f(1.0, 0.0, 1.0); glVertex3f(0.3, -0.3, 0);
    glColor3f(1.0, 0.0, 1.0); glVertex3f(0, 0.3, 0);
    glEnd();
    glTranslatef(0.0, 0.6, 0.0);
    glColor3f(1, 0.6, 0.6);

    //upperbody
    glBegin(GL_POLYGON);
    glColor3f(1.0, 0.0, 1.0); glVertex3f(-0.1, -0.5, 0.0);
    glColor3f(1.0, 0.0, 1.0); glVertex3f(0.1, -0.5, 0.0);
    glColor3f(1.0, 0.0, 1.0); glVertex3f(0.1, -0.3, -0.0);
    glColor3f(1.0, 0.0, 1.0); glVertex3f(-0.1, -0.3, -0.0);
    glEnd();
    glutSwapBuffers();
    //neck
    glBegin(GL_POLYGON);
    glColor3f(0.9, 0.7, 0.6); glVertex3f(-0.05, -0.3, 0.0);
    glColor3f(0.9, 0.7, 0.6); glVertex3f(0.05, -0.3, 0.0);
    glColor3f(0.9, 0.7, 0.6); glVertex3f(0.05, -0.15, -0.0);
    glColor3f(0.9, 0.7, 0.6); glVertex3f(-0.05, -0.15, -0.0);
    glEnd();

    glColor3f(1.0f, 0.5f, 0.0f);
    //head
    glBegin(GL_POLYGON);
    glColor3f(0.9, 0.7, 0.6); glVertex3f(0.2, 0.1, 0.0);
    glColor3f(0.9, 0.7, 0.6); glVertex3f(0.0, 0.0, 0.0);
    glColor3f(0.9, 0.7, 0.6); glVertex3f(-0.1, 0.0, 0.0);
    glColor3f(0.9, 0.7, 0.6); glVertex3f(-0.2, 0.1, 0.0);
    glColor3f(0.9, 0.7, 0.6); glVertex3f(-0.2, -0.1, 0.0);
    glColor3f(0.9, 0.7, 0.6); glVertex3f(-0.1, -0.2, 0.0);
    glColor3f(0.9, 0.7, 0.6); glVertex3f(0.1, -0.2, 0.0);
    glColor3f(0.9, 0.7, 0.6); glVertex3f(0.2, -0.1, 0.0);

    glEnd();



    //hair
    glBegin(GL_POLYGON);
    glColor3d(1.0, 1.0, 0.0); glVertex3f(-0.25, 0.1, 8.0);
    glColor3d(1.0, 1.0, 0.0); glVertex3f(0.25, 0.1, -0.2);
    glColor3d(1.0, 1.0, 0.0); glVertex3f(0.25, -2.0, -0.2);
    glColor3d(1.0, 1.0, 0.0); glVertex3f(-0.25, -2.0, 8.0);
    glEnd();

    //hair part 2
    glBegin(GL_POLYGON);
    glColor3d(1.0, 1.0, 0.0); glVertex3f(-0.2, 0.1, 0.0);
    glColor3d(1.0, 1.0, 0.0); glVertex3f(0.2, 0.1, 0.0);
    glColor3d(1.0, 1.0, 0.0); glVertex3f(0.2, -0.0, 0.0);
    glColor3d(1.0, 1.0, 0.0); glVertex3f(-0.2, -0.0, 0.0);
    glEnd();



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
    glutInitWindowSize(1000, 600);
    glutCreateWindow("Rapunzel");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutIdleFunc(display);
    glutMainLoop();
    return 0;
}