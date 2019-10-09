#include<stdio.h>
#include<GL/glut.h>
#include<math.h>
#include<stdlib.h>

int x1,yr,x2,y2;

void DDA(void)
{
	float step,k,x,y,Xinc,Yinc;
	int dx,dy;
	
	// Calculating the change in Dx aand Dy
	dx = x2-x1;
	dy = y2-yr;
	
	// Calculating the step value
	if(abs(dx)>= abs(dy)){
		step = abs(dx);
	}
	else 
	step = abs(dy);
	
	// Calculating the increment factor
	Xinc = dx/step;
	Yinc = dy/step;
	
	//initialising the initial point and plot
	x = x1;
	y = yr;
	
	//ploting the points
	glBegin(GL_POINTS);
	glVertex2i(x,y);
	glEnd();

	// obtaining the pixel values on the line and plot
	for(k=0;k<=step;k++){
	x = x + Xinc;
	y = y + Yinc;
	
	x = round(x);
	y = round(y);
		
	glBegin(GL_POINTS);
	glVertex2d(x,y);
	glEnd();
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

int main(int argc, char** argv)
{
	printf("Enter the value of x1 : ");
	scanf("%d",&x1);
	printf("Enter the value of y1 : ");
	scanf("%d",&yr);
	printf("Enter the value of x2 : ");
	scanf("%d",&x2);
	printf("Enter the value of y2 : ");
	scanf("%d",&y2);
	int side = 3;
	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (500, 500);
	glutInitWindowPosition (100,100);
	glutCreateWindow ("DDA Line Algo");
	init();
	while(side)
	{
	
	glutDisplayFunc(DDA);
	side--;
	}
	glutMainLoop();

	return 0;
}