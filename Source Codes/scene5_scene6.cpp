#include <windows.h>
#include <stdlib.h>
#include <gl\GL.h>
#include <gl\GLU.h>
#include <gl\glut.h>
#include <math.h>

#define PI 3.141592653

#define SCREEN_WIDTH	1000
#define SCREEN_HEIGHT	600
#define FPS	30

void reshape(GLsizei w, GLsizei h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, SCREEN_WIDTH, 0, SCREEN_HEIGHT);
}

void circle(float x, float y, double r) {
	float A, x1, y1;
	glBegin(GL_POLYGON);
		for (int i = 0; i < 200; i++) {
			A = (i * 2 * PI) / 25;
			x1 = x + (r * cos(A));
			y1 = y + ((r * sin(A)));
			glVertex2f(x1, y1);
		}
	glEnd();
}

void sky() {
	glColor3f(0.902, 0.584, 0.0);
	glBegin(GL_QUADS);
		glVertex2f(-1.0, 0.0);
		glVertex2f(-1.0, 1.0);
		glColor3f(1.0, 0.459, 0.102);
		glVertex2f(1.0, 1.0);
		glVertex2f(1.0, 0.0);
	glEnd();
}

void ground() {
	glColor3f(0.396, 0.263, 0.129);
	glBegin(GL_QUADS);
		glVertex2f(-1.0, 0.0);
		glVertex2f(-1.0, -1.0);
		glVertex2f(1.0, 0.0);
		glVertex2f(1.0, -1.0);
	glEnd();
}

void mountain() {
	//first
	glColor3f(0.4784, 0.451, 0.4471);
	glBegin(GL_POLYGON);
		glVertex2f(-1.0, -0.3);
		glVertex2f(-0.5, 0.70);
		glVertex2f(0.0, -0.3);
	glEnd();

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

	glColor3f(0.4784, 0.451, 0.4471);
	glBegin(GL_POLYGON);
		glVertex2f(0.30, 0.30);
		glVertex2f(0.70, 0.30);
		glColor3f(0.906, 0.906, 0.906);
		glVertex2f(0.50, 0.70);
	glEnd();
}

void sun() {
	glColor3f(1.000, 0.843, 0.000);
	circle(0.90, 0.78, 0.075);
}

void tree1() {
	//wood
	glColor3f(0.588, 0.294, 0.0);
	glBegin(GL_QUADS);
		glVertex2f(0.85, 0.30);
		glVertex2f(0.83, 0.30);
		glVertex2f(0.83, -0.40);
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
}

void tree2() {
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

void tree3() {
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

void tower() {
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
		glVertex2f(-0.42, 0.30);
		glVertex2f(-0.42, 0.70);
		glVertex2f(-0.03, 0.70);
		glVertex2f(-0.03, 0.30);
	glEnd();

	//window
	glColor3f(1.0, 0.782, 0.308);
	glBegin(GL_POLYGON);
		glVertex2f(-0.35, 0.40);
		glVertex2f(-0.10, 0.40);
		glVertex2f(-0.10, 0.65);
		glVertex2f(-0.35, 0.65);
	glEnd();

	//roof
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
		glVertex2f(-0.45, 0.70);
		glVertex2f(0.00, 0.70);
		glColor3f(1.00, 0.498, 0.498);
		glVertex2f(-0.22, 0.93);
	glEnd();
}

void rock() {
	//rock 1
	glColor3f(0.4784, 0.451, 0.4471);
	circle(-0.14, -0.55, 0.075);

	//rock 2
	glColor3f(0.1, 0.1, 0.1);
	circle(-0.08, -0.57, 0.075);

	//rock 3
	glColor3f(0.439, 0.502, 0.565);
	circle(-0.20, -0.62, 0.075);
}

void bushes() {
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

void rapunzelSinging() {
	//upperbody
	glBegin(GL_POLYGON);
		glColor3f(1.0, 0.0, 1.0); glVertex2f(-0.30, 0.40);
		glColor3f(1.0, 0.0, 1.0); glVertex2f(-0.20, 0.40);
		glColor3f(1.0, 0.0, 1.0); glVertex2f(-0.20, 0.45);
		glColor3f(1.0, 0.0, 1.0); glVertex2f(-0.30, 0.45);
		glEnd();

	//neck
	glBegin(GL_POLYGON);
		glColor3f(0.9, 0.7, 0.6); glVertex2f(-0.28, 0.45);
		glColor3f(0.9, 0.7, 0.6); glVertex2f(-0.22, 0.45);
		glColor3f(0.9, 0.7, 0.6); glVertex2f(-0.22, 0.48);
		glColor3f(0.9, 0.7, 0.6); glVertex2f(-0.28, 0.48);
	glEnd();

	//head
	glBegin(GL_POLYGON);
		glColor3f(0.9, 0.7, 0.6); glVertex2f(-0.18, 0.58);
		glColor3f(0.9, 0.7, 0.6); glVertex2f(-0.32, 0.58);
		glColor3f(0.9, 0.7, 0.6); glVertex2f(-0.32, 0.53);
		glColor3f(0.9, 0.7, 0.6); glVertex2f(-0.28, 0.48);
		glColor3f(0.9, 0.7, 0.6); glVertex2f(-0.22, 0.48);
		glColor3f(0.9, 0.7, 0.6); glVertex2f(-0.18, 0.53);
	glEnd();

	//hair
	glBegin(GL_POLYGON);
		glColor3d(1.0, 1.0, 0.0); glVertex2f(-0.32, 0.64);
		glColor3d(1.0, 1.0, 0.0); glVertex2f(-0.32, 0.58);
		glColor3d(1.0, 1.0, 0.0); glVertex2f(-0.18, 0.58);
		glColor3d(1.0, 1.0, 0.0); glVertex2f(-0.18, 0.64);
	glEnd();

	//hair part 2
	glBegin(GL_POLYGON);
		glColor3d(1.0, 1.0, 0.0); glVertex2f(-0.18, 0.64);
		glColor3d(1.0, 1.0, 0.0); glVertex2f(-0.18, -0.30);
		glColor3d(1.0, 1.0, 0.0); glVertex2f(-0.14, -0.30);
		glColor3d(1.0, 1.0, 0.0); glVertex2f(-0.14, 0.64);
	glEnd();
}

//music notes move
GLfloat mmove = 0.0;
void musicMove(int value) {
	mmove += 0.05;

	glutSwapBuffers();
	glutPostRedisplay();

	glutTimerFunc(300, musicMove, 0);
}

void musicNotes() {
	glColor3ub(0, 0, 0);
	
		circle(0.04, 0.55, 0.02);
		
		//vertical line
		glLineWidth(3.0);
		glBegin(GL_LINES);
			glVertex2f(0.057, 0.54);
			glVertex2f(0.057, 0.68);
		glEnd();

		//horizontal line
		glLineWidth(3.0);
		glBegin(GL_LINES);
			glVertex2f(0.057, 0.68);
			glVertex2f(0.08, 0.68);
		glEnd();
}

//prince moves right to left and climbs up rapunzel's hair
GLfloat pmove = 0.0;
void princeMove(int value) {
	pmove -= 0.05;
	
	glutSwapBuffers();
	glutPostRedisplay();

	glutTimerFunc(300, princeMove, 0);
}

void prince() {
	glScalef(0.3f, 0.3f, 1.0f);
	glTranslatef(1.5f, -1.0f, 0.0f);
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

void display() {
	glClear(GL_COLOR_BUFFER_BIT);

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
	rapunzelSinging();

	glPushMatrix();
	glTranslatef(mmove + 0.01, mmove + 0.01, 0);
	if (mmove > 0.60)
		mmove = 0.0;
	musicNotes();
	glPopMatrix();
	glPushMatrix();

	glPushMatrix();
	glTranslatef(pmove + 0.01, 0, 0); //prince moves right to left
	if (pmove < -0.65)
		glTranslatef(0, pmove + 1.1, 0); //prince climbs up rapunzel's hair
	if (pmove < -0.65)
		pmove = 0.0;
	prince();
	glPopMatrix();
	glPushMatrix();
	
	glFlush();
	glutSwapBuffers();
}

void initGL() {
	glClearColor(0.396, 0.263, 0.129, 0);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
}

int main(int argc, char** argv) {
	glutInitDisplayMode(GLUT_DOUBLE);
	glutInit(&argc, argv);
	glutInitWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
	glutCreateWindow("Scene 5");

	initGL();

	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutTimerFunc(300, princeMove, 0);
	glutTimerFunc(300, musicMove, 0);
	
	glutMainLoop();

	return 0;
}