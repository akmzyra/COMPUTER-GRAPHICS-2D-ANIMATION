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
	void mountain();
	{
		glBegin(GL_TRIANGLES);
		glColor3ub(96, 168, 48);
		glVertex2f(0.0, 0.5);
		glVertex2f(-0.3, -0.4);
		glVertex2f(0.3, -0.5);
		glEnd();

		//mountain_ice
		glBegin(GL_TRIANGLES);
		glColor3ub(1.0f, 1.0f, 1.0f);
		glVertex2f(0.0, 0.5);
		glVertex2f(-0.2, -0.4);
		glVertex2f(0.2, -0.4);
		glEnd();
	}

}

void tree6()
{
	//wood
	glColor3ub(138, 98, 74);
	glBegin(GL_POLYGON);
	glVertex2f(0.885, 0.30);
	glVertex2f(0.825, 0.30);
	glVertex2f(0.825, -0.40);
	glVertex2f(0.885, -0.40);
	glEnd();


	//tree_body
	glColor3ub(60, 102, 62);
	glLineWidth(3);
	glBegin(GL_POLYGON);
	glVertex2f(0.975, 0.165);
	glVertex2f(0.975, 0.480);
	glVertex2f(0.740, 0.480);
	glVertex2f(0.740, 0.165);
	glEnd();

	//leaf 1
	glColor3ub(88, 132, 67);
	glBegin(GL_POLYGON);
	glVertex2f(0.860, 0.40);
	glVertex2f(0.860, 0.59);
	glVertex2f(0.995, 0.59);
	glVertex2f(0.995, 0.40);
	glEnd();

	//leaf 2
	glColor3ub(88, 132, 67);
	glBegin(GL_POLYGON);
	glVertex2f(0.800, 0.34);
	glVertex2f(0.800, 0.55);
	glVertex2f(0.695, 0.55);
	glVertex2f(0.695, 0.34);
	glEnd();

	//leaf 3
	glColor3ub(88, 132, 67);
	glBegin(GL_POLYGON);
	glVertex2f(0.860, 0.14);
	glVertex2f(0.860, 0.29);
	glVertex2f(0.765, 0.29);
	glVertex2f(0.765, 0.14);
	glEnd();


	//leaf 4
	glColor3ub(88, 132, 67);
	glBegin(GL_POLYGON);
	glVertex2f(0.890, 0.10);
	glVertex2f(0.890, 0.25);
	glVertex2f(0.992, 0.25);
	glVertex2f(0.992, 0.10);
	glEnd();

}

void tree5()
{
	//wood
	glColor3ub(138, 98, 74);
	glBegin(GL_POLYGON);
	glVertex2f(0.630, 0.10);
	glVertex2f(0.580, 0.10);
	glVertex2f(0.580, -0.40);
	glVertex2f(0.630, -0.40);
	glEnd();

	//tree_body
	glColor3ub(60, 102, 62);
	glLineWidth(3);
	glBegin(GL_POLYGON);
	glVertex2f(0.710, 0.1);
	glVertex2f(0.710, 0.4);
	glVertex2f(0.520, 0.4);
	glVertex2f(0.520, 0.1);
	glEnd();

	//leaf 1
	glColor3ub(88, 132, 67);
	glBegin(GL_POLYGON);
	glVertex2f(0.590, 0.30);
	glVertex2f(0.590, 0.49);
	glVertex2f(0.675, 0.49);
	glVertex2f(0.675, 0.30);
	glEnd();

	//leaf 2
	glColor3ub(88, 132, 67);
	glBegin(GL_POLYGON);
	glVertex2f(0.460, 0.34);
	glVertex2f(0.460, 0.52);
	glVertex2f(0.570, 0.52);
	glVertex2f(0.570, 0.34);
	glEnd();

	//leaf 3
	glColor3ub(88, 132, 67);
	glBegin(GL_POLYGON);
	glVertex2f(0.470, 0.14);
	glVertex2f(0.470, 0.29);
	glVertex2f(0.540, 0.29);
	glVertex2f(0.540, 0.14);
	glEnd();

	//leaf 4
	glColor3ub(88, 132, 67);
	glBegin(GL_POLYGON);
	glVertex2f(0.590, 0.03);
	glVertex2f(0.590, 0.2);
	glVertex2f(0.690, 0.2);
	glVertex2f(0.690, 0.03);
	glEnd();


}

void tree1()
{
	//wood
	glColor3ub(138, 98, 74);
	glBegin(GL_POLYGON);
	glVertex2f(-0.800, 0.10);
	glVertex2f(-0.690, 0.10);
	glVertex2f(-0.690, -0.40);
	glVertex2f(-0.800, -0.40);
	glEnd();

	//tree_body
	glColor3ub(60, 102, 62);
	glLineWidth(3);
	glBegin(GL_POLYGON);
	glVertex2f(-0.900, -0.1);
	glVertex2f(-0.900, 0.4);
	glVertex2f(-0.590, 0.4);
	glVertex2f(-0.590, -0.1);
	glEnd();

	//leaf 1
	glColor3ub(88, 132, 67);
	glBegin(GL_POLYGON);
	glVertex2f(-0.930, 0.30);
	glVertex2f(-0.930, 0.49);
	glVertex2f(-0.825, 0.49);
	glVertex2f(-0.825, 0.30);
	glEnd();

	//leaf 2
	glColor3ub(88, 132, 67);
	glBegin(GL_POLYGON);
	glVertex2f(-0.980, -0.04);
	glVertex2f(-0.980, 0.18);
	glVertex2f(-0.850, 0.18);
	glVertex2f(-0.850, -0.04);
	glEnd();

	//leaf 3
	glColor3ub(88, 132, 67);
	glBegin(GL_POLYGON);
	glVertex2f(-0.834, -0.154);
	glVertex2f(-0.834, 0.11);
	glVertex2f(-0.700, 0.11);
	glVertex2f(-0.700, -0.154);
	glEnd();

	//leaf 4
	glColor3ub(88, 132, 67);
	glBegin(GL_POLYGON);
	glVertex2f(-0.584, -0.04);
	glVertex2f(-0.584, -0.11);
	glVertex2f(-0.632, -0.11);
	glVertex2f(-0.632, -0.04);
	glEnd();

	//leaf 5
	glColor3ub(88, 132, 67);
	glBegin(GL_POLYGON);
	glVertex2f(-0.574, 0.54);
	glVertex2f(-0.574, 0.27);
	glVertex2f(-0.734, 0.27);
	glVertex2f(-0.734, 0.54);
	glEnd();
}

void tree2()
{
	//wood
	glColor3ub(138, 98, 74);
	glBegin(GL_POLYGON);
	glVertex2f(-0.408, 0.05);
	glVertex2f(-0.368, 0.05);
	glVertex2f(-0.368, -0.40);
	glVertex2f(-0.408, -0.40);
	glEnd();

	//tree_body
	glColor3ub(60, 102, 62);
	glLineWidth(3);
	glBegin(GL_POLYGON);
	glVertex2f(-0.490, 0.005);
	glVertex2f(-0.490, 0.38);
	glVertex2f(-0.300, 0.38);
	glVertex2f(-0.300, 0.005);
	glEnd();

	//leaf 1
	glColor3ub(88, 132, 67);
	glBegin(GL_POLYGON);
	glVertex2f(-0.420, -0.05);
	glVertex2f(-0.420, 0.09);
	glVertex2f(-0.315, 0.09);
	glVertex2f(-0.315, -0.05);
	glEnd();

	//leaf 2
	glColor3ub(88, 132, 67);
	glBegin(GL_POLYGON);
	glVertex2f(-0.370, 0.134);
	glVertex2f(-0.370, 0.292);
	glVertex2f(-0.227, 0.292);
	glVertex2f(-0.227, 0.134);
	glEnd();

	//leaf 3
	glColor3ub(88, 132, 67);
	glBegin(GL_POLYGON);
	glVertex2f(-0.470, -0.04);
	glVertex2f(-0.470, 0.09);
	glVertex2f(-0.540, 0.09);
	glVertex2f(-0.540, -0.04);
	glEnd();

	//leaf 4
	glColor3ub(88, 132, 67);
	glBegin(GL_POLYGON);
	glVertex2f(-0.430, 0.33);
	glVertex2f(-0.430, 0.13);
	glVertex2f(-0.545, 0.13);
	glVertex2f(-0.545, 0.33);
	glEnd();


}

void tree4()
{
	//wood
	glColor3ub(138, 98, 74);
	glBegin(GL_POLYGON);
	glVertex2f(0.300, 0.30);
	glVertex2f(0.250, 0.30);
	glVertex2f(0.250, -0.40);
	glVertex2f(0.300, -0.40);
	glEnd();

	//tree_body
	glColor3ub(60, 102, 62);
	glLineWidth(3);
	glBegin(GL_POLYGON);
	glVertex2f(0.150, 0.1);
	glVertex2f(0.150, 0.5);
	glVertex2f(0.380, 0.5);
	glVertex2f(0.380, 0.1);
	glEnd();

	//leaf 1
	glColor3ub(88, 132, 67);
	glBegin(GL_POLYGON);
	glVertex2f(0.300, 0.30);
	glVertex2f(0.300, 0.49);
	glVertex2f(0.425, 0.49);
	glVertex2f(0.425, 0.30);
	glEnd();

	//leaf 2
	glColor3ub(88, 132, 67);
	glBegin(GL_POLYGON);
	glVertex2f(0.240, 0.34);
	glVertex2f(0.240, 0.52);
	glVertex2f(0.10, 0.52);
	glVertex2f(0.10, 0.34);
	glEnd();

	//leaf 3
	glColor3ub(88, 132, 67);
	glBegin(GL_POLYGON);
	glVertex2f(0.24, 0.04);
	glVertex2f(0.24, 0.19);
	glVertex2f(0.34, 0.19);
	glVertex2f(0.34, 0.04);
	glEnd();
}

void tree3()
{
	//wood
	glColor3ub(138, 98, 74);
	glBegin(GL_POLYGON);
	glVertex2f(-0.02, -0.05);
	glVertex2f(0.07, -0.05);
	glVertex2f(0.07, -0.40);
	glVertex2f(-0.02, -0.40);
	glEnd();

	//tree_body
	glColor3ub(60, 102, 62);
	glLineWidth(3);
	glBegin(GL_POLYGON);
	glVertex2f(0.112, 0.3);
	glVertex2f(0.112, -0.06);
	glVertex2f(-0.110, -0.06);
	glVertex2f(-0.110, 0.3);
	glEnd();

	//leaf 1
	glColor3ub(88, 132, 67);
	glBegin(GL_POLYGON);
	glVertex2f(0.130, 0.33);
	glVertex2f(0.130, 0.12);
	glVertex2f(0.005, 0.12);
	glVertex2f(0.005, 0.33);
	glEnd();

	//leaf 2
	glColor3ub(88, 132, 67);
	glBegin(GL_POLYGON);
	glVertex2f(-0.011, 0.24);
	glVertex2f(-0.011, 0.02);
	glVertex2f(-0.155, 0.02);
	glVertex2f(-0.155, 0.24);
	glEnd();

	//leaf 3
	glColor3ub(88, 132, 67);
	glBegin(GL_POLYGON);
	glVertex2f(0.01, 0.00);
	glVertex2f(0.01, -0.1);
	glVertex2f(-0.054, -0.1);
	glVertex2f(-0.054, 0.00);
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

	glutTimerFunc(200, princeMove, 0);
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
   mountain();
	ground();
	tree1();
	tree2();
	tree3();
	tree4();
	tree5();
	tree6();
	

	glPushMatrix();
	glTranslatef(mmove + 0.01, mmove + 0.01, 0);
	if (mmove > 0.60)
		mmove = 0.0;
	
	musicNotes();
	glPopMatrix();
	glPushMatrix();

	glPushMatrix();
	glTranslatef(-pmove , 0, 0); //prince moves right to left
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