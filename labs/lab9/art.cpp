#include "draw.h"
#include "turtle.h"
#include <iostream>

using namespace std;

int main() {
    draw::setrange(-100,100);
    draw::setpenwidth(3);
    
    Turtle eye1(-30,30, 10);
    eye1.setColor(draw::TEAL);
    Turtle eye2(30,30, 10);
    eye2.setColor(draw::MINT);
    Turtle nose(0,0,0);
    nose.setColor(draw::ROSE);
    Turtle mouth(-40,-20,0);
    mouth.setColor(draw::MAROON);
    Turtle pumpkin(-80,80,0);
    pumpkin.setColor(draw::ORANGE);
    Turtle stem(-10,80,0);
    stem.setColor(draw:: GREEN);
        
    
    eye1.move(20);
    eye1.turn(90);
    eye1.move(20);
    eye1.turn(90);
    eye1.move(20);
    eye1.turn(90);
    eye1.move(20);
    
    eye2.move(20);
    eye2.turn(90);
    eye2.move(20);
    eye2.turn(90);
    eye2.move(20);
    eye2.turn(90);
    eye2.move(20);
    
    nose.move(15);
    nose.turn(120);
    nose.move(15);
    nose.turn(120);
    nose.move(15);

    pumpkin.move(150);
    pumpkin.turn(-90);
    pumpkin.move(150);
    pumpkin.turn(-90);
    pumpkin.move(150);
    pumpkin.turn(-90);
    pumpkin.move(150);
    
    stem.move(15);
    stem.turn(90);
    stem.move(15);
    stem.turn(90);
    stem.move(15);
    stem.turn(90);
    stem.move(15);
    
    draw::show(3);
    mouth.move(25);
    mouth.turn(-90);
    mouth.move(10);
    mouth.turn(90);
    mouth.move(20);
    mouth.turn(90);
    mouth.move(10);
    mouth.turn(-90);
    mouth.move(40);
    mouth.turn(-90);
    mouth.move(25);
    mouth.turn(-90);
    mouth.move(85);
    mouth.turn(-90);
    mouth.move(25);
    draw::show(6);
    draw::show(3);
    
    
       
 return 0;   
}