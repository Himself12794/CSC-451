#include <GL/glut.h>
#include <math.h>

#define N 24
#define PI 3.14159265358979323846
#define WINDOW_NAME "Polygon [Philip]"

extern const float LINE_COLOR[] 		= {1.0, 0.0, 0.0};
extern const float BACKGROUND_COLOR[]	= {1.0, 1.0, 0.0};

void display() {

	double points[N][2];

	// Generate vertices
	for (int i = 0; i < N; ++i) {
		points[i][0] = cos((2 * PI * i)/N);
		points[i][1] = sin((2 * PI * i)/N);
	}

	// Draw all vertices and connect them with lines
	glBegin(GL_LINES); {

		// Set the line color
		glColor3fv(LINE_COLOR);
		for (int i = 0; i < N; ++i) {
			for (int j = N - 1; j >= 0; --j) {
				glVertex2d(points[i][0], points[i][1]);
				glVertex2d(points[j][0], points[j][1]);
			}
		}

	} glEnd();

	glFlush();
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
	glClearColor(BACKGROUND_COLOR[0], BACKGROUND_COLOR[1], BACKGROUND_COLOR[2], 1.0);
	glClear(GL_COLOR_BUFFER_BIT);

}

/**
 * The starting point for the program.
 *
 */
int main(int argc, char** argv) {

	glutInit(&argc, argv);
	glutInitWindowSize(500, 500);
	glutCreateWindow(WINDOW_NAME);
	glutDisplayFunc(display);

	init();

	glutMainLoop();
}
