#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>

int a, b, r;

void plot(int x, int y)
{
    glBegin(GL_POINTS);
    glVertex2i(x+a, y+b);
    glEnd();
}

void myInit (void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glColor3f(0.0f, 0.0f, 0.0f);
    glPointSize(4.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}

void midPointCircleAlgo()
{
    int x = 0;
    int y = r;
    float d = 1.25 - r;
    plot(x, y);
    
    while (y > x)
    {
        if (d < 0)
        {
            x = x+1;
            y=y;
            d += 2*x+1;
        }
        else
        {
            x=x+1;
            y=y-1;
            d += 2*(x-y)+1;
        }
        plot(x, y);
        plot(x, -y);
        plot(-x, y);
        plot(-x, -y);
        plot(y, x);
        plot(-y, x);
        plot(y, -x);
        plot(-y, -x);
    }
    
}

void myDisplay(void)
{
    glClear (GL_COLOR_BUFFER_BIT);
    glColor3f (0.0, 0.0, 0.0);
    glPointSize(1.0);
    
    midPointCircleAlgo();
    
    glFlush ();
}

int main(int argc, char** argv)
{
    printf("enter the coordinates");
    scanf("%d%d",&a,&b);
    printf("enter the radius");
    scanf("%d",&r);
  
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (640, 480);
    glutInitWindowPosition (100, 150);
    glutCreateWindow ("MID POINT CIRCLE");
    glutDisplayFunc(myDisplay);
    myInit ();
    glutMainLoop();
}