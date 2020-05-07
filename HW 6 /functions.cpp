#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <cmath>
#include "functions.h"

using namespace std;

Pixel** createImage(int width, int height) {
  cout << "Start createImage... " << endl;
  
  // Create a one dimensional array on the heap of pointers to Pixels 
  //    that has width elements (i.e. the number of columns)
  Pixel** image = new Pixel*[width];
  
  bool fail = false;
  
  for (int i=0; i < width; ++i) { // loop through each column
    // assign that column to a one dimensional array on the heap of Pixels
    //  that has height elements (i.e. the number of rows)
    image[i] = new Pixel[height];
    
    if (image[i] == nullptr) { // failed to allocate
      fail = true;
    }
  }
  
  if (fail) { // if any allocation fails, clean up and avoid memory leak
    // deallocate any arrays created in for loop
    for (int i=0; i < width; ++i) {
      delete [] image[i]; // deleting nullptr is not a problem
    }
    delete [] image; // dlete array of pointers
    return nullptr;
  }
  
  // initialize cells
  //cout << "Initializing cells..." << endl;
  for (int row=0; row<height; ++row) {
    for (int col=0; col<width; ++col) {
      //cout << "(" << col << ", " << row << ")" << endl;
      image[col][row] = { 0, 0, 0 };
    }
  }
  cout << "End createImage... " << endl;
  return image;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////
void deleteImage(Pixel** image, int width)
{
  cout << "Start deleteImage..." << endl;
  // avoid memory leak by deleting the array
  for (int i=0; i<width; ++i) {
    delete [] image[i]; // delete each individual array placed on the heap
  }
  delete [] image;
  image = nullptr;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
// implement for part 1

int* createSeam(int length)
{
    int* newseamarray = new int[length];
    for( int i = 0; i<length; i++)
    {
        newseamarray[i] = 0;
    }
  
    return newseamarray;
}
////////////////////////////////////////////////
void deleteSeam(int* seam)
{
    delete [] seam;
}
////////////////////////////////////////////////////////////////////////////////////////////







bool loadImage(string filename, Pixel** image, int width, int height)
{
    /*
     hight and width is from user
     h and w is from pm file
     */
    
    
    //cout << "Loading image..." << endl;
    // declare/define and open input file stream
    ifstream file (filename);
    
    
    if (!file.is_open()) {
        cout << "Error: failed to open input file - " << filename << endl;
        return false;
    }
    
    // get type from preamble
    char type[3];
    file >> type; // should be P3
    
    if ((toupper(type[0]) != 'P') || (type[1] != '3')) { // check that type is correct
        cout << "Error: type is " << type << " instead of P3" << endl;
        return false;
    }
    
    // get width (w) and height (h) from preamble
    int w = 0, h = 0;
    file >> w;
    
    if(file.fail()){
        cout << "Error: read non-integer value" << endl;
        return false;
    }
    
    file >> h;
    if(file.fail()){
        cout << "Error: read non-integer value" << endl;
        return false;
    }
    
    if (w != width) { // check that width matches what was passed into the function
        cout << "Error: input width (" << width << ") does not match value in file (" << w <<")"<< endl;
        
        return false;
    }
    if (h != height) { // check that height matches what was passed into the function
        cout << "Error: input height (" << height << ") does not match value in file (" << h <<")"<< endl;
        return false;
    }
    int Max = 0;
    file >> Max;
    if (Max != 255) {
        cout << "Error: file is not using RGB color values." << endl;
        return false;
    }
    // not enough color values ; too many color values
    for(int i = 0; i<height; i++){
        for(int j = 0; j<width; j++){
            file >> image[j][i].r;
            file >> image[j][i].g;
            file >> image[j][i].b;
            if(file.fail()){
                cout << "Error: not enough color values" << endl;
                return false;
            }
            if(image[j][i].r < 0 || image[j][i].r > 255){
                cout << "Error: invalid color value " << image[j][i].r << endl;
                return false;
            }
            if(image[j][i].b < 0 || image[j][i].b > 255){
                cout << "Error: invalid color value " << image[j][i].b << endl;
                return false;
            }
            if(image[j][i].g < 0 || image[j][i].g > 255){
                cout << "Error: invalid color value " << image[j][i].g << endl;
                return false;
            }
        }
    }
    return true;
}

 
    

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool outputImage(string filename, Pixel** image, int width, int height)
{
  
    
    //cout << "Outputting image..." << endl;
    //cout << "Outputting image..." << endl;
    // declare/define and open output file stream
   
    ofstream os (filename);
    // check if output stream opened successfully
    if(!os.is_open()){cout<<"Error: failed to open output file"<<filename;}
    // output preamble
    os<<"P3"<<endl<<width<<endl<<height<<endl<<255<<endl;
    // output pixels
    for(int j=0; j<height; ++j){
        for(int i=0;i<width;++i)
        {
            os<<image[i][j].r<<" "<<image[i][j].g<<" "<<image[i][j].b<<" ";
        }
    }
    return true;
    
    
    
    
    
    
    
    
    
    
    
}
////////////////////////////////////////////////////////////////////////////////////////////////









int energy(Pixel** image, int x, int y, int width, int height)
{
  
    //x is column
    //y is row
    
    int red, green, blue, sum; // color values
    
    if (x == 0) // this is the outer most boarder column
    {
        red = image[x + 1][y].r - image[width - 1][y].r;//
        green = image[x + 1][y].g - image[width - 1][y].g;
        blue = image[x + 1][y].b - image[width - 1][y].b;
    }
    else if (x == width - 1)
    {
        red = image[x - 1][y].r - image[0][y].r;
        green = image[x - 1][y].g - image[0][y].g;
        blue = image[x - 1][y].b - image[0][y].b;
    }
    else
    {
        red = image[x - 1][y].r - image[x + 1][y].r;
        green = image[x - 1][y].g - image[x + 1][y].g;
        blue = image[x - 1][y].b - image[x + 1][y].b;
    }
            
    if (y == 0)
    {
        
        red = image[x + 1][y].r - image[height - 1][y].r;
        green = image[x + 1][y].g - image[height - 1][y].g;
        blue = image[x + 1][y].b - image[height - 1][y].b;
        
    }
    else if (y == height)
    {
        
        red = image[x + 1][y].r - image[height - 1][y].r;
        green = image[x + 1][y].g - image[height - 1][y].g;
        blue = image[x + 1][y].b - image[height - 1][y].b;
        
    }
    else
    {
        
        red = image[x + 1][y].r - image[height - 1][y].r;
        green = image[x + 1][y].g - image[height - 1][y].g;
        blue = image[x + 1][y].b - image[height - 1][y].b;
    }
    sum = pow(red, 2) + pow(green, 2) + pow(blue, 2);
    
    
    

    
    
    
    return sum;
}

// implement for part 2

// uncomment for part 2
/*

int loadVerticalSeam(Pixel** image, int start_col, int width, int height, int* seam) {
  return 0;
}

int loadHorizontalSeam(Pixel** image, int start_row, int width, int height, int* seam) {
  return 0;
}

int* findMinVerticalSeam(Pixel** image, int width, int height) {
  return nullptr;
}

int* findMinHorizontalSeam(Pixel** image, int width, int height) {
  return nullptr;
}

void removeVerticalSeam(Pixel** image, int width, int height, int* verticalSeam) {
}


void removeHorizontalSeam(Pixel** image, int width, int height, int* horizontalSeam)
{
    
}
*/
