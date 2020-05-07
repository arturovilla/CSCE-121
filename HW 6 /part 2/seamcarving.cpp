#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <cmath>
#include "functions.h"

using namespace std;

int main() {
  string filename;
  int width = 0;
  int height = 0;
  int targetWidth = 0;
  int targetHeight = 0;
  
  // Add code to validate input (Do in part 1)
  cout << "Input filename: ";
  cin >> filename;
   ////////////////////////////////////////////////////

    cout << "Input width and height: ";
  cin >> width;
    if(cin.fail())
    {
        cout<<"Error: width is a non-integer value";
        exit(1);
    }
    cin>>height;
    if(cin.fail())
    {
        cout<<"Error: height is a non-integer value";
        exit(1);
    }
    
  cout << "Input target width and target-height: ";
  cin >> targetWidth;
    if(cin.fail())
    {
        cout<<"Error: target width is a non-integer value";
        exit(1);
    }
    cin>>targetHeight;
    if(cin.fail())
    {
        cout<<"Error: target height is a non-integer value";
        exit(1);
    }
    
    
    
    
    
    //When width, height, targetWidth or targetHeight are less than or equal to 0.
    if(width <=0)
    {
        cout<<"Error: width must be greater than 0. You entered "<< width<<endl;
        exit(1);
    }
    if(height <= 0 )
    {
        cout<<"Error: height must be greater than 0. You entered "<< height<<endl;
        exit(1);
    }
    if(targetWidth <= 0 )
    {
        cout<<"Error: target Width must be greater than 0. You entered "<< targetWidth<<endl;
        exit(1);
    }
    if(targetHeight <= 0)
    {
        cout<<"Error: target Height must be greater than 0. You entered "<< targetHeight<<endl;
        exit(1);
    }
    if(targetHeight>height)
    {
        cout<<"Error: target Height must be less than height, "<< targetHeight <<" is greater than "<< height <<endl;
        exit(1);
    }
    if(targetWidth>width)
    {
        cout<<"Error: target Width must be less than width, "<< targetWidth <<" is greater than "<< width <<endl;
        exit(1);
    }
    
    
    
  
  int originalWidth = width; // need to delete image array at end of program

  Pixel** image = createImage(width, height); // create array of size that we need
  if (image != nullptr) {
    if (loadImage(filename, image, width, height)) {
      cout << "Start carving..." << endl;
      //////////////////////////////////////////////////////////////////////////////////////////////////////////////
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////
      // Add code to remove seams from image (Do in part 2)
        
        while(width > targetWidth || height > targetHeight)
        {
            if(width>targetWidth)
            {
                int* seam = findMinVerticalSeam(image, width, height);
                removeVerticalSeam(image, width, height, seam);
                width--;
                
            }
            if(height>targetHeight)
            {
                int* seam2 = findMinHorizontalSeam(image, width, height);
                removeHorizontalSeam(image, width, height, seam2);
                height--;
            }
            
            
        }

      // set up output filename
      stringstream ss;
      ss << "carved" << width << "X" << height << "." << filename;
      outputImage(ss.str().c_str(), image, width, height);
    }
  
    // call last to remove the memory from the heap
    deleteImage(image, originalWidth);
  }
  // else
    
    
    
    
    
    
    
    
//    Update seamcarving.cpp to remove seams.
//    Pseudocode
//    While width is greater than target width or height is greater than target height
//    If width is greater than target width
//    Find minimal vertical seam
//    Remove minimal vertical seam
//    Update width (i.e. decrement by one)
//    If height is greater than target height
//    Find minimal horizontal
//    Remove minimal horizontal seam
//    Update height (i.e. decrement by one)
//Note: it is important to remove the vertical seam prior to the horizontal seam since this can affect the subsequent calculation of energies for pixels.
//    Ensure entire program does not have a memory leak.
    

    
    
    
}

