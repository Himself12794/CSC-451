#include <GL/glut.h>
#include <iostream>

using namespace std;

void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3f(0.5f, 0.0f, 1.0f);

	glBegin(GL_POLYGON);
		glVertex2f(-0.5, -0.5);
		glVertex2f(0.5, -0.5);
		glVertex2f(0.5, 0.5);
		glVertex2f(-0.5, 0.5);
	glEnd();

	glutSwapBuffers();

	glFlush();
}

int main(int argc, char** argv) {

	glutInit(&argc, argv);
	glutInitWindowSize(750, 750);
	glutCreateWindow("Mares eat oats and does eat oats");
	glutDisplayFunc(display);
	glutMainLoop();

}
