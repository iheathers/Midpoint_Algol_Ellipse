#include <iostream>
#include <GL/glut.h>
#include <cmath>

using namespace std;

void drawEllipse();
void inputData();
void CoordinateAxes();
void plot(float x, float y);
void drawSymmetryPoints();

float x, y;
float Xc, Yc;
float Rx, Ry;

int main(int argc, char** argv)
{
    inputData();

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(700,700);

    glutCreateWindow("Midpoint Algorithm Ellipse");
    glutDisplayFunc(drawEllipse);

    glutMainLoop();
    return 0;
}

void drawEllipse()
{
    CoordinateAxes();
    glColor3ub(255 ,255,255);
    glBegin(GL_POINTS);

        float P1 = pow(Ry, 2) - pow(Rx, 2)* Ry + (1/4)*pow(Rx,2);
        x = 0;
        y = Ry;
        while (pow(Ry,2)*x < pow(Rx,2)*y)
        {
            if( P1 < 0)
            {
                x++;
                P1 += 2 * pow(Ry,2)* x + pow(Ry,2);
            }
            else
            {
                x++;
                y--;
                P1 += 2 * pow(Ry,2)* x - 2 * pow(Rx, 2)* y + pow(Ry, 2);
            }
            drawSymmetryPoints();

        }

        float P2 = pow(Ry, 2) * pow(x + 0.5,2) + pow(Rx, 2) * pow(y-0.5, 2) - pow(Rx,2) * pow(Ry, 2);
        while (y > 0)
        {
            if (P2 > 0)
            {
                y--;
                P2 += pow(Rx,2) - 2*pow(Rx, 2)*y;
            }
            else
            {
                x++;
                y--;
                P2 += 2*pow(Ry, 2)*x - 2*pow(Rx, 2)*y + pow(Rx,2);
            }
            drawSymmetryPoints();
        }
    glEnd();
    glFlush();
}

void inputData()
{
    cout << "Enter center of ellipse: ";
    cin >> Xc >> Yc;

    cout << "Enter radii of ellipse(Rx, Ry): ";
    cin >> Rx >> Ry ;
}

void CoordinateAxes()
{
    glColor3ub(0,0,255);
    glBegin(GL_LINES);
        glVertex2f(0,1);
        glVertex2f(0,-1);
        glVertex2f(-1,0);
        glVertex2f(1,0);
    glEnd();
}

void plot(float x, float y)
{
    glVertex2f(x/500, y/500);
    //cout << "(" << x << "," << y << ")";
}

void drawSymmetryPoints()
{
    plot(Xc + x, Yc + y);
    plot(Xc - x, Yc + y);
    plot(Xc + x, Yc - y);
    plot(Xc - x, Yc - y);
}




