
/*********
   CTIS164 - Template Source Program
----------
STUDENT :ASLI KUTERDEM
SECTION :02
HOMEWORK:HOMEWORK-1
----------
PROBLEMS:
----------
ADDITIONAL FEATURES: onClick function to close curtain.
fishes moving.
*********/

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdarg.h>

#define WINDOW_WIDTH  600
#define WINDOW_HEIGHT 600

#define TIMER_PERIOD  17
#define TIMER_ON         1

#define D2R 0.0174532


bool up = false, down = false, right = false, left = false;
int  winWidth, winHeight; 
bool activeTimer = true;
int xC = 0, yC = 0;
bool click = true;


void circle(int x, int y, int r)
{
#define PI 3.1415
	float angle;
	glBegin(GL_POLYGON);
	for (int i = 0; i < 100; i++)
	{
		angle = 2 * PI*i / 100;
		glVertex2f(x + r * cos(angle), y + r * sin(angle));
	}
	glEnd();
}

void circle_wire(int x, int y, int r)
{
#define PI 3.1415
	float angle;

	glBegin(GL_LINE_LOOP);
	for (int i = 0; i < 100; i++)
	{
		angle = 2 * PI*i / 100;
		glVertex2f(x + r * cos(angle), y + r * sin(angle));
	}
	glEnd();
}

void print(int x, int y, const char *string, void *font)
{
	int len, i;

	glRasterPos2f(x, y);
	len = (int)strlen(string);
	for (i = 0; i < len; i++)
	{
		glutBitmapCharacter(font, string[i]);
	}
}


void vprint(int x, int y, void *font, const char *string, ...)
{
	va_list ap;
	va_start(ap, string);
	char str[1024];
	vsprintf_s(str, string, ap);
	va_end(ap);

	int len, i;
	glRasterPos2f(x, y);
	len = (int)strlen(str);
	for (i = 0; i < len; i++)
	{
		glutBitmapCharacter(font, str[i]);
	}
}
void vprint2(int x, int y, float size, const char *string, ...) {
	va_list ap;
	va_start(ap, string);
	char str[1024];
	vsprintf_s(str, string, ap);
	va_end(ap);
	glPushMatrix();
	glTranslatef(x, y, 0);
	glScalef(size, size, 1);

	int len, i;
	len = (int)strlen(str);
	for (i = 0; i < len; i++)
	{
		glutStrokeCharacter(GLUT_STROKE_ROMAN, str[i]);
	}
	glPopMatrix();
}



void submarine() {
	
	glColor3f(0.5, 0.5, 0.5);
	circle(-140 + xC, -140, 40);

	glColor3f(0.5, 0.5, 0.5);
	glBegin(GL_POLYGON);
	glVertex2f(-100+xC, -180);
	glVertex2f(-140 + xC, -180);
	glVertex2f(-140 + xC, -100);
	glVertex2f(-100 + xC, -100);
	glEnd();

	glColor3f(0.5, 0.5, 0.5);
	circle(-100 + xC, -140, 40);



	glColor3f(0.5, 0.5, 0.5);
	glBegin(GL_TRIANGLES);
	glVertex2f(-200 + xC, -120);
	glVertex2f(-160 + xC, -135);
	glVertex2f(-200 + xC, -150);
	glEnd();

	glColor3f(0, 1, 1);
	circle(-130 + xC, -140, 10);
	circle(-100 + xC, -140, 10);
	circle(-160 + xC, -140, 10);

	glColor3f(0.5, 0.5, 0.5);
	glBegin(GL_POLYGON);
	glVertex2f(-130 + xC, -100);
	glVertex2f(-100 + xC, -100);
	glVertex2f(-100 + xC, -80);
	glVertex2f(-130 + xC, -80);
	glEnd();

	glColor3f(0.5, 0.5, 0.5);
	glBegin(GL_POLYGON);
	glVertex2f(-120 + xC, -80);
	glVertex2f(-120 + xC, -60);
	glVertex2f(-110 + xC, -60);
	glVertex2f(-110 + xC, -80);
	glEnd();

	glColor3f(0.5, 0.5, 0.5);
	glBegin(GL_POLYGON);
	glVertex2f(-90 + xC, -60);
	glVertex2f(-90 + xC, -50);
	glVertex2f(-110 + xC, -50);
	glVertex2f(-110 + xC, -60);
	glEnd();

	glColor3f(0.5, 0.5, 0.5);
	glBegin(GL_TRIANGLES);
	glVertex2f(-110 + xC, -60);
	glVertex2f(-120 + xC, -60);
	glVertex2f(-110 + xC, -50);
	glEnd();




}
void star() {
	glColor3f(1.000, 0.549, 0.000);
	glBegin(GL_POLYGON);
	glVertex2f(155, -170);
	glVertex2f(150, -160);
	glVertex2f(145, -170);
	glVertex2f(135,-175);
	glVertex2f(145, -180);
	glVertex2f(150, -190);
	glVertex2f(155, -180);
	glVertex2f(165, -175);
	glEnd();

	glColor3f(0.824, 0.412, 0.118);
	glBegin(GL_POLYGON);
	glVertex2f(125, -145);
	glVertex2f(120, -135);
	glVertex2f(115, -145);
	glVertex2f(105, -150);
	glVertex2f(115, -155);
	glVertex2f(120, -165);
	glVertex2f(125, -155);
	glVertex2f(135, -150);
	glEnd();

	glColor3f(1.000, 0.000, 1.000);
	glBegin(GL_POLYGON);
	glVertex2f(115, -175);
	glVertex2f(110, -165);
	glVertex2f(105, -175);
	glVertex2f(95, -180);
	glVertex2f(105, -185);
	glVertex2f(110, -195);
	glVertex2f(115, -185);
	glVertex2f(125, -180);
		glEnd();

}
void fish1() {
	glColor3f(1.000, 0.647, 0.000);
	glBegin(GL_TRIANGLES);
	glVertex2f(-100+yC, 70);
	glVertex2f(-120 + yC, 85);
	glVertex2f(-100 + yC, 100);
	glEnd();
	glColor3f(1.000, 0.647, 0.000);
	glBegin(GL_TRIANGLES);
	glVertex2f(-120 + yC, 85);
	glVertex2f(-135 + yC, 80);
	glVertex2f(-135 + yC, 90);
	glEnd();

	glColor3f(0, 0, 0);
	circle(-105 + yC, 90, 2);


	glColor3f(0.698, 0.133, 0.133);
	glBegin(GL_TRIANGLES);
	glVertex2f(100 + yC, 70);
	glVertex2f(120 + yC, 85);
	glVertex2f(100 + yC, 100);
	glEnd();
	glColor3f(0.698, 0.133, 0.133);
	glBegin(GL_TRIANGLES);
	glVertex2f(120 + yC, 85);
	glVertex2f(135 + yC, 80);
	glVertex2f(135 + yC, 90);
	glEnd();

	glColor3f(0, 0, 0);
	circle(105 + yC, 90, 2);

	glColor3f(0.847, 0.749, 0.847);
	glBegin(GL_TRIANGLES);
	glVertex2f(-100 + yC, 20);
	glVertex2f(-120 + yC, 35);
	glVertex2f(-100 + yC, 50);
	glEnd();
	glColor3f(0.847, 0.749, 0.847);
	glBegin(GL_TRIANGLES);
	glVertex2f(-120 + yC, 35);
	glVertex2f(-135 + yC, 30);
	glVertex2f(-135 + yC, 40);
	glEnd();

	glColor3f(0, 0, 0);
	circle(-105 + yC, 40, 2);

	glColor3f(0.2, 1, 0.1);
	glBegin(GL_TRIANGLES);
	glVertex2f(-50 + yC, -10);
	glVertex2f(-70 + yC, 5);
	glVertex2f(-50 + yC, 20);
	glEnd();
	glColor3f(0.2, 1, 0.1);
	glBegin(GL_TRIANGLES);
	glVertex2f(-70 + yC, 5);
	glVertex2f(-85 + yC, 0);
	glVertex2f(-85 + yC, 10);
	glEnd();

	glColor3f(0, 0, 0);
	circle(-55 + yC, 10, 2);

	glColor3f(0.541, 0.169, 0.886);
	glBegin(GL_TRIANGLES);
	glVertex2f(0 + yC, 5);
	glVertex2f(-20 + yC, 20);
	glVertex2f(-0 + yC, 35);
	glEnd();
	glColor3f(0.541, 0.169, 0.886);
	glBegin(GL_TRIANGLES);
	glVertex2f(-20 + yC, 20);
	glVertex2f(-35 + yC, 15);
	glVertex2f(-35 + yC, 25);
	glEnd();

	glColor3f(0, 0, 0);
	circle(-5 + yC, 25, 2);

	glColor3f(0.722, 0.525, 0.043);
	glBegin(GL_TRIANGLES);
	glVertex2f(50 + yC, -5);
	glVertex2f(30 + yC, -20);
	glVertex2f(50 + yC, -35);
	glEnd();
	glColor3f(0.722, 0.525, 0.043);
	glBegin(GL_TRIANGLES);
	glVertex2f(30 + yC, -20);
	glVertex2f(15 + yC, -15);
	glVertex2f(15 + yC, -25);
	glEnd();

	glColor3f(0, 0, 0);
	circle(45 + yC, -15, 2);

}

//handle of the window
void window() {
	glColor3f(0.5, 0.35, 0.35);
	glBegin(GL_POLYGON);
	glVertex2f(200, -200);
	glVertex2f(200, 200);
	glVertex2f(300, 300);
	glVertex2f(300, -300);
	glEnd();
}



void display() {

	glClearColor(0, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT);

	

	glColor3f(0.5, 0.5, 0.5);
	glBegin(GL_POLYGON);
	glVertex2f(600, 600);
	glVertex2f(600, -600);
	glVertex2f(-600, -600);
	glVertex2f(-600, 600);
	glEnd();

	//wallpaper
	glColor3f(0, 0, 0);
	glBegin(GL_LINES);


	glVertex2f(-300, -300);
	glVertex2f(-300, 300);
	glVertex2f(-250, -300);
	glVertex2f(-250, 300);
	glVertex2f(-200, 300);
	glVertex2f(-200, -300);
	glVertex2f(-150, 300);
	glVertex2f(-150, -300);
	glVertex2f(-100, 300);
	glVertex2f(-100, -300);
	glVertex2f(-50, -300);
	glVertex2f(-50, 300);
	glVertex2f(0, 300);
	glVertex2f(0, -300);
	glVertex2f(50, -300);
	glVertex2f(50, 300);
	glVertex2f(100, 300);
	glVertex2f(100, -300);
	glVertex2f(150, 300);
	glVertex2f(150, -300);
	glVertex2f(200, -300);
	glVertex2f(200, 300);
	glVertex2f(250, -300);
	glVertex2f(250, 300);

	glVertex2f(300, 300);
	glVertex2f(-300, 300);
	glVertex2f(-300, 200);
	glVertex2f(300, 200);
	glVertex2f(300, 100);
	glVertex2f(-300, 100);
	glVertex2f(300, 0);
	glVertex2f(-300, 0);
	glVertex2f(-300, -100);
	glVertex2f(300, -100);
	glVertex2f(300, -200);
	glVertex2f(-300, -200);
	glEnd();

	//window out
	glColor3f(0.5, 0.35, 0.35);
	glBegin(GL_POLYGON);
	glVertex2f(-260, 260);
	glVertex2f(-260, -260);
	glVertex2f(260, -260);
	glVertex2f(260, 260);

	glEnd();

// in window
	glColor3f(0, 0, 1);
	glBegin(GL_POLYGON);
	glVertex2f(200, 200);
	glVertex2f(200, -200);
	glVertex2f(-200, -200);
	glVertex2f(-200, 200);
	glEnd();

	glColor3f(1.000, 0.937, 0.835);
	glBegin(GL_POLYGON);
	glVertex2f(-200, -200);
	glVertex2f(200, -200);
	glVertex2f(200, -135);
	glVertex2f(-200, -135);
	glEnd();

	
	glColor3f(1.000, 0.894, 0.710);
	glBegin(GL_TRIANGLES);
	glVertex2f(-200, -140);
	glVertex2f(-180, -120);
	glVertex2f(-160, -140);
	glVertex2f(-140, -140);
	glVertex2f(-120, -120);
	glVertex2f(-100, -140);
	glVertex2f(-50, -140);
	glVertex2f(-30, -120);
	glVertex2f(-10, -140);
	glVertex2f(50, -140);
	glVertex2f(70, -120);
	glVertex2f(90, -140);
	glVertex2f(100, -140);
	glVertex2f(120, -120);
	glVertex2f(140, -140);
	glVertex2f(60, -140);
	glVertex2f(80, -120);
	glVertex2f(100, -140);
	glVertex2f(-130, -140);
	glVertex2f(-110, -120);
	glVertex2f(-90, -140);
	glVertex2f(-150, -140);
	glVertex2f(-160, -120);
	glVertex2f(-170, -140);
	glVertex2f(-100, -140);
	glVertex2f(-80, -120);
	glVertex2f(-50, -140);
	glVertex2f(0, -140);
	glVertex2f(35, -120);
	glVertex2f(70, -140);
	glVertex2f(30, -140);
	glVertex2f(55, -120);
	glVertex2f(80, -140);
	glVertex2f(150, -140);
	glVertex2f(160, -120);
	glVertex2f(170, -140);
	glEnd();


	glColor3f(0.604, 0.804, 0.196);
	glBegin(GL_POLYGON);
	glVertex2f(-200, -200);
	glVertex2f(-200, -105);
	glVertex2f(-191, -105);
	glVertex2f(-191, -200);
	glEnd();
	glColor3f(0.180, 0.545, 0.341);
	glBegin(GL_POLYGON);
	glVertex2f(-175, -200);
	glVertex2f(-175, -85);
	glVertex2f(-166, -85);
	glVertex2f(-166, -200);
	glEnd();

	glColor3f(0.000, 0.980, 0.604);
	glBegin(GL_POLYGON);
	glVertex2f(200, -200);
	glVertex2f(200, -30);
	glVertex2f(191, -30);
	glVertex2f(191, -200);
	glEnd();
	glColor3f(0.000, 0.502, 0.000);
	glBegin(GL_POLYGON);
	glVertex2f(175, -200);
	glVertex2f(175, -85);
	glVertex2f(166, -85);
	glVertex2f(166, -200);
	glEnd();

	glColor3f(0.294, 0.000, 0.510);
	circle(0, -200, 30);

	
	//coral reefs
	glColor3f(0.000, 1.000, 1.000);
	circle_wire(0, -200, 30);
	circle_wire(0, -200, 24);
	circle_wire(0, -200, 18);
	glColor3f(0.678, 1.000, 0.184);
	circle(20, -200, 23);

	glColor3f(1.000, 0.271, 0.000);
	circle_wire(20, -200, 23);
	circle_wire(20, -200, 13);

	glColor3f(0.5, 0.35, 0.35);
	glBegin(GL_POLYGON);
	glVertex2f(-100, -260);
	glVertex2f(100, -260);
	glVertex2f(100, -200);
	glVertex2f(-100, -200);
	glEnd();

	

	







	star();
	submarine();
	fish1();
	window();
	

	glColor3f(0.5, 0.35, 0.35);
	if (click == false)
		glRectf(-200, -200, 200, 200);

	glColor3f(1, 1, 1);
	vprint(-100, -235, GLUT_BITMAP_HELVETICA_18, "Submarine Down the Sea");
	vprint(-90, 235, GLUT_BITMAP_HELVETICA_18, "ASLI KUTERDEM");

	glutSwapBuffers();
}


void onKeyDown(unsigned char key, int x, int y)
{
	
	if (key == 27)
		exit(0);

	if (key == ' ')
		activeTimer = !activeTimer;

	
	glutPostRedisplay();
}

void onKeyUp(unsigned char key, int x, int y)
{
	// exit when ESC is pressed.
	if (key == 27)
		exit(0);



	// to refresh the window it calls display() function
	glutPostRedisplay();
}


void onSpecialKeyDown(int key, int x, int y)
{
	// Write your codes here.
	switch (key) {
	case GLUT_KEY_UP:
		up = true;
		break;
	case GLUT_KEY_DOWN:
		down = true;
		break;
	case GLUT_KEY_LEFT:
		left = true;
		break;
	case GLUT_KEY_RIGHT:
		right = true;
		break;
	}

	
	glutPostRedisplay();
}

//
// Special Key like GLUT_KEY_F1, F2, F3,...
// Arrow Keys, GLUT_KEY_UP, GLUT_KEY_DOWN, GLUT_KEY_RIGHT, GLUT_KEY_RIGHT
//
void onSpecialKeyUp(int key, int x, int y)
{
	// Write your codes here.
	switch (key) {
	case GLUT_KEY_UP:
		up = false;
		break;
	case GLUT_KEY_DOWN:
		down = false;
		break;
	case GLUT_KEY_LEFT:
		left = false;
		break;
	case GLUT_KEY_RIGHT:
		right = false;
		break;
	}

	
	glutPostRedisplay();
}

//
// When a click occurs in the window,
// It provides which button
// buttons : GLUT_LEFT_BUTTON , GLUT_RIGHT_BUTTON
// states  : GLUT_UP , GLUT_DOWN
// x, y is the coordinate of the point that mouse clicked.
//
// GLUT to OpenGL coordinate conversion:
//   x2 = x1 - winWidth / 2
//   y2 = winHeight / 2 - y1
void onClick(int button, int stat, int x, int y)
{
	// Write your codes here.
	int x2, y2;
	x2 = x - winWidth / 2;
	y2 = winHeight / 2 - y;
	if (button == GLUT_LEFT_BUTTON && stat == GLUT_DOWN)
	{
		if (x2<200 && x2>-200 && y2<200 && y2>-200)
			click = !click;
	}
	

	// to refresh the window it calls display() function
	glutPostRedisplay();
}


void onResize(int w, int h)
{
	winWidth = w;
	winHeight = h;
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-w / 2, w / 2, -h / 2, h / 2, -1, 1);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	display(); // refresh window.
}

void onMoveDown(int x, int y) {
	// Write your codes here.



	// to refresh the window it calls display() function
	glutPostRedisplay();
}

// GLUT to OpenGL coordinate conversion:
//   x2 = x1 - winWidth / 2
//   y2 = winHeight / 2 - y1
void onMove(int x, int y) {
	// Write your codes here.



	// to refresh the window it calls display() function
	glutPostRedisplay();
}

#if TIMER_ON == 1
void onTimer(int v) {

	glutTimerFunc(TIMER_PERIOD, onTimer, 0);

	if (activeTimer == true) {
		if (xC < 300) {
			xC += 5;
			yC += 4;
		}
		else {
			xC = 0;
			yC = 0;
		}

		glutPostRedisplay();

	}
}
#endif

void Init(){

	// Smoothing shapes
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

}

void main(int argc, char *argv[]) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	//glutInitWindowPosition(600, 600);
	glutCreateWindow("Submarine Down The Sea");


	glutDisplayFunc(display);
	glutReshapeFunc(onResize);

	//
	// keyboard registration
	//
	glutKeyboardFunc(onKeyDown);
	glutSpecialFunc(onSpecialKeyDown);

	glutKeyboardUpFunc(onKeyUp);
	glutSpecialUpFunc(onSpecialKeyUp);

	//
	// mouse registration
	//
	glutMouseFunc(onClick);
	glutMotionFunc(onMoveDown);
	glutPassiveMotionFunc(onMove);

#if  TIMER_ON == 1
	
	glutTimerFunc(TIMER_PERIOD, onTimer, 0);
#endif

	Init();

	glutMainLoop();
}