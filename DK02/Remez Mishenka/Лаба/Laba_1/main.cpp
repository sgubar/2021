#include <stdlib.h>
#include <glut.h>
#include <iostream>
#include <stdio.h>

#define _USE_MATH_DEFINES
#include <math.h>

#define delta_cord 0.05
#define delta_scale 0.1

#define Width 500
#define Height 500

void Draw_diagrama();
void Keyboard(unsigned char key, int x, int y);

float Znach_X(float t);
float Znach_Y(float t);

float scale = 1.0f, y_d = 0.0f, x_d = 0.0f;

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(Width, Height);
	glutInitWindowPosition(350, 150);
	glutCreateWindow("Test draw diagram from MRem");
	glutDisplayFunc(Draw_diagrama);
	
	glutKeyboardFunc(Keyboard);
	
	glutMainLoop();
}

void Keyboard(unsigned char key, int x, int y)
{
	
	switch (key)
	{
	case '-':
		if (scale - delta_scale > 0)
		scale -= delta_scale;
		glutIdleFunc(Draw_diagrama);
		break;
	case '=':
		scale += delta_scale;
		glutIdleFunc(Draw_diagrama);
		break;	
	case 'w':
		y_d += delta_cord;
		glutIdleFunc(Draw_diagrama);
		break;
	case 'a':
		x_d -= delta_cord;
		glutIdleFunc(Draw_diagrama);
		break;	
	case 's':
		y_d -= delta_cord;
		glutIdleFunc(Draw_diagrama);
		break;
	case 'd':
		x_d += delta_cord;
		glutIdleFunc(Draw_diagrama);
		break;	
	
	default:
		break;
	}
}

void Draw_diagrama()
{
	std::cout << scale << " " << x_d << " " << y_d << "\n";
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_LINE_STRIP);								// ��� ������
	glColor3f(0.4f, 0.7f, 1.0f);

	for (float t = 0; t <= 2 * M_PI; t += 0.01)
		glVertex2f((Znach_X(t) + x_d) * scale, (Znach_Y(t) + y_d) * scale);
	glEnd();

	glBegin(GL_LINES);									// ��� ���������

	glColor3f(0.8f, 0.8f, 0.8f);

	glVertex2f(-1, 0);
	glVertex2f(1, 0);

	glVertex2f(1, 0);
	glVertex2f(0.97, -0.02);
	glVertex2f(1, 0);
	glVertex2f(0.97, 0.02);

	glVertex2f(0, -1);
	glVertex2f(0, 1);

	glVertex2f(0, 1);
	glVertex2f(0.02, 0.97);
	glVertex2f(0, 1);
	glVertex2f(-0.02, 0.97);

	for (float i = 0; i < 1; i += 0.1 * scale)
	{
		glVertex2f(i, -0.01 * scale);
		glVertex2f(i, 0.01 * scale);
		glVertex2f(-0.01 * scale, i);
		glVertex2f(0.01 * scale, i);
	}
	for (float i = 0; i > -1; i -= 0.1 * scale)
	{
		glVertex2f(i, -0.01 * scale);
		glVertex2f(i, 0.01 * scale);
		glVertex2f(-0.01 * scale, i);
		glVertex2f(0.01 * scale, i);
	}

	glEnd();

	glFlush();
}

float Znach_X(float t)
{
	return cos(6 * t) * cos(t);
}

float Znach_Y(float t)
{
	return cos(6 * t) * sin(t);
}
