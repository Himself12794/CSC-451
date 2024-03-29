#include <GL/glut.h>

GLfloat v[3][2] = {{-1.0, -0.58}, {1.0, -0.58}, {0.0, 1.15}};
int n = 8;

void triangle (GLfloat *a, GLfloat *b, GLfloat *c) {
    glVertex2fv (a);
    glVertex2fv (b);
    glVertex2fv (c);
}

void divide_triangle (GLfloat *a, GLfloat *b, GLfloat *c, int m) {
    GLfloat v0[2], v1[2], v2[2];
    int j;
    
    if (m == 0)
    {
        triangle (a, b, c);
    }
    else
    {
        for (j = 0; j < 2; j++)
        {
            v0 [j] = (a [j] + b [j]) / 2;
            v1 [j] = (a [j] + c [j]) / 2;
            v2 [j] = (b [j] + c [j]) / 2;
        }
        divide_triangle (a, v0, v1, m-1);
        divide_triangle (c, v1, v2, m-1);
        divide_triangle (b, v2, v0, m-1);
    }
}

void display (void) {
    glClear (GL_COLOR_BUFFER_BIT);
    glBegin (GL_TRIANGLES);
        divide_triangle (v[0], v[1], v[2], n);
    glEnd ();
    glFlush ();
}

void myinit (void) {
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity ();
    gluOrtho2D (-2.0, 2.0, -2.0, 2.0);
    glMatrixMode (GL_MODELVIEW);
    glClearColor (1.0, 1.0, 1.0, 1.0);
    glColor3f (1.0, 0.0, 0.0);
}

/*int main (int argc, char **argv) {
    glutInit (&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (500, 500);
    glutCreateWindow ("2D Gasket");
    glutDisplayFunc (display);
    myinit ();
    glutMainLoop ();
    return 0;
}*/
