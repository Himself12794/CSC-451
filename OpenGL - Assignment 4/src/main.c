#include <GL/glut.h>
#include <math.h>
#include <windows.h>

#define PI 			3.14159265358979323846
#define WINDOW_NAME "Polygon [Whiting]"
#define RADIANS(x)	x * PI / 180.0

const float LINE_COLOR[] 		= {1.0, 0.0, 0.0};
const float BACKGROUND_COLOR[]	= {1.0, 1.0, 0.0};

short fps		= 10;
int offset 		= 0;
int magnitude 	= -1;
int stopped 	= 0;
int n 			= 5;
int window_id	= 0;

/**
 * The main display function
 *
 */
void display() {

	glClearColor(BACKGROUND_COLOR[0], BACKGROUND_COLOR[1], BACKGROUND_COLOR[2], 1.0F);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	double points[n][2];

	// Generate vertices
	for (int i = 0; i < n; ++i) {
		points[i][0] = cos(((2 * PI * i)/n) + RADIANS(offset));
		points[i][1] = sin(((2 * PI * i)/n) + RADIANS(offset));
	}

	// Draw all vertices and connect them with lines
	glBegin(GL_LINES); {

		// Set the line color
		glColor3fv(LINE_COLOR);
		for (int i = 0; i < n; ++i) {
			for (int j = n - 1; j >= 0; --j) {
				glVertex2d(points[i][0], points[i][1]);
				glVertex2d(points[j][0], points[j][1]);
			}
		}

	} glEnd();

	glFlush();
}

/**
 * Called when the window is resized. Will maintain aspect-ratio.
 */
void reshape(int w, int h) {
	float ratio = (float) w / (float) h;
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (ratio >= 1.0) {
		gluOrtho2D(-1.5 * ratio, 1.5 * ratio, -1.5, 1.5);
	} else {
		gluOrtho2D(-1.5, 1.5, -1.5 / ratio, 1.5 / ratio);
	}
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void timer(int x) {
	if (!stopped) {
		offset += 1 * magnitude;
		display();
	}
	glutTimerFunc(1000 / fps, timer, 0);
}

/**
 * Called whenever we have a keyboard button press.
 */
void keyboard_event(unsigned char key, GLint x, GLint y) {
	switch (key) {

	case '0':
		stopped = 1;
		break;
	case '1':
		fps = 10;
		stopped = 0;
		break;
	case '2':
		fps = 20;
		stopped = 0;
		break;
	case 'q':
	case 'Q':
		glutDestroyWindow(window_id);
		break;
	case 'r':
	case 'R':
		magnitude *= -1;

	}

	if (key >= '3' && key <= '9') {
		n = key - '0';
		display();
	} else if (key >= 'a' && key <= 'j') {
		n = 10 + key - 'a';
		display();
	} else if (key >= 'A' && key <= 'J') {
		n = 10 + key - 'A';
		display();
	}
}

/**
 * Initializes OpenGL state by clearing colors, as well
 * as setting the view to 3 x 3 with bottom left at (-1.5, -1.5)
 * and top right at (1.5, 1.5)
 */
void init() {

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-1.5, 1.5, -1.5, 1.5);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

}

/**
 * The starting point for the program.
 *
 */
int main(int argc, char** argv) {

	// Clearing the console windows for a windows application
	ShowWindow(GetConsoleWindow(), SW_HIDE);
	FreeConsole();

	glutInit(&argc, argv);
	glutInitWindowSize(500, 500);
	window_id = glutCreateWindow(WINDOW_NAME);
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard_event);
	glutTimerFunc(1000 / fps, timer, 0);

	init();

	glutMainLoop();
}
