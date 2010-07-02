#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <Glut/glut.h>

#define kWindowWidth 400
#define kWindowHeight 300

typedef GLfloat point[3]; 

point s[8] ={	{0,0,0},
							{0,0,0.5},
							{0,0.5,0},
							{0,0.5,0.5},
							{0.5,0,0},
							{0.5,0,0.5},
							{0.5,0.5,0},
							{0.5,0.5,0.5}};
GLvoid DrawGLScene(void);

void square(point a, point b, point c, point d);
void cube(void);
void axis(void);
int main(int argc, char **argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowSize(kWindowWidth, kWindowHeight);
  glutInitWindowPosition(100, 100);
  glutCreateWindow ("simple opengl example");
  glutDisplayFunc(DrawGLScene);
  glutMainLoop();
  return 0;
}

GLvoid DrawGLScene(void)
{
  glClear(GL_COLOR_BUFFER_BIT); 
  glColor3f(1.0,1.0,1.0); 
  glLoadIdentity(); 
	glRotated(45,1,1,1);
	cube();
  glutSwapBuffers();
}
void cube(void)
{
	square(s[0],s[1],s[3],s[2]);
	square(s[0],s[4],s[6],s[2]);
	square(s[0],s[4],s[5],s[1]);
	square(s[7],s[6],s[4],s[5]);
	square(s[7],s[3],s[1],s[5]);
//	square(s[7],s[3],s[5],s[1]);
}

void square(point a, point b, point c, point d)
{
	glBegin(GL_LINE_LOOP);
  glVertex3fv(a); 
  glVertex3fv(b); 
  glVertex3fv(c);
	glVertex3fv(d); 
  glEnd();
}

void axis(void)
{
	point a[4] ={	{0,0,0},
								{2,0,0},
								{0,2,0},
								{0,0,2}};
	glBegin(GL_LINE_LOOP);
  glVertex3fv(a[0]); 
  glVertex3fv(a[1]); 
  glEnd();
	glBegin(GL_LINE_LOOP);
  glVertex3fv(a[0]); 
  glVertex3fv(a[2]); 
  glEnd();
	glBegin(GL_LINE_LOOP);
  glVertex3fv(a[0]); 
  glVertex3fv(a[3]); 
  glEnd();
}
