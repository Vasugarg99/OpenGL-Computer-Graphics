#include <GL/glut.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int h,k;
float a,b;
void display(void) 
{
   double I,J;
    int i,j;
    glClear (GL_COLOR_BUFFER_BIT);
    glColor3f (1.0, 0.0, 0.0);
    glBegin(GL_POINTS);
    glVertex2s(h,k);
    for( i=0 ; i<=a ; i+=1)     {
        J=sqrt(1 - (i*i)/(a*a))*b;
        j=(int)(J);
		glVertex2s(h+i,k+j);
        glVertex2s(h-i,k+j);
        glVertex2s(h-i,k-j);
        glVertex2s(h+i,k-j);       }
    	glColor3f (1.0, 1.0, 1.0);
    for(int i=-100 ; i<=100 ; i++)
    {     glVertex2s(i,0);
          glVertex2s(0,i);        }
    for(int i=-2; i<=2 ; i++)
    {     glVertex2s(95+i,4+i);
          glVertex2s(95-i,4+i);     }
    for(int i=0; i<=2 ; i++)
    {     glVertex2s(4+i,95+i);
          glVertex2s(4-i,95+i);
          glVertex2s(4,95-i);	  }
    glEnd();
    glFlush();
}
void init(void)
{
    glClearColor (1.0, 1.0, 1.5, 0.0);
    glOrtho(-100.0, 100.0, -100.0, 100.0, -1.0, 1.0);
}

int main(int argc, char** argv)
{
    printf("Enter the center of ellipse:\n");
    scanf("%d %d",&h,&k);
    printf("Enter the parameters a & b:\n");
    scanf("%f %f",&a,&b);
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (500, 500);
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("Ellipse : mid-point ");
    init ();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}