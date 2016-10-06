#include <GL/glut.h>
#include <math.h>
#include <stdio.h>

#define WINDOW_NAME "Colors [Whiting]"
#define CYCLE_BG cycle_color(bg_color, fg_color)
#define CYCLE_FG cycle_color(fg_color, bg_color)

GLfloat bg_color[] = {0.0, 0.0, 0.0};
GLfloat fg_color[] = {1.0, 1.0, 1.0};

int window_id = -1;

/**
 * Converts array to bit representation for easier incrementation
 */
unsigned char get_bits(GLfloat vals[]) {

	unsigned char total = 0;
	for (int i = 0; i < 3; i++) total += vals[2-i] * (pow(2, i));

	return total;
}

/**
 * Cycles the colors for an array.
 */
void cycle_color(GLfloat changed[], GLfloat comparison[]) {
	// Treating the array as binary integer for easier iteration.
	unsigned char c1 = get_bits(changed);
	unsigned char c2 = get_bits(comparison);

	c1 += 1;					/* increment color */
	if (c1 > 7) c1 = 0;			/* make sure we haven't gone over color limit */

	// Checks to make sure both colors are not the same
	if (c1 == c2) {
		if (c1 == 7) c1 = 0;
		else c1 += 1;
	}

	// Convert computed value back to binary representation
	for (int i=0;i<3;i++) changed[2-i] = (c1 >> i) & 1;
}

/**
 * Called whenever a mouse button is pressed.
 */
void mouse_event(GLint button, GLint state, GLint x, GLint y) {
	if (state == GLUT_DOWN) {
		switch (button) {
		case GLUT_LEFT_BUTTON:
			CYCLE_FG;
			break;
		case GLUT_MIDDLE_BUTTON:
			CYCLE_BG;
			break;
		}
		glutPostRedisplay();
	}
}

/**
 * Called whenever we have a keyboard button press.
 */
void keyboard_event(unsigned char key, GLint x, GLint y) {
	switch (key) {
	case 'q':
	case 'e':
		glutDestroyWindow(window_id);
		break;
	case 'f':
		CYCLE_FG;
		break;
	case 'b':
		CYCLE_BG;
		break;
	}
	glutPostRedisplay();
}

void myinit () {
    /* set background color */
    glClearColor(bg_color[0], bg_color[1], bg_color[2], 1.0);
    glColor3fv(fg_color);                       /* set foreground color */
    glMatrixMode (GL_PROJECTION);               /* modify the PROJECTION matrix */
    glLoadIdentity ();                          /* start with no transformation */
    gluOrtho2D (-1.0, 1.0, -1.0, 1.0); 			/* setting the viewing window (used in 2D) */
}

void mydisplay () {
	/* set clear (background) color */
	glClearColor(bg_color[0], bg_color[1], bg_color[2], 1.0);
    glClear(GL_COLOR_BUFFER_BIT);               /* clear the window */
    glColor3fv(fg_color);						/* set foreground color */
    glBegin(GL_POLYGON);                        /* define a polygon */
        glVertex2f (-0.5, -0.5);                /* define vertices */
        glVertex2f (-0.5, 0.5);
        glVertex2f (0.5, 0.5);
        glVertex2f (0.5, -0.5);
    glEnd ();                                   /* end of definition */
    glFlush ();                                 /* flush so the image appears */
}

int main (int argc, char** argv) {
    glutInit (&argc, argv);                     /* initial the openGL system */
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);  /* use single buffer and RGB mode */
    glutInitWindowSize(500, 500);               /* window size */
    glutInitWindowPosition (0, 0);              /* window position */
    window_id = glutCreateWindow(WINDOW_NAME);  /* create window with given caption */
    glutDisplayFunc(&mydisplay);				/* bind the display callback */
    glutMouseFunc(&mouse_event);				/* bind the mouse callback */
    glutKeyboardFunc(&keyboard_event);			/* bind the keyboard callback */
    myinit();                                   /* initialize states and attributes */
    glutMainLoop ();                            /* enter the event loop */
}

