#include<GL/glut.h>
#include<stdio.h>
GLfloat Vertices[8][3]={{-1,-1,-1},{1,-1,-1},{1,1,-1},{-1,1,-1},{-1,-1,1},{1,-1,1},{1,1,1},{-1,1,1}};
GLfloat Colors[8][3]={{0,0,1},{0,1,0},{0,1,1},{1,0,0},{1,0,1},{1,1,0},{1,1,1},{1,0.5,0}};
static GLfloat theta[]={0,0,0};
static GLint axis=2;
static GLdouble viewer[]={0,0,5};

void Polygon(int a,int b,int c,int d)
{
glBegin(GL_POLYGON);
glColor3fv(Colors[a]);
glVertex3fv(Vertices[a]);
glColor3fv(Colors[b]);
glVertex3fv(Vertices[b]);
glColor3fv(Colors[c]);
glVertex3fv(Vertices[c]);
glColor3fv(Colors[d]);
glVertex3fv(Vertices[d]);
glEnd();
}
void colorcube()
{
Polygon(0,3,2,1);
Polygon(4,5,6,7);
Polygon(0,4,7,3);
Polygon(1,5,6,2);
Polygon(0,1,5,4);
Polygon(3,2,6,7);
}
void display()
{
glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
glLoadIdentity();
gluLookAt(viewer[0],viewer[1],viewer[2],0,0,0,0,1,0);

glRotatef(theta[0],1,0,0);
glRotatef(theta[1],0,1,0);
glRotatef(theta[2],0,0,1);
colorcube();
glFlush();
glutSwapBuffers();
}


void MyMouse(int btn,int state,int x,int y)
{
if(btn==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
axis=0;
if(btn==GLUT_MIDDLE_BUTTON && state==GLUT_DOWN)
axis=1;
if(btn==GLUT_RIGHT_BUTTON && state==GLUT_DOWN)
axis=2;
theta[axis]+=2.0;
if(theta[axis]>360.0) theta[axis]-=360.0;
display();
}

void keys(unsigned char key,int x,int y)
{
if(key=='x') viewer[0]-=1;
if(key=='X') viewer[0]+=1;
if(key=='y') viewer[1]-=1;
if(key=='Y') viewer[1]+=1;
if(key=='z') viewer[2]-=1;
if(key=='Z') viewer[2]+=1;
display();
}

void MyReshape(int w,int h)
{
glViewport(0,0,w,h);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
if(w<=h)
glFrustum(-2,2,-2*(GLfloat)h/(GLfloat)w,2*(GLfloat)h/(GLfloat)w,2,20);
else
glFrustum(-2*(GLfloat)w/(GLfloat)h,2*(GLfloat)w/(GLfloat)h,-2,2,2,20);
glMatrixMode(GL_MODELVIEW);
}
int main(int argc,char **argv)
{
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
glutCreateWindow("CUBE");
glutReshapeFunc(MyReshape);
glutDisplayFunc(display);
glutKeyboardFunc(keys);
glutMouseFunc(MyMouse);
glEnable(GL_DEPTH_TEST);
glutMainLoop();                                               
}
