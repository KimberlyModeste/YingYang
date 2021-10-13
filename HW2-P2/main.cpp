//CSC470 HW1
//Kimberly Modeste
#include <GL/glut.h>
#include <math.h>
#include <time.h> 
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
	c.set(0, 0);
	cvs.clearScreen();
	cvs.setWindow(-10.0, 10.0, -10.0, 10.0);
	cvs.setViewport(10, 460, 10, 460);
	drawCircle(c, 10);
	//ngon(30, 0.0, 0.0, 10.0, 2.0);
	glFlush();
}

void main(void)
{
	cvs.setBackgroundColor(1.0, 1.0, 1.0);
	cvs.setColor(0.0, 0.0, 0.0);
	glutDisplayFunc(display);
	glutMainLoop();
}