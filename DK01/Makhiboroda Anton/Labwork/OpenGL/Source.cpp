#include <GL/glut.h> 
#define _USE_MATH_DEFINES
#include <math.h>
double zoom = 1;
double LeftRigth, UpDown;
void keyboard(unsigned char key, int x, int y)
{
	switch (key) {
	case 27: // Esc
		exit(0);
		break;
	}
}
void ZoomKeys(int key, int x, int y) {
	switch (key) {
	case GLUT_KEY_PAGE_DOWN:
		zoom = zoom + 0.1;
		break;
	case GLUT_KEY_PAGE_UP:
		zoom = zoom - 0.1;
		break;
	case GLUT_KEY_LEFT:
		LeftRigth = LeftRigth - 0.1;
		break;
	case GLUT_KEY_RIGHT:
		LeftRigth = LeftRigth + 0.1;
		break;
	case GLUT_KEY_UP:
		UpDown = UpDown + 0.1;
		break;
	case GLUT_KEY_DOWN:
		UpDown = UpDown - 0.1;
		break;  
	}
}
void Graf() {
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f); // ��� ������ �� ��������
	
	// ��������� ��� ������, �� � �������� �������
	glBegin(GL_LINE_STRIP); // ����� ���� ������� ���� ������
	glColor3f(1.0f, 1.0f, 0.0f); // ������ ����
	for (double t = 0; t <= M_PI; t += 0.01) {
		float y = (sin(3 * t) * cos(t) / M_PI) ;
		float x = (sin(3 * t) * sin(t) / M_PI) ;
		glVertex2f(x/zoom + LeftRigth, y/zoom + UpDown);
	}
	glEnd();
}
void LineX() {
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f); // ��� ������ �� ��������
	glBegin(GL_LINES); // ����� ���� ������� ���� ������
	glColor3f(1.0f, 0.0f, 0.0f); // ������ ����
		glVertex2f(-1, 0);
		glVertex2f(1, 0);
	glEnd();
}
void LineXY(double x ) {
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f); // ��� ������ �� ��������
	glBegin(GL_LINES); // ����� ���� ������� ���� ������
	glColor3f(1.0f, 0.0f, 0.0f); // ������ ����
	glVertex2f(x, 0.025);
	glVertex2f(x,-0.025);
	glEnd();
}
void LineY() {
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f); // ��� ������ �� ��������
	glBegin(GL_LINES); // ����� ���� ������� ���� ������
	glColor3f(1.0f, 0.0f, 0.0f); // ������ ����
	glVertex2f(0,-1 );
	glVertex2f(0,1 );
	glEnd();
}
void LineYX(double y) {
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f); // ��� ������ �� ��������
	glBegin(GL_LINES); // ����� ���� ������� ���� ������
	glColor3f(1.0f, 0.0f, 0.0f); // ������ ����
	glVertex2f( 0.025, y);
	glVertex2f(-0.025, y);
	glEnd();
}
void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
	Graf();
	LineX();
	for (double x = -1; x <= 1; x += 0.1) {
		LineXY(x);
	}
	LineY();
	for (double y = -1; y <= 1; y += 0.1) {
		LineYX(y);
	}
	glutSwapBuffers();
}
void Timer(int value) {
	glutPostRedisplay(); 
	glutTimerFunc(30, Timer, 0); 
}
int main(int argc, char* argv[])
{
	glutInit(&argc, argv); // ����������� GLUT
	glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE);
	glutInitWindowPosition(100, 100); // ��������� ����
	glutInitWindowSize(800, 800);//����� �� ������ ����
	glutCreateWindow("Grafic by Anton"); // ��������� ���� �� ������� ��'��
	glutSpecialFunc(ZoomKeys);
	glutDisplayFunc(display);// ��������� ������� ����������
	glutKeyboardFunc(keyboard); // ��������� ��������� ���� ���������
	glutTimerFunc(0, Timer, 0); // ������ �� ��������� ������� �������
	glFlush();// ������� ��� ��������� ����
	glutMainLoop(); // ���� � ���� ������� ���� GLUT
	return 0;
}