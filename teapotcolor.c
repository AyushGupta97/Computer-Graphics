#include<stdio.h>
#include<GL/glut.h>
GLfloat mat_ambient[]={0.7,0.7,0.7,1.0};
GLfloat mat_diffuse[]={0.5,0.5,0.5,1.0};
GLfloat mat_specular[]={1.0,1.0,1.0,1.0};
const GLfloat mat_shininess[]={50.0};
GLfloat light_intensity[]={0.7,0.7,0.7,1.0};
GLfloat light_position[]={2.0,6.0,3.0,0.0};

void drawtext(float x,float y,char *s)
{
        int i;
        glRasterPos2f(x,y);
        for(i=0;s[i]!='\0';i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,s[i]);

}
void init()
{
    glMaterialfv(GL_FRONT,GL_AMBIENT,mat_ambient);
    glMaterialfv(GL_FRONT,GL_DIFFUSE,mat_diffuse);
    glMaterialfv(GL_FRONT,GL_SPECULAR,mat_specular);
    glMaterialfv(GL_FRONT,GL_SHININESS,mat_shininess);
    glLightfv(GL_LIGHT0,GL_POSITION,light_position);
    glLightfv(GL_LIGHT0,GL_DIFFUSE,light_intensity);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-2.0,2.0,-2.0,2.0,-10.0,10.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(2.0,1.0,2.0,0.0,0.2,0.2,0.0,1.0,0.0);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
}
void teapot()
{
    glPushMatrix();
    glColor3f(0.0,0.1,1.0);
    glTranslated(0.4,0.0,0.4);
    glRotated(30,0,1,0);
    glutSolidTeapot(0.2);
    glPopMatrix();
}
void tabletop()
{
    glPushMatrix();
    glColor3f(0.7,1.0,0.0);
    glTranslated(0.0,-0.3,0.0);
    glScaled(7.0,0.5,7.0);
    glutSolidCube(0.2);
    glPopMatrix();
}
void frontleg()
{
    glPushMatrix();
    glColor3f(1.0,1.0,1.0);
    glTranslated(0.5,-0.7,0.5);
    glScaled(0.5,7.0,0.5);
    glutSolidCube(0.1);
    glPopMatrix();
}
void leftleg()
{
    glPushMatrix();
    glColor3f(1.0,1.0,1.0);
    glTranslated(-0.5,-0.7,0.5);
    glScaled(0.5,7.0,0.5);
    glutSolidCube(0.1);
    glPopMatrix();
}
void rightleg()
{
    glPushMatrix();
    glColor3f(1.0,1.0,1.0);
    glTranslated(0.5,-0.7,-0.5);
    glScaled(0.5,7.0,0.5);
    glutSolidCube(0.1);
    glPopMatrix();
}
void backleg()
{
    glPushMatrix();
    glColor3f(1.0,1.0,1.0);
    glTranslated(-0.5,-0.7,-0.5);
    glScaled(0.5,7.0,0.5);
    glutSolidCube(0.1);
    glPopMatrix();
}
void leftwall()
{
    glPushMatrix();
    glColor3f(0.6,0.3,0.1);
    glTranslated(-1.0,0.0,0.0);
    glScaled(0.1,10.0,10.0);
    glutSolidCube(0.2);
    glPopMatrix();
}
void bottomfloor()
{
    glPushMatrix();
    glColor3f(0.3,1.0,0.5);
    glTranslated(0.0,-1.0,0.0);
    glScaled(10.1,0.1,10.0);
    glutSolidCube(0.2);
    glPopMatrix();
}
void rightwall()
{
    glPushMatrix();
    glColor3f(0.2,1.0,0.1);
    glTranslated(0.0,0.0,-1.0);
    glScaled(10.0,10.0,0.1);
    glutSolidCube(0.2);
    glPopMatrix();
}
void display()
{
    init();

    drawtext(-2.0,1.6,"TEA POT");
    drawtext(-2.0,1.4,"Name :SAGAR BM");
    drawtext(-2.0,1.2,"USN : 1BI16CS423");
    drawtext(-2.0,1.0,"BATCH: A-2");

    teapot();
    tabletop();
    frontleg();
    leftleg();
    rightleg();
    backleg();
    bottomfloor();
    rightwall();
    leftwall();
    glFlush();
}
void main(int argc,char **argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB|GLUT_DEPTH);
    glutInitWindowPosition(50,50);
    glutInitWindowSize(400,300);
    glutCreateWindow("Shaded scene");
    glutDisplayFunc(display);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glClearColor(1.0,1.0,1.0,0.0);
    glViewport(0,0,640,480);
    glutMainLoop();
}


