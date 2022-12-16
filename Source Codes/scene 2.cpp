#include <windows.h>
#include <stdlib.h>
#include <gl\GL.h>
#include <gl\GLU.h>
#include <gl\glut.h>
#include <math.h>

#define PI 3.141592653

#define SCREEN_WIDTH	1000
#define SCREEN_HEIGHT	600
#define FPS 10

GLfloat yrot;

float cloud_move = 0.0f;
float cloud_move2 = 0.0f;

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
		float x1 = x + ((r - .07) * cos(A));
		float y1 = y + ((r * sin(A)));
		glVertex2f(x1, y1);
	}
	glEnd();
}
void drawCircle(float x, float y, double r)
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
	glEnd();
}

void circleRock(float x, float y, double r)
{
	float t1, r1;
	glBegin(GL_POLYGON);
	for (int i = 0; i < 200; i++)
	{
		float A = (i * 2 * PI) / 25;
		float t1 = x + ((r = .07) * cos(A));
		float r1 = y + ((r * sin(A)));
		glVertex2f(t1, r1);
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
	
	glColor3f(0.396, 0.263, 0.129);
	glBegin(GL_QUADS);
	glVertex2f(-1.0, 0.0);
	glVertex2f(-1.0, -1.0);
	glVertex2f(1.0, 0.0);
	glVertex2f(1.0, -1.0);
	glEnd();

	glFlush();

}

void mountain()
{
	//first
	glColor3f(0.4784, 0.451, 0.4471);
	glBegin(GL_POLYGON);
	glVertex2f(-1.0, -0.3);
	glVertex2f(-0.5, 0.70);
	glVertex2f(0.0, -0.3);
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
	circle(0.15, 0.75, 0.18);
	glFlush();
}

void rapunzel()
{
	glRotatef(yrot, 0, 1, 0);

	//head
	glColor3f(0.9, 0.7, 0.6);
	glBegin(GL_POLYGON);
	glVertex2f(-0.30,0.60);
	glVertex2f(-0.30, 0.53);
	glVertex2f(-0.20, 0.53);
	glVertex2f(-0.20, 0.60);
	glEnd();
	
	//upper clothes
	glColor3f(1.0, 0.0, 1.0);
	glBegin(GL_POLYGON);
	glVertex2f(-0.29,0.51);
	glVertex2f(-0.29, 0.46);
	glVertex2f(-0.23, 0.46);
	glVertex2f(-0.23, 0.51);
	glEnd();

	//skirt
	glColor3f(1.0, 0.0, 1.0);
	glBegin(GL_POLYGON);
	glVertex2f(-0.26, 0.50);
	glVertex2f(-0.23, 0.40);
	glVertex2f(-0.29, 0.40);
	glEnd();


	//hair
	glBegin(GL_POLYGON);
	glColor3d(1.0, 1.0, 0.0);
	glVertex2f(-0.30, 0.65);
	glVertex2f(-0.30, 0.60);
	glVertex2f(-0.20, 0.60);
	glVertex2f(-0.20, 0.65);
	glEnd();

	//hair part 2
	glBegin(GL_POLYGON);
	glColor3d(1.0, 1.0, 0.0); 
	glVertex2f(-0.20, 0.65);
	glVertex2f(-0.22, 0.65);
	glVertex2f(-0.22, -0.50);
	glVertex2f(-0.20, -0.50);
	glEnd();


}

void tree1()
{
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
	glVertex2f(-0.42, 0.30);
	glVertex2f(-0.42, 0.70);
	glVertex2f(-0.08, 0.70);
	glVertex2f(-0.08, 0.30);
	glEnd();

	//window
	glColor3f(1.0, 0.882, 0.208);
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
	circleRock(-0.14, -0.55, 0.10);
	glFlush();

	//rock 2
	glColor3f(0.1, 0.1, 0.1);
	circleRock(-0.08, -0.57, 0.78);
	glFlush();

	//rock 3
	glColor3f(0.439, 0.502, 0.565);
	circleRock(-0.20, -0.62, 0.80);
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

void cloud()
{
	glColor3f(0.80, 0.80, 0.80);
	circle(-0.85, 0.77, 0.15);
	circle(-0.79, 0.70, 0.15);
	circle(-0.70, 0.70, 0.15);
	circle(-0.75, 0.77, 0.15);

}

void cloud2()
{
	glColor3f(0.80, 0.80, 0.80);
	drawCircle(0.35, 0.71, 0.15);
	circle(0.45, 0.70, 0.15);
	drawCircle(0.55, 0.75, 0.15);
	circle(0.45, 0.77, 0.15);
}


void display() {
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3ub(0, 0, 128);


	//glColor3ub(rand() % 255, rand() % 255, rand() % 255);
	glLoadIdentity();
	glMatrixMode(GL_MODELVIEW);


	sky();
	ground();
	mountain();
	sun();

	glPushMatrix();
	glTranslatef(cloud_move, 0.0, 0.0);
	cloud();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(cloud_move2, 0.0, 0.0);
	cloud2();
	glPopMatrix();

	cloud_move += 0.003;
	{
		if (cloud_move > 1.9)
		{
			cloud_move = -1.0;
		}
	}

	cloud_move2 += .003;
	{
		if (cloud_move2 > 1.5)
		{
			cloud_move2 = -1.2;
		}
	}

	tree1();
	tree2();
	tower();
	rapunzel();
	tree3();
	rock();
	bushes();

	glFlush();
	glutSwapBuffers();
}

void initGL() {
	//glClearColor(0.6706, 0.8431, 0.9216, 0.0);
	glClearColor(0.396, 0.263, 0.129, 0);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
}
void idle()
{
	DWORD start = GetTickCount();
	while (GetTickCount() - start < 1000 / FPS);
	glutPostRedisplay();
}



int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
	glutCreateWindow("Scene 2");
	initGL();

	glutDisplayFunc(display);
	glutReshapeFunc(reshape);

	glutIdleFunc(idle);
	glutMainLoop();
	return 0;

}