#include <GL/glut.h> 
#define _USE_MATH_DEFINES
#include <math.h>
double zoom = 1;
double lr, ud;
void ZoomKeys(int key, int x, int y) {
	switch (key) {
	case GLUT_KEY_PAGE_DOWN:
		zoom = zoom + 0.1;
		break;
	case GLUT_KEY_PAGE_UP:
		zoom = zoom - 0.1;
		break;
	case GLUT_KEY_LEFT:
		lr = lr - 0.1;
		break;
	case GLUT_KEY_RIGHT:
		lr = lr + 0.1;
		break;
	case GLUT_KEY_UP:
		ud = ud + 0.1;
		break;
	case GLUT_KEY_DOWN:
		ud = ud - 0.1;
		break;
	}
}
void Graf() {
	int a = 1;
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f); // Фон чорний 

	// Малювання декількох відрізків(графік функції)
	glBegin(GL_LINE_STRIP); // Кожна пара вершини задає відрізок
	glColor3f(1.0f, 0.0f, 1.0f); // Рожевий колір
	for (double t = -M_PI; t <= M_PI; t += 0.01) {
		float y = ((a * sqrt(2) * cos(t) * sin(t)) / (1 + sin(t) * sin(t)) / M_PI);
		float x = ((a * sqrt(2) * cos(t)) / (1 + sin(t) * sin(t)) / M_PI);
		glVertex2f(x / zoom + lr, y / zoom + ud);
	}
	glEnd();
}
void LineX() {
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f); // Фон чорний 
	glBegin(GL_LINES); // Кожна пара вершини задає відрізок
	glColor3f(0.0f, 1.0f, 0.0f); // зелений колір
	glVertex2f(-1, 0);
	glVertex2f(1, 0);
	glEnd();
}
void LineXY(double x) {
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f); // Фон чорний 
	glBegin(GL_LINES); // Кожна пара вершини задає відрізок
	glColor3f(0.0f, 1.0f, 0.0f); // Зелений колір
	glVertex2f(x, 0.025);
	glVertex2f(x, -0.025);
	glEnd();
}
void LineY() {
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f); // Фон чорний 
	glBegin(GL_LINES); // Кожна пара вершини задає відрізок
	glColor3f(0.0f, 1.0f, 0.0f); // Зелений колір
	glVertex2f(0, -1);
	glVertex2f(0, 1);
	glEnd();
}
void LineYX(double y) {
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f); // Фон чорний
	glBegin(GL_LINES); // Кожна пара вершини задає відрізок
	glColor3f(0.0f, 1.0f, 0.0f); // Зелений колір
	glVertex2f(0.025, y);
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
	glutInit(&argc, argv); // Ініціалізація GLUT
	glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE);
	glutInitWindowPosition(100, 100); // Положення вікна
	glutInitWindowSize(800, 800);//ширина та висота вікна
	glutCreateWindow("Grafik"); // вікно із заданим ім'ям
	glutSpecialFunc(ZoomKeys);
	glutDisplayFunc(display);// Реєстрація функції зворотного
	glutTimerFunc(0, Timer, 0); // Запуск та реєстрація обробки таймера
	glFlush();// виклик для малювання вікна
	glutMainLoop(); // Вхід у цикл обробки подій GLUT
	return 0;
}
