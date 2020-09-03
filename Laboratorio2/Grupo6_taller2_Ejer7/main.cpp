#include <iostream>
#include <math.h>
#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
int ancho;
int alto;

void init(void);
void display(void);
void reshape(int, int);
void aPuntoMedioRecta(int, int, int, int);
void ingresoDatos(void);
void aPuntoMedioCirculo(int radio,int posx,int posy);
void aPuntoMedioCentroCirculo(int radio,int posx,int posy);
int px0,py0,px1,py1;

int main(int argc, char** argv)
{
    ingresoDatos();
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(650, 350);
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

    glViewport(0,0,(GLsizei)ancho/2, (GLsizei)alto);
    aPuntoMedioCirculo(20,-8,-8);
    aPuntoMedioCirculo(8,-16,-16);
    aPuntoMedioCirculo(8,-16,0);
    aPuntoMedioCirculo(8,0,-16);
    aPuntoMedioCirculo(8,0,0);

    aPuntoMedioRecta(-8,-8,6,8);//Diagonal derecha
    aPuntoMedioRecta(-6,-9,-22,-9);//Diagonal izquierda



    aPuntoMedioRecta(-16,0,2,0);//Raya Horizontal
    aPuntoMedioRecta(-16,-16,2,-16);//Raya Horizontal
    aPuntoMedioRecta(-16,-16,-16,0);//Raya Vertical
    aPuntoMedioRecta(2,-16,2,0);//Raya Vertical
    glViewport(ancho/2,0,(GLsizei)ancho/2, (GLsizei)alto);

    //Circulos dentro de un circulo mayor
    aPuntoMedioCirculo(12,0,0);
    aPuntoMedioCentroCirculo(6,6,0);
    aPuntoMedioCentroCirculo(6,-6,0);
    aPuntoMedioCentroCirculo(6,0,6);
    aPuntoMedioCentroCirculo(6,0,-6);

    //Segundo circulo mayor
    aPuntoMedioCirculo(24,0,0);
    aPuntoMedioCirculo(6,12,12);
    aPuntoMedioCirculo(6,-12,12);
    aPuntoMedioCirculo(6,12,-12);
    aPuntoMedioCirculo(6,-12,-12);

    //Tercero circulo mayor
    aPuntoMedioCirculo(36,0,0);
    aPuntoMedioCentroCirculo(6,30,0);
    aPuntoMedioCentroCirculo(6,-30,0);
    aPuntoMedioCentroCirculo(6,0,30);
    aPuntoMedioCentroCirculo(6,0,-30);


    //Cuarto circulo grande
    aPuntoMedioCirculo(48,0,0);
    aPuntoMedioCirculo(6,30,30);
    aPuntoMedioCirculo(6,-30,30);
    aPuntoMedioCirculo(6,30,-30);
    aPuntoMedioCirculo(6,-30,-30);


    //Cudrado

    aPuntoMedioRecta(-48,-48,48,-48);//Raya Horizontal
    aPuntoMedioRecta(-48,48,48,48);//Raya Horizontal
    aPuntoMedioRecta(-48,-48,-48,48);//Raya Vertical
    aPuntoMedioRecta(48,-48,48,48);//Raya Vertical

    aPuntoMedioRecta(-48,32,-32,48);//Diagonal derecha
    aPuntoMedioRecta(32,-48,48,-32);//Diagonal derecha

    aPuntoMedioRecta(-32,-48,-48,-48);//Diagonal izquierda
    aPuntoMedioRecta(48,32,32,32);//Diagonal izquierda

    //Horizontales
    aPuntoMedioRecta(-48,32,-32,16);//Diagonal derecha-> arriba
    aPuntoMedioRecta(32,32,48,16);//Diagonal derecha
    aPuntoMedioRecta(32,-32,48,-48);//Diagonal derecha-> Arfiba
    aPuntoMedioRecta(-48,-32,-32,-48);//Diagonal derecha

    //Vertical

    aPuntoMedioRecta(-32,-48,-32,-32);//Raya Vertical
    aPuntoMedioRecta(-32,32,-32,48);//Raya Vertical
    aPuntoMedioRecta(32,-48,32,-32);//Raya Vertical
    aPuntoMedioRecta(32,32,32,48);//Raya Vertical

    glPopMatrix(); // recupera el estado del matriz
    glFlush();
}

void reshape(int w, int h)
{
    ancho=w;
    alto=h;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-50.0, 50.0, -50.0, 50, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}



void aPuntoMedioRecta(int x0, int y0, int x1, int y1)
{
    int dx, dy, dE, dNE, d, x, y;
    dx = x1 - x0;
    dy = y1- y0;
    d = 2*dy - dx;
    dE = 2*dy;
    dNE = 2*(dy - dx);
    x = x0;
    y = y0;

    glBegin(GL_POINTS);
    glVertex2f(x,y);
    if(x<x1)
    {
        while (x<x1)
        {
            if(d<=0)
            {
                d += dE;
                x++;
            }
            else
            {
                d += dNE;
                x++;
                y++;
            }
            glVertex2f(x,y);
        }

    }
    else if(x>x1)
    {
        while (x>x1)
        {
            if(d<=0)
            {
                d += dE;
                x--;
            }
            else
            {
                d += dNE;
                x--;
                y++;
            }
            glVertex2f(x,y);
        }

    }
    else if(x==x1)
    {
        if(y<y1)
        {
            while (y<y1)
            {
                y++;
                glVertex2f(x,y);
            }

        }
        else
        {
            while (y>=y1)
            {
                y--;
                glVertex2f(x,y);
            }
        }

    }

    glEnd();

}


void aPuntoMedioCentroCirculo(int radio,int posx,int posy)
{
    int x=0;
    int y=radio,d=1-radio;

    glBegin(GL_POINTS);
    glVertex2f(y+posx,x+posy);//Primer Octante
    glVertex2f(x+posx,y+posy);//Segundo Octante
    glVertex2f(-x+posx,y+posy);//Tercer octante
    glVertex2f(-y+posx,x+posy);//Cuarto octante
    glVertex2f(-y+posx,-x+posy);//Quinto octante
    glVertex2f(-x+posx,-y+posy);//Sexto octante
    glVertex2f(x+posx,-y+posy);//Septimo octante
    glVertex2f(y+posx,-x+posy);//Septimo octante
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
        glVertex2f(y+posx,x+posy);//Primer Octante
        glVertex2f(x+posx,y+posy);//Segundo Octante
        glVertex2f(-x+posx,y+posy);//Tercer octante
        glVertex2f(-y+posx,x+posy);//Cuarto octante
        glVertex2f(-y+posx,-x+posy);//Quinto octante
        glVertex2f(-x+posx,-y+posy);//Sexto octante
        glVertex2f(x+posx,-y+posy);//Septimo octante
        glVertex2f(y+posx,-x+posy);//Septimo octante
    }
    glEnd();
}


void aPuntoMedioCirculo(int radio,int posx,int posy)
{
    int x=0;
    int y=radio,d=1-radio;

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

// opcional
void ingresoDatos(void)
{
    px0=3;
    py0=3;
    px1=5;
    py1=5;
}
