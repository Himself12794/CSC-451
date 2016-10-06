#include <GL/glut.h>
#include <math.h>
#include <stdio.h>

#define WINDOW_NAME "Polygon [Philip]"

GLfloat bg_colors[] = {0.0, 0.0, 0.0};
GLfloat fg_colors[] = {1.0, 1.0, 1.0};

void mouse_event(GLint button, GLint state, GLint x, GLint y) {
	printf("We have mouse event/n");
}

void myinit () {
    glClearColor (0.0, 0.0, 0.0, 1.0);          /* black background */
    glColor3f (1.0, 1.0, 1.0);                  /* draw in white */
    glMatrixMode (GL_PROJECTION);               /* modify the PROJECTION matrix */
    glLoadIdentity ();                          /* start with no transformation */
    gluOrtho2D (-1.0, 1.0, -1.0, 1.0); /* setting the viewing window (used in 2D) */
}

void mydisplay () {
    glClear (GL_COLOR_BUFFER_BIT);              /* clear the window */
    glBegin (GL_POLYGON);                       /* define a polygon */
        glVertex2f (-0.5, -0.5);                /* define vertices */
        glVertex2f (-0.5, 0.5);
        glVertex2f (0.5, 0.5);
        glVertex2f (0.5, -0.5);
    glEnd ();                                   /* end of definition */
    glFlush ();                                 /* flush so the image appears */
}

int main (int argc, char** argv)
{
    glutInit (&argc, argv);                     /* initial the openGL system */
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);  /* use single buffer and RGB mode */
    glutInitWindowSize(500, 500);               /* window size */
    glutInitWindowPosition (0, 0);              /* window position */
    glutCreateWindow(WINDOW_NAME);              /* create window with given caption */
    glutDisplayFunc(mydisplay);                 /* bind the display callback */
    glutMouseFunc(mouse_event);
    myinit();                                   /* initialize states and attributes */
    glutMainLoop ();                            /* enter the event loop */
}

