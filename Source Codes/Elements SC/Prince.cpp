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


    //right leg 
    glBegin(GL_POLYGON);
    glColor3d(0.1f,0.1f,0.1f); glVertex3f(-0.1, 0.1, 3.0);
    glColor3d(1.0f, 1.0f, 1.0f); glVertex3f(0.1, 0.1, -0.2);
    glColor3d(1.0f, 1.0f, 1.0f); glVertex3f(0.1, -0.7, -0.2);
    glColor3d(0.1f,0.1f,0.1f); glVertex3f(-0.1, -0.7, 3.0);
    glEnd();



    //left leg 
    glBegin(GL_POLYGON);
    glColor3d(0.1f, 0.1f, 0.1f); glVertex3f(-0.1, 0.1, -0.2);
    glColor3d(1.0f, 1.0f, 1.0f); glVertex3f(0.1, 0.1, 3.0);
    glColor3d(1.0f, 1.0f, 1.0f); glVertex3f(0.1, -0.7, 3.0);
    glColor3d(1.0f, 1.0f, 1.0f); glVertex3f(-0.1, -0.7, -0.2);
    glEnd();
    
   
  
    //skirt
    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 1.0f, 1.0f); glVertex3f(-0.3, -0.3, 0);
    glColor3f(1.0f,1.0f,1.0f); glVertex3f(0.3, -0.3, 0);
    glColor3f(0.1f,0.1f,0.1f); glVertex3f(0, 0.3, 0);
    glEnd();
    glTranslatef(0.0, 0.6, 0.0);
    glColor3f(1, 0.6, 0.6);



  //upperbody
    glBegin(GL_POLYGON);
    glColor3d(0.1f,0.1f,0.1f); glVertex3f(-0.19, -0.3, 0.1);
    glColor3d(1.0f, 1.0f, 1.0f); glVertex3f(0.19, -0.3, 0.1);
    glColor3d(1.0f,1.0f,1.0f); glVertex3f(0.19, -0.68, -0.1);
    glColor3d(1.0f,1.0f,1.0f); glVertex3f(-0.19, -0.68, -0.1);
    glEnd();
    glutSwapBuffers();

    //neck
    glBegin(GL_POLYGON);
    glColor3d(0.9,0.8,0.7); glVertex3f(-0.05, -0.3, 0.0);
    glColor3d(1, 0.9, 0.7); glVertex3f(0.05, -0.3, 0.0);
    glColor3d(1, 0.9, 0.7); glVertex3f(0.05, -0.15, -0.0);
    glColor3d(1, 0.9, 0.7); glVertex3f(-0.05, -0.15, -0.0);
    glEnd();

    glColor3f(1, 0.9, 0.8);
    //head
    glBegin(GL_POLYGON);
    glVertex3f(0.2, 0.1, 0.0);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(-0.1, 0.0, 0.0);
    glVertex3f(-0.2, 0.1, 0.0);
    glVertex3f(-0.2, -0.1, 0.0);
    glVertex3f(-0.1, -0.2, 0.0);
    glVertex3f(0.1, -0.2, 0.0);
    glVertex3f(0.2, -0.1, 0.0);

    glEnd();



    //hair
    glBegin(GL_POLYGON);
    glColor3d(0.1f, 0.1f, 0.1f); glVertex3f(-0.25, 0.1, 6.0);
    glColor3d(0.1f, 0.1f, 0.1f); glVertex3f(0.25, 0.1, -0.2);
    glColor3d(0.1f, 0.1f, 0.1f); glVertex3f(0.25, -0.15, -0.2);
    glColor3d(0.1f, 0.1f, 0.1f); glVertex3f(-0.25, -0.15, 6.0);
    glEnd();

    //hair part 2
    glBegin(GL_POLYGON);
    glColor3d(0.1f, 0.1f, 0.1f); glVertex3f(-0.2, 0.1, 0.0);
    glColor3d(0.1f, 0.1f, 0.1f); glVertex3f(0.2, 0.1, 0.0);
    glColor3d(0.1f, 0.1f, 0.1f); glVertex3f(0.2, -0.0, 0.0);
    glColor3d(0.1f, 0.1f, 0.1f); glVertex3f(-0.2, -0.0, 0.0);
    glEnd();



    glFlush();


 
}

void init()
{
    glClearColor(1.0f, 1.0f, 0.1f,0.1f);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(50, 50);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Prince  ");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutIdleFunc(display);
    glutMainLoop();
    return 0;
}