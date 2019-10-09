#include<stdio.h>
#include<GL/glut.h>
#include<math.h>
#include<stdlib.h>

int x1,yr,x2,y2;

void Bresenham(void)
{
	int x,y,dx,dy,p;
	
	//initialising the initial point and plot
	x = x1;
	y = yr;
	 
	// Calculating the change in Dx aand Dy
	dx = x2-x1;
	dy = y2-yr;
	
	// Calculating the decision factor
	p = (2*dx)+dy;
	
	//iterating the loop till x will reach x2 as this program is for m<1
	while(x <= x2){
	
	//Put pixel (x,y)
	glBegin(GL_POINTS);
	glVertex2d(x,y);
	glEnd();
	
	x++;//as m is smaller than 1
	
	if(p<0){
		p=p+(2*dy);
		}
	else{
		p=p+(2*dy)-(2*dx);
		y++;
		}	
	}
	
	glFlush();
	}

void init(void)
	{
	glClearColor(0.0,0.0,0.0,0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-100,100,-100,100);
	}

	int main(int argc, char** argv) {
	printf("Enter the value of x1 : ");
	scanf("%d",&x1);
	printf("Enter the value of y1 : ");
	scanf("%d",&yr);
	printf("Enter the value of x2 : ");
	scanf("%d",&x2);
	printf("Enter the value of y2 : ");
	scanf("%d",&y2);

	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (500, 500);
	glutInitWindowPosition (100,100);
	glutCreateWindow ("DDA Line Algo");
	init();
	glutDisplayFunc(Bresenham);
	glutMainLoop();

	return 0;
}