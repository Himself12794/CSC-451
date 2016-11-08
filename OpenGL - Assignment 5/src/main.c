#include <stdlib.h>
#include <time.h>
#include <GL\glut.h>

typedef GLfloat point2 [2];
typedef GLfloat color [3];

point2 vertices [3][3];

void triangle(point2 a, point2 b, point2 c, color fill);

void init();
void initVertices();

void display();
void timer(int value);

int angle = 0;

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Assignment 5 [Whiting]");
    glutDisplayFunc(display);
    glutTimerFunc(0, timer, 0);
    init();
    glutMainLoop();
    return 0;
}

void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 1.0, 0.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    initVertices();
}

void display() {
    color red = {1.0, 0.0, 0.0};
    color green = {0.0, 1.0, 0.0};
    color blue = {0.0, 0.0, 1.0};

    glClear(GL_COLOR_BUFFER_BIT);
    
    triangle(vertices[0][0], vertices[0][1], vertices[0][2], red);
    triangle(vertices[1][0], vertices[1][1], vertices[1][2], green);
    triangle(vertices[2][0], vertices[2][1], vertices[2][2], blue);

    glFlush();
    glutSwapBuffers();
}

/**
 * Rotate 2d item around a certain point
 */
void do_rotate(float ang, point2 p) {

}

void triangle(point2 a, point2 b, point2 c, color fill) {
    point2 mid;

    mid [0] = (a[0] + b[0] + c[0]) / 3.0;
    mid [1] = (a[1] + b[1] + c[1]) / 3.0;

    // Store matrix state
    glPushMatrix();

    // Do transformations and drawing
	glTranslatef(mid[0], mid[1], 0.0f);
	glRotatef(angle, 0.0f, 0.0f, 1.0f);
	glTranslatef(-mid[0], -mid[1], 0.0f);
    glColor3fv(fill);

    glBegin(GL_TRIANGLES);
    	glVertex2fv(a);
    	glVertex2fv(b);
    	glVertex2fv(c);
    glEnd();

    glColor3f(1.0, 1.0, 1.0);
    glPointSize(5.0);
    glBegin(GL_POINTS);
    glVertex2fv(mid);
    glEnd();

    // Restore matrix state
    glPopMatrix();
    glPointSize(1.0);
}

/**
 * Called every 0.1 seconds and increments the angle by 1 degree.
 */
void timer(int x) {
	angle++;
	glutPostRedisplay();
	glutTimerFunc(100, timer, 0);
}

void initVertices() {
    int i, j, k;
    unsigned int iseed = (unsigned int)time(NULL);
    srand(iseed);

    for (i = 0; i < 3; i++) {

        for (j = 0; j < 3; j++) {

            for (k = 0; k < 2; k++) {
                vertices [i][j][k] = rand() / (RAND_MAX + 1.0);
            }
        }
    }
}
