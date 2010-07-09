#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <Glut/glut.h>
#include <stdio.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define WINDOW_X 100
#define WINDOW_Y 100

typedef GLfloat point[3]; 

void DrawGLScene(void);
void ChangeSize(GLsizei w, GLsizei h);
GLvoid pressZoomKey(int key, int x, int y);

int frame = 0;
float zDist= 0;

int main(int argc, char **argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
  glutInitWindowPosition(WINDOW_X, WINDOW_Y);
  glutCreateWindow("simple opengl example");

  glutDisplayFunc(DrawGLScene);
  // NEW
  glutReshapeFunc(ChangeSize);
	glutSpecialFunc(pressZoomKey);
	zDist = -10;
  glutMainLoop();
  return 0;
}

void DrawGLScene(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
		glNormal3d(0, 0, 1);
		
		
		glPushMatrix();
		glTranslatef(0.0, 0.0, zDist);
		glRotatef(30, 1.0, 1.0, 0.0);

		glutWireCube(1);
		glutWireCube(2);
		glutWireCube(4);
		glutWireCube(8);
		glutWireCube(16);
		glutWireCube(32);
		glutWireCube(64);
		glutWireCube(128);
		glutWireCube(256);
		glPopMatrix();
		glutSwapBuffers();
}

void ChangeSize(GLsizei w, GLsizei h)
{

  // Prevent a divide by zero
  if(h == 0)
    h = 1;

  glViewport(0, 0, w, h);

  // Reset coordinate system
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  gluPerspective(60.0f, w/h, 1.0, 1000.0);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}

void pressZoomKey(int key, int x, int y)
{
	switch(key)
	{
		case GLUT_KEY_UP : 
			zDist -= 1;
			break;
		case GLUT_KEY_DOWN : 
			zDist += 1;
			break;
	}
	glLoadIdentity();
		glutPostRedisplay();
}

