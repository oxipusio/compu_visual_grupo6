#include <iostream>
#include <math.h>
#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
void init(void);
void display(void);
void reshape(int, int);
void abasico(int, int, int, int);
void ingresoDatos(void);
void aPuntoMedioCirculo(int radio,int posx,int posy);
void elipseAhora();
void aPuntoMedioCirculo2(int radio,int posx,int posy);
void elipseAhora()
{
    glTranslatef(0, 0, 0); // ellipse centre
    glBegin(GL_POINTS);
    float inc = (float) M_PI / 500.0;
    for (GLfloat i = 0; i < M_PI * 2; i+=inc)
    {
        float x = cos(i) * 25;
        float y = sin(i) * 15;
        glVertex2f(x, y);
    }
    glEnd();

}



int px0,py0,px1,py1;


int main(int argc, char** argv)
{
    ingresoDatos();
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(600, 350);
    glutInitWindowPosition(100,100);
    glutCreateWindow("Algoritmo Punto Medio");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}
void init(void)
{
    glClearColor(1.0,1.0,1.0,0.0); //parametros: rojo, amarillo y azul, el cuarto es el
    glShadeModel(GL_FLAT);
}


void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix(); // salva el estado actual de la matriz
    glColor3f(0,0,1); // Azul
    glPointSize(4); // Fije el grosor de pixel = 2

    elipseAhora();
    aPuntoMedioCirculo(25,0,0);
    aPuntoMedioCirculo2(25,5,10);
    glPopMatrix(); // recupera el estado del matriz
    glFlush();
}

void reshape(int w, int h)
{
    glViewport(0,0,(GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-50.0, 50.0, -50.0, 50, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

}

void aPuntoMedioCirculo(int radio,int posx,int posy)
{
    int x=0;
    int y=radio,d=1-radio;
    glTranslatef(0, 0, 0); // Coloca el centro en otro lado

    glBegin(GL_POINTS);
    glVertex2f(y+posy,x+posx);//Primer Octante
    glVertex2f(x+posx,y+posy);//Segundo Octante
    glVertex2f(-x+posx,y+posy);//Tercer octante
    glVertex2f(-y+posy,x+posx);//Cuarto octante
    glVertex2f(-y+posy,-x+posx);//Quinto octante
    glVertex2f(-x+posx,-y+posy);//Sexto octante
    glVertex2f(x+posx,-y+posy);//Septimo octante
    glVertex2f(y+posy,-x+posx);//Septimo octante
    while(x<y)
    {
        if(d<0)
        {
            d+=2*x+3;
        }
        else
        {
            d+=2*(x-y)+5;
            y--;
        }
        x++;

        glVertex2f(y+posy,x+posx);//Primer Octante
        glVertex2f(x+posx,y+posy);//Segundo Octante
        glVertex2f(-x+posx,y+posy);//Tercer octante
        glVertex2f(-y+posy,x+posx);//Cuarto octante
        glVertex2f(-y+posy,-x+posx);//Quinto octante
        glVertex2f(-x+posx,-y+posy);//Sexto octante
        glVertex2f(x+posx,-y+posy);//Septimo octante
        glVertex2f(y+posy,-x+posx);//Septimo octante

    }

    glEnd();
}



void aPuntoMedioCirculo2(int radio,int posx,int posy)
{
    int x=0;
    int y=radio,d=1-radio;
    glTranslatef(0, 0, 0); // Coloca el centro en otro lado

    glBegin(GL_POINTS);
    glVertex2f(y+posy,x+posx);//Primer Octante
    glVertex2f(x+posx,y+posy);//Segundo Octante
    glVertex2f(-x+posx,y+posy);//Tercer octante
    glVertex2f(-y+posy,x+posx);//Cuarto octante
    glVertex2f(-y+posy,-x+posx);//Quinto octante
    glVertex2f(-x+posx,-y+posy);//Sexto octante
    glVertex2f(x+posx,-y+posy);//Septimo octante
    glVertex2f(y+posy,-x+posx);//Septimo octante
    while(x<y)
    {
        if(d<0)
        {
            d+=2*x+3;
        }
        else
        {
            d+=2*(x-y)+5;
            y--;
        }
        x++;

        glVertex2f(y+posy,x+posx);//Primer Octante
        glVertex2f(x+posx,y+posy);//Segundo Octante
        glVertex2f(-x-posx,y+posy);//Tercer octante
        glVertex2f(-y+posy,x+posx);//Cuarto octante
        glVertex2f(-y+posy,-x-posx);//Quinto octante
        glVertex2f(-x-posx,-y-posy);//Sexto octante
        glVertex2f(x+posx,-y-posy);//Septimo octante
        glVertex2f(y+posy,-x-posx);//Septimo octante

    }

    glEnd();
}

// opcional
void ingresoDatos(void)
{
    px0=3;
    py0=3;
    px1=5;
    py1=5;
}
