/* Triangle rotation */
#include <GL/glut.h>
#include <math.h>
#include <stdio.h>

GLfloat tri[3][3] = { { 100, 100, 0 }, { 200, 100, 0 }, { 150, 200, 0 } };
GLfloat arb_x = 100;
GLfloat arb_y = 100;
GLfloat rot_angle;

void drawtri()
{

	glBegin(GL_LINE_LOOP);
	glVertex3fv(tri[0]);
	glVertex3fv(tri[1]);
	glVertex3fv(tri[2]);
	glEnd();
}
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1, 0, 0);
	drawtri();
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(arb_x, arb_y, 0.0);
	glRotatef(rot_angle, 0.0, 0.0, 1.0);
	glTranslatef(-arb_x, -arb_y, 0.0);
	glColor3f(0, 1, 0);
	drawtri();
	glTranslatef(0.0, 0.0, 0.0);
	glRotatef(rot_angle, 0.0, 0.0, 1.0);
	glTranslatef(-0.0, -0.0, 0.0);
	glColor3f(0, 0, 1);
	drawtri();

	glFlush();
}
void myinit()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glColor3f(1.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-250.0, 499.0, -250.0, 499.0);
}

void main(int argc, char* argv[])
{
	printf("\nENTER THE ROTATION ANGLE :-\n");
	scanf("%f", &rot_angle);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("House Rotation");
	glutDisplayFunc(display);
	myinit();
	glutMainLoop();
}
