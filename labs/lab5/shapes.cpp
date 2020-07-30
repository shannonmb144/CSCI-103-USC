#include <iostream>
#include <cmath>
#include "bmplib.h"

using namespace std;

// global variable. bad style but ok for this lab
unsigned char image[SIZE][SIZE];

bool in_bounds(int x, int y)
    {
        return (( x<256 && x >=0) && (y<256 && y>=0));
    }
// Fill in this function:
void draw_rectangle(int top, int left, int height, int width) {
     for (int i=top; i < top + height; i++) 
         {
             if (in_bounds(left+width, i))
             {
                 image[i][left+width] = 0;
             }
             if (in_bounds(left,i))
             {
                 image [i][left] = 0;
             }
         }
       
     for (int j=left; j < width+left ; j++) 
         {
             if(in_bounds(top, j))
             {
                 image[top][j] = 0;
             }
             if (in_bounds (top+height,j))
             {
                 image[top+height][j] = 0;
             }  
         }
}

// Fill in this function:
void draw_ellipse(int cy, int cx, int height, int width) {
    for (double i=0; i<=2*M_PI; i+=0.01)
    {
        int x = cx +width/2*cos(i);
        int y = cy +height/2*sin(i);
        if(in_bounds(x,y))
        {
            image[y][x]=0;
        }
    }  
}


int main() {
   // initialize the image to all white pixels
   for (int i=0; i < SIZE; i++) {
      for (int j=0; j < SIZE; j++) {
         image[i][j] = 255;
      }
   }
   
   // Main program loop here
   int n=-1;
   
   cout << "To draw a rectangle, enter: 0 top left height width" << endl;
   cout << "To draw an ellipse, enter: 1 cy cx height width " << endl; 
   cout<< "To save your drawing as 'output.bmp' and quit, enter: 2" << endl;
   while (n !=2) {
       cin >> n; 
       if (n==2)
       {
           break;
       }
       int top, left, height, width;
       cin >> top >> left >> height >> width;
       if (n==0)
       {
           draw_rectangle(top, left, height, width);
       }
       if (n==1)
       {
           draw_ellipse(top, left, height, width);
       }
   }
   
   
   // Write the resulting image to the .bmp file
       writeGSBMP("output.bmp", image);   
   
   return 0;
}
