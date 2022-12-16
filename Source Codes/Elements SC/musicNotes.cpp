#include <windows.h>
#include <stdlib.h>
#include <gl\GL.h>
#include <gl\GLU.h>
#include <gl\glut.h>
#include <math.h>

#define PI 3.141592653

#define SCREEN_WIDTH	1000
#define SCREEN_HEIGHT	600

void musicNotes(int n, int x, int y, int r) {
	for (int i = 0; i < 4; i++) {

		//circle
		double inc = 2 * PI / (double)n;
		glBegin(GL_POLYGON);
		for (double theta = 0.0; theta <= 2 * PI; theta += inc) {
			glVertex2i(r * cos(theta) + x, r * sin(theta) + y);
		}
		glEnd();

		//vertical line
		glLineWidth(2.0);
		glBegin(GL_LINES);
		glVertex2i(x + 9, y);
		glVertex2i(x + 9, y + 50);
		glEnd();

		//horizontal line
		glLineWidth(2.0);
		glBegin(GL_LINES);
		glVertex2i(x + 9, y + 50);
		glVertex2i(x + 19, y + 50);
		glEnd();

		x = x + 25;
		y = y + 7;
	}
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3ub(0, 0, 0);

	//(n, x, y, r)
	musicNotes(360, 500, 300, 10);

	glFlush();
}

void initGL() {
	glClearColor(255.0, 255.0, 255.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, SCREEN_WIDTH, 0, SCREEN_HEIGHT);
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
	glutCreateWindow("Music Note");
	glutDisplayFunc(display);

	initGL();

	glutMainLoop();

}
