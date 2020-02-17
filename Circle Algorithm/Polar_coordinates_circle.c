#include<stdio.h>
#include<GL/glut.h>
#include<math.h>
#include<stdlib.h>

int x1,yr,r;

void Polar_Circle(void)
{
	int i,x,y;
	float theta;
	
	for(i=0;i<=360;i++){
		theta=(i*3.14)/180;
		x=(int)(x1+(r*cos(theta)));
		y=(int)(yr+(r*sin(theta)));
		glBegin(GL_POINTS);
		glVertex2d(x,y);
		glEnd();
	}
	
	glFlush();
}

void init(void)
{
	glClearColor(1.0, 14.0, 51.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-100,100,-100,100);
}

int main(int argc, char** argv)
{
	printf("Enter the value of x1: ");
	scanf("%d",&x1);
	printf("Enter the value of y1: ");
	scanf("%d",&yr);
	printf("Enter the value of radius of circle: ");
	scanf("%d",&r);

	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (500, 500);
	glutInitWindowPosition (100,100);
	glutCreateWindow ("Circle Using Polar Co-ordinates");
	init();
	glutDisplayFunc(Polar_Circle);
	glutMainLoop();

	return 0;
}