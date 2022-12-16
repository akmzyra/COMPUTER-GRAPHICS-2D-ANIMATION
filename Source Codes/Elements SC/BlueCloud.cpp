#include <windows.h>
#include <stdlib.h>
#include <gl\GL.h>
#include <gl\GLU.h>
#include <gl\glut.h>
#include <math.h>

#define PI 3.141592653

#define SCREEN_WIDTH	1000
#define SCREEN_HEIGHT	600

void blueCloud(int n, int x, int y, int r) {
	double inc = 2 * PI / (double)n;
	glBegin(GL_POLYGON);
	for (double theta = 0.0; theta <= 2 * PI; theta += inc) {
		glVertex2i(r * cos(theta) + x, r * sin(theta) + y);
	}
	glEnd();
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3ub(0, 0, 128);

	//cloud 1 (n, x, y, r)
	blueCloud(360, 200, 500, 35);
	blueCloud(360, 265, 500, 50);
	blueCloud(360, 320, 500, 30);
	blueCloud(360, 330, 500, 40);

	//cloud 2 (n, x, y, r)
	blueCloud(360, 700, 500, 35);
	blueCloud(360, 765, 500, 50);
	blueCloud(360, 820, 500, 30);
	blueCloud(360, 830, 500, 40);

	glFlush();
}

void initGL() {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, SCREEN_WIDTH, 0, SCREEN_HEIGHT);
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
	glutCreateWindow("Blue Cloud");
	glutDisplayFunc(display);

	initGL();

	glutMainLoop();

}