#include <stdio.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include "display.h"

t_display display;

void initVars(void) {

	int width = 720;
	int height = 480;

	display.screenHeight=height;
	display.screenWidth=width;

}

void initRenderer(void) {

	glEnable(GL_DEPTH_TEST);
}

void resize(int width, int height) {

	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);

	glLoadIdentity();

	gluPerspective(	45.0,
					(double)width/(double)height,
					1.0,
					200.0);

}

void draw(void) {

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);

    glLoadIdentity();

    glBegin(GL_QUADS);

    // draw square
    glVertex3f(-0.7f, -1.5f, -5.0f);
    glVertex3f(0.7f, -1.5f, -5.0f);
    glVertex3f(0.4f, -0.5f, -5.0f);
    glVertex3f(-0.4f, -0.5f, -5.0f);

    glEnd();
    glutSwapBuffers();

}

void keyboard(unsigned char key, int x, int y) {

//	printf("xy coordinates: %d,%d", x, y);

	switch(key) {
		case 27: // escape
			exit(0);
	}
}

int main(int argc, char** argv) {

    printf("hello world");

    initVars();

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(display.screenWidth, display.screenHeight);
    glutInitWindowPosition(128, 128);
    glutCreateWindow("Hello world :D");

    initRenderer();

    glutDisplayFunc(draw);
    glutKeyboardFunc(keyboard);
    glutReshapeFunc(resize);
    glutMainLoop();
    return 0;

}

