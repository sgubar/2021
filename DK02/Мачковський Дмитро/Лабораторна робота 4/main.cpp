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

void Graph();
void Keyboard(unsigned char key, int x, int y);

float Sklad_X(float t);
float Sklad_Y(float t);

float scale = 1.0f, y_c = 0.0f, x_c = 0.0f;

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(Width, Height);
	glutInitWindowPosition(450, 150);
	glutCreateWindow("Laba 4");
	glutDisplayFunc(Graph);

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
		glutIdleFunc(Graph);
		break;
	case '=':
		scale += delta_scale;
		glutIdleFunc(Graph);
		break;
	case 'w':
		y_c += delta_cord;
		glutIdleFunc(Graph);
		break;
	case 'a':
		x_c -= delta_cord;
		glutIdleFunc(Graph);
		break;
	case 's':
		y_c -= delta_cord;
		glutIdleFunc(Graph);
		break;
	case 'd':
		x_c += delta_cord;
		glutIdleFunc(Graph);
		break;

	default:
		break;
	}
}

void Graph()
{
	std::cout << scale << " " << x_c << " " << y_c << "\n";
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_LINE_STRIP);								
	glColor3f(1.0f, 1.0f, 0.0f);

	for (float t = 0; t <= 4 * M_PI; t += 0.01)
		glVertex2f((Sklad_X(t) + x_c) * scale, (Sklad_Y(t) + y_c) * scale);
	glEnd();

	glBegin(GL_LINES);									

	glColor3f(1.0f, 1.0f, 1.0f);

	glVertex2f(-1, (0 + y_c) * scale);
	glVertex2f(1, (0 + y_c) * scale);

	glVertex2f(1, (0 + y_c) * scale);
	glVertex2f(0.9, (-0.08 + y_c) * scale);
	glVertex2f(1, (0 + y_c) * scale);
	glVertex2f(0.9, (0.08 + y_c) * scale);

	glVertex2f((0 + x_c) * scale, -1);
	glVertex2f((0 + x_c) * scale, 1);

	glVertex2f((0 + x_c) * scale, 1);
	glVertex2f((0.08 + x_c) * scale, 0.9);
	glVertex2f((0 + x_c) * scale, 1);
	glVertex2f((-0.08 + x_c) * scale, 0.9);

	for (float i = 0; i < 1; i += 0.1 * scale)
	{
		glVertex2f(i, (-0.04 + y_c) * scale);
		glVertex2f(i, (0.04 + y_c) * scale);
		glVertex2f((-0.04 + x_c) * scale, i);
		glVertex2f((0.04 + x_c) * scale, i);
	}
	for (float i = 0; i > -1; i -= 0.1 * scale)
	{
		glVertex2f(i, (-0.04 + y_c) * scale);
		glVertex2f(i, (0.04 + y_c) * scale);
		glVertex2f((-0.04 + x_c) * scale, i);
		glVertex2f((0.04 + x_c) * scale, i);
	}

	glScalef(scale, scale, 0);

	glEnd();

	glFlush();
}

float Sklad_X(float t)
{
	return (2 + cos((5 * t) / 2) * cos(t));
}

float Sklad_Y(float t)
{
	return (2 + cos((5 * t) / 2) * sin(t));
}
