#include<windows.h>
#include<GL\glut.h>
#include <GL/glu.h>
#include<math.h>
#include <stdlib.h>
#include<stdio.h>


#define PI 3.141592653

void init(void)
{
    glClearColor(1.0, 0.8, 0.2, 0.0);//yellowish
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 1000.0, 0.0, 500.0);
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
    glVertex2i(634, 270);
    glVertex2i(634, 120);
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
    nGon(40, 540, 200, 40);

    // bowl lid(?)
    glColor3f(0.4f, 0.1f, 0.0f); // deep brown
    glLineWidth(500);
    glBegin(GL_LINES);
    glVertex2i(540, 245);
    glVertex2i(540, 220);
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
    glVertex2i(780, 310);
    glVertex2i(810, 310);
    glEnd();

    glColor3f(0.5f, 0.2f, 0.0f);
    glLineWidth(100);
    glBegin(GL_LINES);
    glVertex2i(780, 260);
    glVertex2i(810, 260);
    glEnd();

    glColor3f(0.5f, 0.2f, 0.0f);
    glLineWidth(100);
    glBegin(GL_LINES);
    glVertex2i(780, 230);
    glVertex2i(810, 230);
    glEnd();

    glColor3f(0.5f, 0.2f, 0.0f);
    glLineWidth(100);
    glBegin(GL_LINES);
    glVertex2i(780, 200);
    glVertex2i(810, 200);
    glEnd();

    glColor3f(0.5f, 0.2f, 0.0f);
    glLineWidth(100);
    glBegin(GL_LINES);
    glVertex2i(780, 150);
    glVertex2i(810, 150);
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
    glVertex2i(850, 270);
    glColor3f(0.6f, 0.23f, 0.1f);
    glVertex2i(1000, 270);
    glEnd();

    glColor3f(0.6f, 0.3f, 0.0f);
    glLineWidth(50);
    glBegin(GL_LINES);
    glVertex2i(830, 240);
    glColor3f(0.6f, 0.3f, 0.1f);
    glVertex2i(1000, 240);
    glEnd();

    glColor3f(0.6f, 0.3f, 0.0f);
    glLineWidth(50);
    glBegin(GL_LINES);
    glVertex2i(820, 210);
    glColor3f(0.6f, 0.23f, 0.1f);
    glVertex2i(1000, 210);
    glEnd();

    glColor3f(0.6f, 0.3f, 0.0f);
    glLineWidth(50);
    glBegin(GL_LINES);
    glVertex2i(800, 190);
    glColor3f(0.6f, 0.2f, 0.1f);
    glVertex2i(1000, 190);
    glEnd();

    glColor3f(0.6f, 0.3f, 0.0f);
    glLineWidth(50);
    glBegin(GL_LINES);
    glVertex2i(760, 165);
    glColor3f(0.6f, 0.2f, 0.1f);
    glVertex2i(1000, 165);
    glEnd();

    glColor3f(0.6f, 0.3f, 0.0f);
    glLineWidth(50);
    glBegin(GL_LINES);
    glVertex2i(730, 135);
    glColor3f(0.6f, 0.2f, 0.1f);
    glVertex2i(1000, 135);
    glEnd();

    glColor3f(0.6f, 0.3f, 0.0f);
    glLineWidth(50);
    glBegin(GL_LINES);
    glVertex2i(700, 115);
    glColor3f(0.6f, 0.23f, 0.1f);
    glVertex2i(1000, 115);
    glEnd();


    // Process all OpenGL routine s as quickly as possible
    glFlush();


}


void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    houseWindow();

    glutSwapBuffers();
    glFlush();

}


int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(50, 50); // void glutInitWindowPosition(int x, int y);
    glutInitWindowSize(1000, 600);
    glutCreateWindow("Inside Tower (almost-dusk)");
    init();
    glutDisplayFunc(display);

    glutMainLoop();
}



