#include <iostream>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <cstdlib>
#include "bmplib.h"

using namespace std;

//============================Add function prototypes here======================
void gaussian_filter(unsigned char output[][SIZE][3], unsigned char input[][SIZE][3], int N, double sigma);
void sobel(unsigned char out[][SIZE][RGB], unsigned char in[][SIZE][RGB]);
void convolve(unsigned char out[][SIZE][RGB],unsigned char in[][SIZE][RGB], 
	      int N, double kernel[][11]);
void unsharp(unsigned char output[][SIZE][3], unsigned char input[][SIZE][3], int N, double sigma, double alpha);
void dummy(unsigned char out[][SIZE][RGB], unsigned char in[][SIZE][RGB]);
void gaussian(double kernel[][11], int N, double sigma);



//============================Do not change code in main()======================

#ifndef AUTOTEST

int main(int argc, char* argv[])
{
   //First check argc
  if(argc < 3)
    {
      //we need at least ./filter <input file> <filter name> to continue
      cout << "usage: ./filter <input file> <filter name> <filter parameters>";
      cout << " <output file name>" << endl;
      return -1;
    }
   //then check to see if we can open the input file
   unsigned char input[SIZE][SIZE][RGB];
   unsigned char output[SIZE][SIZE][RGB];
   char* outfile;
   int N;
   double sigma, alpha;
   double kernel[11][11];

   // read file contents into input array
   int status = readRGBBMP(argv[1], input); 
   if(status != 0)
   {
      cout << "unable to open " << argv[1] << " for input." << endl;
      return -1;
   }
   //Input file is good, now look at next argument
   if( strcmp("sobel", argv[2]) == 0)
   {
     sobel(output, input);
     outfile = argv[3];
   }
   else if( strcmp("blur", argv[2]) == 0)
   {
     if(argc < 6)
       {
	 cout << "not enough arguments for blur." << endl;
	 return -1;
       }
     N = atoi(argv[3]);
     sigma = atof(argv[4]);
     outfile = argv[5];
     gaussian_filter(output, input, N, sigma);
   }
   else if( strcmp("unsharp", argv[2]) == 0)
   {
     if(argc < 7)
       {
	 cout << "not enough arguments for unsharp." << endl;
	 return -1;
       }
     N = atoi(argv[3]);
     sigma = atof(argv[4]);
     alpha = atof(argv[5]);
     outfile = argv[6];
     unsharp(output, input, N, sigma, alpha);

   }
   else if( strcmp("dummy", argv[2]) == 0)
   {
     //do dummy
     dummy(output, input);
     outfile = argv[3];
   }
   else
   {
      cout << "unknown filter type." << endl;
      return -1;
   }

   if(writeRGBBMP(outfile, output) != 0)
   {
      cout << "error writing file " << argv[3] << endl;
   }

}   

#endif 

//=========================End Do not change code in main()=====================


// Creates an identity kernel (dummy kernel) that will simply
// copy input to output image and applies it via convolve()
//
// ** This function is complete and need not be changed.
// Use this as an example of how to create a kernel array, fill it in
// appropriately and then use it in a call to convolve.
void dummy(unsigned char out[][SIZE][RGB], unsigned char in[][SIZE][RGB])
{
   double k[11][11];
   for (int i = 0; i < 3; i++)
   {
      for(int j = 0; j < 3; j++)
      {
         k[i][j] = 0;
      }
   }
   k[1][1] = 1;
   convolve(out, in, 3, k);
}


// Convolves an input image with an NxN kernel to produce the output kernel
// You will need to complete this function by following the 
//  instructions in the comments
void convolve(unsigned char out[][SIZE][RGB], unsigned char in[][SIZE][RGB], 
	      int N, double kernel[][11])
{
    						   
   unsigned char padded[SIZE+10][SIZE+10][RGB];  // Use for input image with appropriate 
                                       // padding
   int temp[SIZE][SIZE][RGB];          // Use for the unclamped output pixel 
                                       // values then copy from temp to out, 
                                       // applying clamping 
    for (int i = 0; i < SIZE + 10; i++)
    {
		for (int j = 0; j < SIZE + 10; j++)
        {
			for (int k = 0; k < RGB; k++) 
            {
				padded[i][j][k] = 0; //sets image into padded array
			}
		}
	}

	
	for (int i = 0; i < SIZE; i++) 
    {
		for (int j = 0; j < SIZE; j++) 
        {
			for (int k = 0; k < RGB; k++) 
            {
				padded[i + 5][j + 5][k] = in[i][j][k]; //adds 5 pixels of padding on each side
			}
		}
	}


   //initialize temp pixels to 0 (black)
   for(int i=0;i<SIZE;i++)
   {
       for(int j=0; j<SIZE;j++)
       {
           for(int k=0;k<RGB;k++)
           {
               temp[i][j][k] = 0;
           }
       }
   }


  //now perform convolve (using convolution equation on each pixel of the 
  // actual image) placing the results in temp (i.e. unclamped result)
  //Here we give you the structure of the convolve for-loops, you need
  //to figure out the loop limits
  //for(int y= ;y< ;y++)
  //  for(int x= ;x< ;x++)
  //    for(int k=0;k<RGB;k++)
  //       for(int i= ; i<= ; i++)
  //          for(int j= ; j<= ; j++)
  //                temp[][][k] += padded[][][k]*kernel[][];

  for(int y=0;y<SIZE ;y++) //iterate only through the picture, takes into account the extra 10 padding pixels
  {    
      for(int x=0;x<SIZE ;x++) //iterate only through the picture, takes into account the extra 10 padding pixels
      {
        for(int k=0;k<RGB;k++) //iterate throgh each level of RGB in the image
        {
           for(int i=-(N/2); i<=(N/2) ; i++) //iterate through each pixel by row
           {
               for(int j=-(N/2); j<=(N/2) ; j++) //iterate through each pixel by column
               {
                temp[x][y][k] += padded[x+i+5][y+j+5][k]*kernel[i+ (N/2)][j + (N/2)];  //apply kernel to padded and set to temp
               }
           }
        }
      }
  }

   //now clamp and copy to output
   // You may need to cast to avoid warnings from the compiler:
   // (i.e. out[i][j][k] = (unsigned char) temp[i][j][k];)
  for(int i=0;i<SIZE;i++) // iterate through each layer, row, column
   {
       for(int j=0; j<SIZE;j++)
       {
           for(int l=0;l<RGB;l++)
           {
               if(temp[i][j][l]>255)
               {
                   out[i][j][l]= 255; // when values greater than range, clamp to fit within 255 
               }
               
               else if(temp[i][j][l]<0)
               {
                   out[i][j][l] = 0; //when values less than range, change to 0
               }
               else
               {
                   out[i][j][l] = temp[i][j][l]; //when values are within range, copy to temp 
               }
           }
       }
   }
}

// You will need to complete this function by following the 
//  instructions in the comments
void sobel(unsigned char out[][SIZE][RGB], unsigned char in[][SIZE][RGB])
{
   double k[11][11];
   double s_h1[3][3] = { {-1, 0, 1}, 
                         {-2, 0, 2}, 
                         {-1, 0, 1} };
   double s_h2[3][3] = { {1, 0, -1}, 
                         {2, 0, -2}, 
                         {1, 0, -1} };
   
   unsigned char h1_sobel[SIZE][SIZE][RGB]; //hold intermediate image1
   unsigned char h2_sobel[SIZE][SIZE][RGB]; //hold intermediate image2

   for (int i = 0; i < 11; i++)
   {
      for(int j=0; j < 11; j++)
      {
         k[i][j] = 0; //set all values of k to 0
      }
   }


   // Copy in 1st 3x3 horizontal sobel kernel (i.e. copy s_h1 into k)
   for(int i = 0; i<3; i++)
   {      
       for (int j=0; j<3; j++) //create 3x3 sobel 1
       {
           k[i][j] = s_h1[i][j];
       }
   }
           


   // Call convolve to apply horizontal sobel kernel with result in h1_soble
   convolve(h1_sobel, in, 3, k);


   // Copy in 2nd 3x3 horizontal sobel kernel (i.e. copy s_h2 into k)
   for(int i = 0; i<3; i++)
   {      
       for (int j=0; j<3; j++) //create 3x3 sobel 2
       {
           k[i][j] = s_h2[i][j];
       }
   }
           

   // Call convolve to apply horizontal sobel kernel with result in h2_soble
   convolve(h2_sobel, in, 3, k);


   // Add the two results (applying clamping) to produce the final output 
   for(int i=0;i<SIZE;i++)
   {
       for(int j=0; j<SIZE;j++)
       {
           for(int m=0;m<RGB;m++)
           {
               int temp = (int)h1_sobel[i][j][m]+(int)h2_sobel[i][j][m]; //adds both sobel kernels
               
               if(temp>255)
               {
                   out[i][j][m]= 255; //clamp so values greater than 255 limit are 255
               }
               else if(temp<0)
               {
                   out[i][j][m] = 0; //clamp so values less than 0 become 0
               }
               else
               {
                   out[i][j][m] = (unsigned char)temp; //copy into temp
               }
           }
       }
   }

}


// Add the rest of your functions here (i.e. gaussian, gaussian_filter, unsharp)
void unsharp(unsigned char output[][SIZE][3], unsigned char input[][SIZE][3], int N, double sigma, double alpha)
{
   unsigned char blur[SIZE][SIZE][3];
   for(int i=0; i<SIZE; i++)
   {
       for(int j=0; j<SIZE; j++)
       {
           for(int k=0; k<RGB; k++) //iterate through image
           {
               blur[i][j][k] = 0; //initializes blur to 0
           }
       }
   }
    
   gaussian_filter(blur, input, N, sigma); //call gaussian filter
   for(int i=0; i<SIZE; i++)
   {
       for(int j=0;j<SIZE;j++)
       {
           for(int k=0; k<RGB; k++) //iterate through image
           {
               double details = input[i][j][k]-blur[i][j][k]; //input mimus blurred values to sharpen image
               double blurred_values = input[i][j][k] + (alpha*details); // add the sharpened kernel to the input
               
               if (blurred_values < 0) //clamping for <0, >0, and normal values
               {
					output[i][j][k] = 0;
			   }
			   else if (blurred_values > 255)
               {
					output[i][j][k] = 255;
			   }
			   else 
               {
					output[i][j][k] = (unsigned char)(blurred_values);
               }
           }
       }
   }
}

void gaussian(double kernel[][11], int N, double sigma)
{   
    double final_val = 0; //initializes 
    
    
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            double input1 = (pow(i - (N/2),2))/(2*pow(sigma,2)); //split up given equation into parts
            double input2 = (pow(j - (N/2),2))/(2*pow(sigma,2));
            double equation = exp((-1*(input1+input2))); //final equation
            kernel[i][j] = equation; //uses equation to get gaussian kernel value
            final_val += equation; //adds equation values to input
        }
    }
 
 for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            kernel[i][j] /= final_val; //normalize by dividing each value by total
            
        }
    }
}
void gaussian_filter(unsigned char output[][SIZE][3], unsigned char input[][SIZE][3], int N, double sigma)
{
    double kernel[11][11]; //call kernel
    gaussian(kernel, N, sigma); //apply gaussian
    convolve(output, input , N, kernel); //apply convolve
}