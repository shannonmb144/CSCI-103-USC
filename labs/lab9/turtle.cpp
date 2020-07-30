#include "turtle.h"
#include "draw.h"
#include <iostream>
#include <cmath>

using namespace std;

Turtle::Turtle(double x0, double y0, double dir0)
{
    x = x0;
    y = y0;
    dir = (dir0*M_PI)/180;
    col = draw :: BLACK;
    draw::setcolor(col);
    pen = true;
   
    
}

void Turtle::turn(double deg) 
{
    double deg_rad= (deg*M_PI)/180;
    dir += deg_rad; 
}
void Turtle::move(double dist)
{
    double x2 = 0;
    double y2 = 0;
    if(pen == true)
    {
        x2 = x + dist*cos(dir);
        y2 = y + dist*sin(dir);
        draw::setcolor(col);
        draw::line(x, y, x2, y2);
    }
    
    x +=dist*cos(dir);
    y += dist*sin(dir);
}
void Turtle::setColor(Color c)
{
    col = c;
}
void Turtle::on()
{
   pen = true; 
}
void Turtle::off()
{
    pen = false;
}
