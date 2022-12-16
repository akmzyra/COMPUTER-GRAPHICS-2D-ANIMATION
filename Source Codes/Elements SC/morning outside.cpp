#include <windows.h>
#include <stdlib.h>
#include <gl\GL.h>
#include <gl\GLU.h>
#include <gl\glut.h>
#include <math.h>

#define PI 3.141592653

#define SCREEN_WIDTH	1200
#define SCREEN_HEIGHT	700

void reshape(GLsizei w, GLsizei h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 1000, 0, 500);
	//glMatrixMode(GL_MODELVIEW);
	//glLoadIdentity();
}

void circle(float x, float y, double r)
{
	float x1, y1;
	glBegin(GL_POLYGON);
	for (int i = 0; i < 200; i++)
	{
		float A = (i * 2 * PI) / 25;
		float x1 = x + ((r = .07) * cos(A));
		float y1 = y + ((r * sin(A)));
		glVertex2f(x1, y1);
	}
	glEnd();
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


void sky()
{
	glColor3f(0.529, 0.808, 0.922);
	glBegin(GL_QUADS);
	glVertex2f(-1.0, 0.0);
	glVertex2f(-1.0, 1.0);
	glColor3f(0.941, 0.973, 1.00);
	glVertex2f(1.0, 1.0);
	glVertex2f(1.0, 0.0);
	glEnd();

	glFlush();
}

void ground()
{
	//have some weird belahan pls fix them later
	glColor3f(0.396, 0.263, 0.129);
	glBegin(GL_QUADS);
	glVertex2f(-1.0,0.0);
	glVertex2f(-1.0,-1.0);
	glVertex2f(1.0,0.0);
	glVertex2f(1.0,-1.0);
	glEnd();

	glFlush();

}

void mountain()
{
	//first
	glColor3f(0.4784, 0.451, 0.4471);
	glBegin(GL_POLYGON);
	glVertex2f(-1.0,-0.3);
	glVertex2f(-0.5,0.70);
	glVertex2f(0.0,-0.3);
	glEnd();

	//first hat??
	glColor3f(0.4784, 0.451, 0.4471);
	glBegin(GL_POLYGON);
	glVertex2f(-0.30, 0.30);
	glVertex2f(-0.70, 0.30);
	glColor3f(0.906, 0.906, 0.906);
	glVertex2f(-0.50, 0.70);
	glEnd();
	

	//second
	glColor3f(0.4784, 0.451, 0.4471);
	glBegin(GL_POLYGON);
	glVertex2f(0.0, -0.3);
	glVertex2f(0.5, 0.70);
	glVertex2f(1.0, -0.3);
	glEnd();

	//second hat??
	glColor3f(0.4784, 0.451, 0.4471);
	glBegin(GL_POLYGON);
	glVertex2f(0.30, 0.30);
	glVertex2f(0.70, 0.30);
	glColor3f(0.906, 0.906, 0.906);
	glVertex2f(0.50, 0.70);
	glEnd();

	glFlush();
}

void sun()
{
	glColor3f(1.000, 0.843, 0.000);
	circle(0.15, 0.78, 0.25);
	glFlush();
}

void tree1()
{
	//wood
	glColor3f(0.588, 0.294, 0.0);
	glBegin(GL_QUADS);
	glVertex2f(0.85,0.30);
	glVertex2f(0.83,0.30);
	glVertex2f(0.83,-0.40);
	glVertex2f(0.80, -0.40);
	glEnd();

	//leaves
	glColor3f(0.216, 0.376, 0.024);
	glLineWidth(3);
	glBegin(GL_POLYGON);
	glVertex2f(0.65, 0.25);
	glVertex2f(0.65, 0.48);
	glColor3f(0.565, 0.933, 0.565);
	glVertex2f(0.92, 0.48);
	glVertex2f(0.92, 0.25);
	glEnd();

	glColor3f(0.216, 0.376, 0.024);
	glLineWidth(3);
	glBegin(GL_POLYGON);
	glVertex2f(0.60, 0.35);
	glVertex2f(0.60, 0.59);
	glColor3f(0.565, 0.933, 0.565);
	glVertex2f(0.95, 0.59);
	glVertex2f(0.95, 0.35);
	glEnd();

	glColor3f(0.216, 0.376, 0.024);
	glLineWidth(3);
	glBegin(GL_POLYGON);
	glVertex2f(0.65, 0.35);
	glVertex2f(0.65, 0.72);
	glColor3f(0.565, 0.933, 0.565);
	glVertex2f(0.89, 0.72);
	glVertex2f(0.89, 0.35);
	glEnd();


	glFlush();
}

void tree2()
{
	//wood
	glColor3f(0.588, 0.294, 0.0);
	glBegin(GL_QUADS);
	glVertex2f(-0.85, 0.30);
	glVertex2f(-0.83, 0.30);
	glVertex2f(-0.83, -0.40);
	glVertex2f(-0.80, -0.40);
	glEnd();

	//leaves
	glColor3f(0.216, 0.376, 0.024);
	glLineWidth(3);
	glBegin(GL_POLYGON);
	glVertex2f(-0.65, 0.25);
	glVertex2f(-0.65, 0.48);
	glColor3f(0.565, 0.933, 0.565);
	glVertex2f(-0.92, 0.48);
	glVertex2f(-0.92, 0.25);
	glEnd();

	glColor3f(0.216, 0.376, 0.024);
	glLineWidth(3);
	glBegin(GL_POLYGON);
	glVertex2f(-0.60, 0.35);
	glVertex2f(-0.60, 0.59);
	glColor3f(0.565, 0.933, 0.565);
	glVertex2f(-0.95, 0.59);
	glVertex2f(-0.95, 0.35);
	glEnd();

	glColor3f(0.216, 0.376, 0.024);
	glLineWidth(3);
	glBegin(GL_POLYGON);
	glVertex2f(-0.65, 0.35);
	glVertex2f(-0.65, 0.72);
	glColor3f(0.565, 0.933, 0.565);
	glVertex2f(-0.89, 0.72);
	glVertex2f(-0.89, 0.35);
	glEnd();


}

void tree3()
{
	//wood
	glColor3f(0.588, 0.294, 0.0);
	glBegin(GL_QUADS);
	glVertex2f(-0.53, 0.10);
	glVertex2f(-0.50, 0.10);
	glVertex2f(-0.53, -0.40);
	glVertex2f(-0.50, -0.40);
	glEnd();

	//leaves
	glColor3f(0.216, 0.376, 0.024);
	glLineWidth(3);
	glBegin(GL_POLYGON);
	glVertex2f(-0.60, 0.10);
	glVertex2f(-0.60, 0.30);
	glColor3f(0.565, 0.933, 0.565);
	glVertex2f(-0.43, 0.30);
	glVertex2f(-0.43, 0.10);
	glEnd();

	glColor3f(0.216, 0.376, 0.024);
	glLineWidth(3);
	glBegin(GL_POLYGON);
	glVertex2f(-0.60, 0.35);
	glVertex2f(-0.60, 0.59);
	glColor3f(0.565, 0.933, 0.565);
	glVertex2f(-0.95, 0.59);
	glVertex2f(-0.95, 0.35);
	glEnd();

	glColor3f(0.216, 0.376, 0.024);
	glLineWidth(3);
	glBegin(GL_POLYGON);
	glVertex2f(-0.65, 0.35);
	glVertex2f(-0.65, 0.72);
	glColor3f(0.565, 0.933, 0.565);
	glVertex2f(-0.89, 0.72);
	glVertex2f(-0.89, 0.35);
	glEnd();
}


void tower() 
{
	//base
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex2f(-0.20, 0.39);
	glVertex2f(-0.20, -0.55);
	glColor3f(0.149, 0.149, 0.149);
	glVertex2f(-0.25, -0.55);
	glVertex2f(-0.25, 0.39);
	glEnd();

	//main
	glColor3f(0.737, 0.561, 0.561);
	glBegin(GL_POLYGON);
	glVertex2f(-0.42,0.30);
	glVertex2f(-0.42, 0.70);
	glVertex2f(-0.08, 0.70);
	glVertex2f(-0.08, 0.30);
	glEnd();
	
	//window
	glColor3f(1.0,0.882,0.208);
	glBegin(GL_POLYGON);
	glVertex2f(-0.35, 0.40);
	glVertex2f(-0.35, 0.65);
	glColor3f(1.0, 0.914, 0.408);
	glVertex2f(-0.15, 0.65);
	glVertex2f(-0.15, 0.40);
	glEnd();

	//window cross
	glColor3f(0.0, 0.0, 0.0);
	glLineWidth(10);
	glBegin(GL_LINES);
	glVertex2f(-0.35, 0.525);
	glVertex2f(-0.15, 0.525);
	glVertex2f(-0.25, 0.40);
	glVertex2f(-0.25, 0.65);
	glEnd();

	//roof
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex2f(-0.45, 0.70);
	glVertex2f(-0.05, 0.70);
	glColor3f(1.00, 0.498, 0.498);
	glVertex2f(-0.25, 0.93);
	glEnd();


}

void rock()
{
    //rock 1
	glColor3f(0.4784, 0.451, 0.4471);
	circle(-0.14, -0.55, 0.25);
	glFlush();

	//rock 2
	glColor3f(0.1, 0.1, 0.1);
	circle(-0.08, -0.57, 0.55);
	glFlush();

	//rock 3
	glColor3f(0.439, 0.502, 0.565);
	circle(-0.20, -0.62, 0.55);
	glFlush();

}

void bushes()
{


	glColor3f(0.216, 0.376, 0.024);
	glLineWidth(3);
	glBegin(GL_POLYGON);
	glVertex2f(0.18, -0.35);
	glVertex2f(0.18, 0.05);
	glColor3f(0.565, 0.933, 0.565);
	glVertex2f(0.30, 0.05);
	glVertex2f(0.30, -0.35);
	glEnd();

	glColor3f(0.216, 0.376, 0.024);
	glLineWidth(3);
	glBegin(GL_POLYGON);
	glVertex2f(0.08, -0.35);
	glVertex2f(0.08, -0.10);
	glColor3f(0.565, 0.933, 0.565);
	glVertex2f(0.35, -0.10);
	glVertex2f(0.35, -0.35);
	glEnd();

	glColor3f(0.216, 0.376, 0.024);
	glLineWidth(3);
	glBegin(GL_POLYGON);
	glVertex2f(0.215, -0.35);
	glVertex2f(0.215, -0.01);
	glColor3f(0.565, 0.933, 0.565);
	glVertex2f(0.40, -0.01);
	glVertex2f(0.40, -0.35);
	glEnd();

}


void display() {
	glClear(GL_COLOR_BUFFER_BIT);

	//glColor3ub(rand() % 255, rand() % 255, rand() % 255);
	glLoadIdentity();
	glMatrixMode(GL_MODELVIEW);

	
	sky();
	ground();
	mountain();
	sun();
	tree1();
	tree2();
	tower();
	tree3();
	rock();
	bushes();
	glFlush();
}

void initGL() {
	//glClearColor(0.6706, 0.8431, 0.9216, 0.0);
	glClearColor(0.396, 0.263, 0.129, 0);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
}



int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
	glutCreateWindow("Background 1");
	initGL();
	
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);

	
	glutMainLoop();
	return 0;

}