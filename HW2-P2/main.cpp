//CSC470 HW1
//Kimberly Modeste
#include <GL/glut.h>
#include <math.h>
#include <time.h> 
#include <vector>
#include <iostream>
#include "classes.h"

using namespace std;
char title[] = "yingyang";
Canvas cvs(480, 480, title);


void ngon(int n, float cx, float cy, float radius, float rotAngle) {
	if (n < 3) return;
	double angle = rotAngle * 3.14159265 / 180;
	double angleInc = 2 * 3.14159265 / n;
	cvs.moveTo(radius + cx, cy);

	for (int k = 0; k < n; k++)
	{
		angle += angleInc;
		cvs.lineTo(radius * cos(angle) + cx, radius * sin(angle) + cy);
	}
}

void drawCircle(Point2 center, float radius) {
	const int numverts = 50;
	ngon(numverts, center.getX(), center.getY(), radius, 0);
}

void display() {
	Point2 c;
	float theta;
	float r;
	
	cvs.clearScreen();
	cvs.setBackgroundColor(1.0, 1.0, 1.0);
	cvs.setColor(0.0, 0.0, 0.0);
	cvs.setWindow(-10.0, 10.0, -10.0, 10.0);
	cvs.setViewport(10, 460, 10, 460);
	
	//colors half of the top
	c.set(0, 0);
	r = 10;
	cvs.setColor(0.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	for (int i = 0; i < 180; i++)
	{
		theta = i * 3.14159265 / 180;
		glVertex2f(r * cos(theta) + c.getX(), r * sin(theta) + c.getY());
	}
	glEnd();
	
	//Colors the two arc circles
	c.set(-5, 0);
	r = 5;
	glBegin(GL_POLYGON);
	for (int i = 0; i < 360; i++)
	{
		theta = i * 3.14159265 / 180;
		glVertex2f(r * cos(theta) + c.getX(), r * sin(theta) + c.getY());
	}
	glEnd();
	c.set(5, 0);
	cvs.setColor(1.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
	for (int i = 0; i < 360; i++)
	{
		theta = i * 3.14159265 / 180;
		glVertex2f(r * cos(theta) + c.getX(), r * sin(theta) + c.getY());
	}
	glEnd();


	//little black circle
	r = 2;
	c.set(-5, 0);
	cvs.setColor(1.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
	for (int i = 0; i < 360; i++)
	{
		theta = i * 3.14159265 / 180;
		glVertex2f(r * cos(theta) + c.getX(), r * sin(theta) + c.getY());
	}
	glEnd();
	//little white circle
	c.set(5, 0);
	cvs.setColor(0.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	for (int i = 0; i < 360; i++) 
	{
		theta = i * 3.14159265 / 180;
		glVertex2f(r*cos(theta)+c.getX(), r*sin(theta)+c.getY());
	}
	glEnd();

	//outer circle
	c.set(0, 0);
	drawCircle(c, 10);

	glFlush();
}

void main(void)
{
	glutDisplayFunc(display);
	glutMainLoop();
}