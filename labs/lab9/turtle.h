//#include <iostream>
//using namespace std;
#include "draw.h"

class Turtle {
 public: 
    Turtle(double x0, double y0, double dir0);
    void move(double dist);
    void turn(double deg);
    void setColor(Color c);
    void off();
    void on();
    void eye1(double c11, double c12, double rad1);
    void eye2(double c21, double c22, double rad2);
    void nose(double c_nose1, double c_nose2, double rad_nose);
    void mouth(double cx, double cy, double rx);
    void pumpkin(double a, double b, double c);
    void stem(double d, double e, double f);
    
 private:
    double x;
    double y;
    double dir;
    double deg;
    double dist;
    Color col;
    bool pen;
};