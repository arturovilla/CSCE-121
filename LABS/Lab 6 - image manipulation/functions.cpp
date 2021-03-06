
#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include <limits>
#include "functions.h"

using namespace std;

/***************************************************************************
 * 
 * This provided code uses C-style strings.
 * Later this semester the students will be learning and using C++ Strings 
 * instead.
 * It is important to know about C-style strings because they are used
 * in a lot of code. Unless you have a specific, compelling reason to use C-style
 * strings, once you learn C++ Strings, use std::string (defined in the <string> header) instead. 
 * std::string is easier, safer, and more flexible. 
 *
 ***************************************************************************/

/*  Function processImage
 *  choice: char representing which type of image processing to perform
 *  image: 2d-array of Pixels (structs)
 *  Return value: none
 */
 // You should not modify this function unless you add another processing option. //
void processImage(char choice, Pixel image[MAX_WIDTH][MAX_HEIGHT]) {
  const int maxFilenameSize = 100;
  char originalImageFilename[maxFilenameSize];
  char outputImageFilename[maxFilenameSize+6]; // maxFilenameSize plus 6 for adding on "sepia." ".copy" is smaller so works as well
  int width = 0, height = 0;
  
  // get filename, width and height from user
  cout << "Image filename: ";
  cin >> originalImageFilename;
  width = getInteger("width", 1, MAX_WIDTH); // ensure user does not input value greater than the MAX_WIDTH for our array
  height = getInteger("height", 1, MAX_HEIGHT); // ensure user does not input value greater than the MAX_HEIGHT for our array
  
  // load image
  if (loadImage(originalImageFilename, image, width, height)) {
    // only get in here if image loaded successfully
  
    // modify image
    switch (toupper(choice)) {
      case 'G':
        grayscaleImage(image, width, height);
        strcpy(outputImageFilename,"grey.");
        strcat(outputImageFilename, originalImageFilename);
        break;
      case 'S':
        sepiaImage(image, width, height);
        strcpy(outputImageFilename,"sepia.");
        strcat(outputImageFilename, originalImageFilename);
        break;
    }
    
    // output image
    outputImage(outputImageFilename, image, width, height);
  }
}



/*  Function loadImage
 *  filename: c-string which is the ppm file to read
 *  image: 2d-array of Pixels (structs)
 *  width: int for the width of the image array
 *  height: int for height of the image array
 *  Return value: bool true if the image loads, bool false if the image fails to load
 */
 // You should complete this function. //
bool loadImage(const char filename[], Pixel image[MAX_WIDTH][MAX_HEIGHT], int width, int height)
{
  cout << "Loading image..." << endl;
  // declare/define and open input file stream
  ifstream ifs (filename);
  
  // check if input stream opened successfully
  if (!ifs.is_open()) {
    cout << "Error: failed to open input file " << filename << endl;
    return false;
  }
  
  // get type from preamble
  char type[3];
  ifs >> type; // should be P3
  if ((toupper(type[0]) != 'P') || (type[1] != '3')) { // check that type is correct
    cout << "Error: type is " << type << "instead of P3" << endl;
    return false;
  }
  
  // get width (w) and height (h) from preamble
  int w = 0, h = 0;
  ifs >> w >> h;
  if (w != width) { // check that width matches what was passed into the function
    cout << "Error: file width does not match input" << endl;
    cout << " - input width: " << width << endl;
    cout << " -  file width: " << w << endl;
    return false;
  }
  if (h != height) { // check that height matches what was passed into the function
    cout << "Error: file height does not match input" << endl;
    cout << " - input height: " << height << endl;
    cout << " -  file height: " << h << endl;
    return false;
  }
  
  // get maximum value from preamble
  int colorMax = 0;
  ifs >> colorMax;
  if (colorMax != 255) {
    cout << "Error: file is not using RGB color values." << endl;
    return false;
  }//write the data we have computed into the if stream ///////////////////////////////////////////////////////////////////////////////////

  // get RGB pixel values
  // complete this part
 
    for(int col =0; col<height; col++)
    {
        for(int row =0; row<width; row++)
        {
            
            ifs>>image[row][col].r;
            ifs>>image[row][col].g;
            ifs>>image[row][col].b;
            
            
            
            
        }
    }
    
  return true;
}



/*  Function grayscale
 *  image: 2d-array of Pixels (structs)
 *  width: int for the width of the image array
 *  height: int for height of the image array
 *  Return value: none, but image should be modified to be grayscale colors
 */
 // You should write this function. //
void grayscaleImage(Pixel image[MAX_WIDTH][MAX_HEIGHT], int width, int height)
{
  cout << "Making grayscale image... " << endl;
  // iterate through 2d image of Pixels and convert them to grayscale
    for(int col = 0; col<height;col++)
    {
        for(int row = 0; row<width;row++)
        {
            image[row][col].r = round((image[row][col].r+image[row][col].g+image[row][col].b)/3.0);
            image[row][col].g = image[row][col].r;
            image[row][col].b = image[row][col].r;
            
        }
    }
    
}



/*  Function sepiaImage
 *  image: 2d-array of Pixels (structs)
 *  width: int for the width of the image array
 *  height: int for height of the image array
 *  Return value: none, but image should be modified to be sepia colors
 */
 // You should write this function. //
void sepiaImage(Pixel image[MAX_WIDTH][MAX_HEIGHT], int width, int height)
{
  cout << "Making sepia image... " << endl;
  // iterate through 2d image of Pixels and convert them to sepia
    
    int nr = 0;
    int ng = 0;
    int nb = 0;
    
    
    for(int col = 0; col<height; col++)
    {
        for(int row  = 0; row< width; row++)
        {
            nr = round(0.393*image[row][col].r + 0.769*image[row][col].g + 0.189*image[row][col].b);
            ng = round(0.349*image[row][col].r + 0.686*image[row][col].g + 0.168*image[row][col].b);
            nb = round(0.272*image[row][col].r + 0.534*image[row][col].g + 0.131*image[row][col].b);
            
            if(nr>255)
            {
                nr=255;
            }
            if(ng>255)
            {
                ng=255;
            }
            if(nb>255)
            {
                nb=255;
            }
            
            image[row][col].r = nr;
            image[row][col].g = ng;
            image[row][col].b = nb;
        }
    }
    
    
}



/*  Function outputImage
 *  filename: c-string which is the ppm file to write
 *  image: 2d-array of Pixels (structs)
 *  width: int for the width of the image array
 *  height: int for height of the image array
 *  Return value: none, but ppm file should be created
 */
 // You should write this function. //
void outputImage(const char filename[], const Pixel image[MAX_WIDTH][MAX_HEIGHT], int width, int height)
{
    cout << "Outputting image..." << endl;
    cout << "Outputting image..." << endl;
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
  
}



/*  Function printMenu
 *  Return value: none
 */
 // You should not modify this function. //
void printMenu()
{
  cout << "--------------------------" << endl;
  cout << " 'G': Make grayscale image" << endl;
  cout << " 'S': Make sepia image" << endl;
  cout << " 'Q': Quit" << endl;
  cout << "--------------------------" << endl;
  cout << endl << "Please enter your choice: ";
}



/*  Function getInteger
 *  label: label for outputing what the user is inputting, it should work when used as "Please enter <label>"
 *  min: int value indicating the smallest value the user should provide
 *  max: int value indicating the largest value the user should provide
 *  Return value: int value within the range min <= value <= max
 */
 // You should not modify this function. //
int getInteger(const char label[], int min, int max)
{
  // get value from user repeatedly until input matches requirements
  int num = 0;
  do {
    cin.clear(); // reset stream states
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear buffer
    
    cout << "Please enter " << label << " (" << min << " - " << max << "): ";
    cin >> num;
  } while (!cin.good() || num < min || num > max); // while input does not match requirements
  return num;
}
