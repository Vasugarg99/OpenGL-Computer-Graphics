#include<GL/glut.h>
#include<GL/gl.h>
#include<stdio.h>
float x1,x2,x3,x4,y1,y2,y3,y4;
void draw_pixel(int x,int y)
{
    glColor3f(0.0,0.0,0.0);//set the current color
    glPointSize(1.0);//specify the diameter of rasterized points
    glBegin(GL_POINTS);
    glVertex2i(x,y);
    glEnd();
}
void edge(float x1,float y1,float x2,float y2,int *l,int *r)
{  float temp,x,mx;
    int i;
    if(y1>y2)
    {
        temp=x1,x1=x2,x2=temp;
        temp=y1,y1=y2,y2=temp;
    }
    if(y1==y2)
        mx=x2-x1;
   else
        mx=(x2-x1)/(y2-y1);
    x=x1;
    for(i=int(y1);i<=(int)y2;i++)
    {
        if(x<(float)l[i]) l[i]=(int)x;
        if(x>(float)r[i]) r[i]=(int)x;
        x+=mx;
    }
}
void scanfill(float x1,float y1,float x2,float y2,float x3,float y3,float x4,float y4)
{
    int l[500],r[500],i,j;
    for(i=0;i<500;i++)
        l[i]=500,r[i]=0;
    edge(x1,y1,x2,y2,l,r);
    edge(x2,y2,x3,y3,l,r);
    edge(x3,y3,x4,y4,l,r);
    edge(x4,y4,x1,y1,l,r);
    for(j=0;j<500;j++)
    {
        if(l[j]<=r[j])
            for(i=l[j];i<r[j];i++)
                draw_pixel(i,j);
    }
}void display()
{
    x1=200.0;y1=250.0;x2=200.0;y2=250.0;
    x3=250.0;y3=350.0;x4=350.0;y4=300.0;
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0,0.0,1.0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(x1,y1);
    glVertex2f(x2,y2);
    glVertex2f(x3,y3);
    glVertex2f(x4,y4);
    glEnd();
  scanfill(x1,y1,x2,y2,x3,y3,x4,y4);
glFlush();
}void init()
{
    glClearColor(1.0,1.0,1.0,1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0,400.0,0.0,400.0);
}
int main(int argc,char **argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(500,500);
    glutCreateWindow("Scanline (Vasu)");
  glutDisplayFunc(display);
    init();
    glutMainLoop();
    return(0);
}
