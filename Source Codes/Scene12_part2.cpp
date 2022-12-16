#include<windows.h>
#include<GL\glut.h>
#include <GL/glu.h>
#include<math.h>
#include <stdlib.h>
#include<stdio.h>


#define PI 3.141592653

#define SCREEN_WIDTH	1000
#define SCREEN_HEIGHT	600
#define FPS	30

GLfloat yrot;

float rMove = 0.0f;
float rMove2 = 0.0f;

void circle(float x, float y, double r)
{
    float x1, y1;
    glBegin(GL_POLYGON);
    for (int i = 0; i < 200; i++)
    {
        float A = (i * 2 * PI) / 25;
        float x1 = x + ((r - .07) * cos(A));
        float y1 = y + ((r * sin(A)));
        glVertex2f(x1, y1);
    }
    glEnd();
}

void drawcircle(float x, float y, double r)
{
    float x1, y1;
    glBegin(GL_POLYGON);
    for (int i = 0; i < 200; i++)
    {
        float A = (i * 2 * PI) / 25;
        float x1 = x + ((r - .03) * cos(A));
        float y1 = y + ((r * sin(A)));
        glVertex2f(x1, y1);
    }
    glEnd;
}

void drawSquare(int x, int y, int w) {
    glBegin(GL_POLYGON);
    glVertex2i(x, y);
    glVertex2i(x + w, y);
    glVertex2i(x + w, y + w);
    glVertex2i(x, y + w);
    glEnd();
}

void nGon(int n, int x, int y, int r) {
    double inc = 2 * PI / (double)n;
    glBegin(GL_POLYGON);
    for (double theta = 0.0; theta <= 2 * PI; theta += inc) {
        glVertex2i(r * cos(theta) + x, r * sin(theta) + y);
    }
    glEnd();
}

void houseWindow() {


    glColor3f(0.9f, 0.6f, 0.0f); // dusk sky
    glBegin(GL_POLYGON); // x = 100, y = 250, w = 150
    glVertex2i(100, 250); // x = 100, y = 250
    glVertex2i(250, 250); // 100 + 150 = 250, 250
    glVertex2i(250, 400); // 100+ 150 = 250, 250 + 150 = 400
    glVertex2i(100, 400); // 100, 250 + 150 = 400
    glEnd();

    // Hill_Small

    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 1.0, 1.0); // snow
    glVertex2i(180, 350); // up 
    glColor3f(0.0f, 0.2f, 0.0f);
    glVertex2i(100, 256); // left
    glVertex2i(250, 256); // right
    glEnd();

    // line of window 
    glColor3f(0.4f, 0.0f, 0.0f);
    glLineWidth(40);
    glBegin(GL_LINES);
    glVertex2i(100, 250); // below
    glVertex2i(250, 250);
    glVertex2i(250, 400); // above
    glVertex2i(100, 400);
    glVertex2i(103, 400); // left
    glVertex2i(103, 250);
    glVertex2i(250, 400); // right
    glVertex2i(250, 250);
    glEnd();


    // Left_blinds_curtains_1

    glBegin(GL_TRIANGLES);
    glColor3f(0.3, 0.0, 0.0);
    glVertex2i(300, 600); // up
    glColor3f(0.6, 0.0, 0.0);
    glVertex2i(300, 258); // left
    glColor3f(0.5, 0.0, 0.0);
    glVertex2i(600, 600); // right
    glEnd();

    // Right_blinds_curtains_1
    // try again
    glBegin(GL_TRIANGLES);
    glColor3f(0.3, 0.0, 0.0);
    glVertex2i(800, 280); // up
    glColor3f(0.6, 0.0, 0.0);
    glVertex2i(800, 500); // left
    glColor3f(0.5, 0.0, 0.0);
    glVertex2i(600, 500); // right
    glEnd();

    // floor
    glColor3f(0.5, 0.2, 0.3);
    glLineWidth(3);
    glBegin(GL_POLYGON);
    glVertex2i(0, 150);
    glVertex2i(1000, 150);
    glVertex2i(1000, 0);
    glVertex2i(0, 0);
    glEnd();

    // Left_blinds_curtains_2

    glBegin(GL_TRIANGLES);
    glColor3f(0.6, 0.0, 0.0);
    glVertex2i(300, 350); // up 
    glColor3f(0.3, 0.0, 0.0);
    glVertex2i(300, 138); // left
    glColor3f(0.3, 0.0, 0.0);
    glVertex2i(450, 138); // right
    glEnd();

    // fireplace

    glColor3f(0.5f, 0.2f, 0.0f);
    glLineWidth(50);
    glBegin(GL_LINES);
    glVertex2i(430, 280);
    glVertex2i(650, 280);
    glVertex2i(446, 270);
    glVertex2i(446, 120);
    glVertex2i(634, 270);
    glVertex2i(634, 120);
    glEnd();


    // Right_blinds_curtains_2

    glBegin(GL_TRIANGLES);
    glColor3f(0.6, 0.0, 0.0);
    glVertex2i(800, 350); // up 
    glColor3f(0.3, 0.0, 0.0);
    glVertex2i(638, 138); // left
    glColor3f(0.3, 0.0, 0.0);
    glVertex2i(800, 138); // right
    glEnd();

    // fireplace

    glColor3f(0.5f, 0.2f, 0.0f);
    glLineWidth(50);
    glBegin(GL_LINES);
    glVertex2i(635, 270);
    glVertex2i(635, 120);
    glEnd();

    // fire

    /*glBegin(GL_TRIANGLES);
    glColor3f(0.7, 0.7, 0.8);
    glVertex2i(380, 150); // up
    glColor3f(0.4, 0.5, 0.1);
    glVertex2i(300, 100); // left
    glVertex2i(450, 100); // right
    glEnd();*/

    // fire left
    glBegin(GL_TRIANGLES);
    glColor3f(0.6, 0.0, 0.0);
    glVertex2i(525, 200); // up 
    glColor3f(0.7, 0.3, 0.0);
    glVertex2i(500, 130); // left
    glColor3f(0.6, 0.0, 0.0);
    glVertex2i(550, 130); // right
    glEnd();

    // fire right
    glBegin(GL_TRIANGLES);
    glColor3f(0.6, 0.0, 0.0);
    glVertex2i(560, 200); // up 
    glColor3f(0.7, 0.3, 0.0);
    glVertex2i(520, 130); // left
    glColor3f(0.6, 0.0, 0.0);
    glVertex2i(600, 130); // right
    glEnd();

    // bowl(?)
    glColor3f(0.2f, 0.3f, 0.3f);
    nGon(40, 545, 200, 40);

    // bowl lid(?)
    glColor3f(0.4f, 0.1f, 0.0f); // deep brown
    glLineWidth(500);
    glBegin(GL_LINES);
    glVertex2i(545, 245);
    glVertex2i(545, 220);
    glEnd();

    // staircase railing

    glColor3f(0.5f, 0.2f, 0.0f);
    glLineWidth(40);
    glBegin(GL_LINES);
    glVertex2i(780, 350);
    glVertex2i(1000, 350);
    glEnd();

    glColor3f(0.5f, 0.2f, 0.0f);
    glLineWidth(100);
    glBegin(GL_LINES);
    glVertex2i(780, 365);
    glVertex2i(780, 150);
    glEnd();

    // staircas_railing_top

    // stairs

    glColor3f(0.5f, 0.2f, 0.0f);
    glLineWidth(50);
    glBegin(GL_LINES);
    glVertex2i(890, 325);
    glColor3f(0.6f, 0.23f, 0.03f);
    glVertex2i(1000, 325);
    glEnd();

    glColor3f(0.6f, 0.3f, 0.0f);
    glLineWidth(50);
    glBegin(GL_LINES);
    glVertex2i(870, 300);
    glColor3f(0.5f, 0.2f, 0.0f);
    glVertex2i(1000, 300);
    glEnd();

    glColor3f(0.6f, 0.3f, 0.0f);
    glLineWidth(50);
    glBegin(GL_LINES);
    glVertex2i(850, 275);
    glColor3f(0.6f, 0.23f, 0.1f);
    glVertex2i(1000, 275);
    glEnd();

    glColor3f(0.6f, 0.3f, 0.0f);
    glLineWidth(50);
    glBegin(GL_LINES);
    glVertex2i(830, 250);
    glColor3f(0.6f, 0.3f, 0.1f);
    glVertex2i(1000, 250);
    glEnd();

    glColor3f(0.6f, 0.3f, 0.0f);
    glLineWidth(50);
    glBegin(GL_LINES);
    glVertex2i(810, 225);
    glColor3f(0.6f, 0.23f, 0.1f);
    glVertex2i(1000, 225);
    glEnd();

    glColor3f(0.6f, 0.3f, 0.0f);
    glLineWidth(50);
    glBegin(GL_LINES);
    glVertex2i(790, 200);
    glColor3f(0.6f, 0.2f, 0.1f);
    glVertex2i(1000, 200);
    glEnd();

    glColor3f(0.6f, 0.3f, 0.0f);
    glLineWidth(50);
    glBegin(GL_LINES);
    glVertex2i(780, 175);
    glColor3f(0.6f, 0.2f, 0.1f);
    glVertex2i(1000, 175);
    glEnd();

    glColor3f(0.6f, 0.3f, 0.0f);
    glLineWidth(50);
    glBegin(GL_LINES);
    glVertex2i(760, 150);
    glColor3f(0.6f, 0.2f, 0.1f);
    glVertex2i(1000, 150);
    glEnd();

    glColor3f(0.6f, 0.3f, 0.0f);
    glLineWidth(50);
    glBegin(GL_LINES);
    glVertex2i(740, 125);
    glColor3f(0.6f, 0.23f, 0.1f);
    glVertex2i(1000, 125);
    glEnd();


    // Process all OpenGL routine s as quickly as possible
    glFlush();


}

void rapunzel()
{
    // glLoadIdentity();
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


void witch()
{
    glLoadIdentity();
    glRotatef(yrot, 0, 1, 0);
    glScalef(0.5f, 0.5f, 1.0f);
    glTranslatef(-0.6f, -0.5f, -0.5f);

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

void prince() {

    // glRotatef(-70.0, 0.0f, 1.0f, 550.0f);
    // glTranslatef(2.3f, 0.3f, 0.5f);

     //right leg 
    glBegin(GL_POLYGON);
    glColor3d(0.1f, 0.1f, 0.1f); glVertex3f(-0.1, 0.1, 3.0);
    glColor3d(1.0f, 1.0f, 1.0f); glVertex3f(0.1, 0.1, -0.2);
    glColor3d(1.0f, 1.0f, 1.0f); glVertex3f(0.1, -0.7, -0.2);
    glColor3d(0.1f, 0.1f, 0.1f); glVertex3f(-0.1, -0.7, 3.0);
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
    glColor3f(1.0f, 1.0f, 1.0f); glVertex3f(0.3, -0.3, 0);
    glColor3f(0.1f, 0.1f, 0.1f); glVertex3f(0, 0.3, 0);
    glEnd();
    glTranslatef(0.0, 0.6, 0.0);
    glColor3f(1, 0.6, 0.6);

    //upperbody
    glBegin(GL_POLYGON);
    glColor3d(0.1f, 0.1f, 0.1f); glVertex3f(-0.19, -0.3, 0.1);
    glColor3d(1.0f, 1.0f, 1.0f); glVertex3f(0.19, -0.3, 0.1);
    glColor3d(1.0f, 1.0f, 1.0f); glVertex3f(0.19, -0.68, -0.1);
    glColor3d(1.0f, 1.0f, 1.0f); glVertex3f(-0.19, -0.68, -0.1);
    glEnd();


    //neck
    glBegin(GL_POLYGON);
    glColor3d(0.9, 0.8, 0.7); glVertex3f(-0.05, -0.3, 0.0);
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
}

void blueCloud() {
    glLoadIdentity();
    glColor3ub(0, 0, 128);
    glTranslatef(-0.0f, -0.6f, 0.0f);

    drawcircle(0.35, 0.71, 0.15);
    circle(0.45, 0.70, 0.15);
    drawcircle(0.55, 0.75, 0.15);
    circle(0.45, 0.77, 0.15);
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    houseWindow();

    glPushMatrix();
    glLoadIdentity();
    glScalef(0.5f, 0.5f, 1.0f);
    glTranslatef(1.0f, -0.8f, 0.0f);
    glTranslatef(rMove, rMove2, 0);

    rMove += 0.02;
    rMove -= 0.00;
    {
        if (rMove > 0.1)
        {
            rMove = 0.1;

        }
        if (rMove > 0.1)
        {
            rMove = -0.1;
        }
    }
    rapunzel();
    glPopMatrix();

    glPushMatrix();
    glLoadIdentity();
    glRotatef(yrot, 0, 1, 0);
    glScalef(0.5f, 0.5f, 1.0f);
    glTranslatef(-0.6f, -0.5f, -0.5f);
    witch();
    glPopMatrix();

    glPushMatrix();
    glLoadIdentity();
    glScalef(0.5f, 0.5f, 1.0f);
    glRotatef(-70.0, 0.0f, 1.0f, 550.0f);
    glTranslatef(1.1f, -1.0f, 0.5f);
    prince();
    glPopMatrix();

    glPushMatrix();
    glLoadIdentity();
    glTranslatef(1.3f, -0.6f, 0.0f);
    blueCloud();
    glPopMatrix();


    glFlush();
    glutSwapBuffers();
}

void idle()
{
    DWORD start = GetTickCount64();
    while (GetTickCount64() - start < 1000 / FPS);

    glutPostRedisplay();
}

void init(void)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glClearColor(1.0, 0.8, 0.2, 0.0);//yellowish

    gluOrtho2D(0.0, 1000.0, 0.0, 500.0);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE);
    glutInitWindowPosition(50, 50); // void glutInitWindowPosition(int x, int y);
    glutInitWindowSize(1000, 600);
    glutCreateWindow("scene12_ii");
    init();
    glutDisplayFunc(display);

    glutIdleFunc(idle);
    glutMainLoop();
}