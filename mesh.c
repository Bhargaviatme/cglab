#include<stdlib.h>
#include<GL/glut.h>
#define dx 10
#define dy 10
void display()
{
GLint i,j;
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(1.0,1.0,0.0);
for(i=10;i<300;i+=dx)
for(j=10;j<300;j+=dy)
{
glBegin(GL_LINE_LOOP);
glVertex2i(i,j);
glVertex2i(i+dx,j);
glVertex2i(i+dx,j+dy);
glVertex2i(i,j+dy);
glEnd();
}
glFlush();
}

int main(int argc,char **argv)
{
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
glutInitWindowPosition(50,20);

glutInitWindowSize(500,500);
glutCreateWindow("rectangular mesh");
glClearColor(0.0,1.0,0.0,0.0);
glMatrixMode(GL_PROJECTION);
gluOrtho2D(0.0,500.0,0.0,500.0);
glutDisplayFunc(display);
glutMainLoop();
return 0;
}
