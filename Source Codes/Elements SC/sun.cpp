#include <windows.h>
#include <stdlib.h>
#include <gl\GL.h>
#include <gl\GLU.h>
#include <gl\glut.h>
#include <math.h>

#define PI 3.141592653

#define SCREEN_WIDTH	1000
#define SCREEN_HEIGHT	600

void sun(int n, int x, int y, int r) {
	double inc = 2 * PI / (double)n;
	glBegin(GL_POLYGON);
	for (double theta = 0.0; theta <= 2 * PI; theta += inc) {
		glVertex2i(r * cos(theta) + x, r * sin(theta) + y);
	}
	glEnd();
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3ub(255, 255, 0);

	sun(360, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 70);

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
	glutCreateWindow("Sun");
	glutDisplayFunc(display);

	initGL();

	glutMainLoop();

}
