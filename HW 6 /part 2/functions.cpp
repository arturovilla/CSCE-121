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
    
   /*
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
    
    
    
    */
    
    int red, green, blue, tot, Xval, Yval =  0;//i m
    if (x == 0)
    {
        red = image[x + 1][y].r - image[width - 1][y].r; //
        green = image[x + 1][y].g - image[width - 1][y].g;
        blue = image[x + 1][y].b - image[width - 1][y].b;
        Xval = pow(blue,2) + pow(red,2) + pow(green,2);
    }
    else if (x == width - 1)
    {
        red = image[x - 1][y].r - image[0][y].r;
        green = image[x - 1][y].g - image[0][y].g;
        blue = image[x - 1][y].b - image[0][y].b;
        Xval = pow(blue,2) + pow(red,2) + pow(green,2);
    }
    else
    {
        red = image[x - 1][y].r - image[x + 1][y].r;
        green = image[x - 1][y].g - image[x + 1][y].g;
        blue = image[x - 1][y].b - image[x + 1][y].b;
        Xval = pow(blue,2) + pow(red,2) + pow(green,2);
    }
    if (y == 0)
    {
        
        red = image[x][y+1].r - image[x][height -1].r;
        green = image[x][y+1].g - image[x][height -1].g;
        blue = image[x][y+1].b - image[x][height -1].b;
        Yval = pow(blue,2) + pow(red,2) + pow(green,2);
    }
    else if (y == height-1)
    {
        
        red = image[x][height-2].r - image[x][0].r;
        green = image[x][height-2].g - image[x][0].g;
        blue = image[x][height-2].b - image[x][0].b;
        Yval = pow(blue,2) + pow(red,2) + pow(green,2);
    }
    else
    {
        red = image[x][y+1].r - image[x][y - 1].r;
        green = image[x][y+1].g - image[x][y - 1].g;
        blue = image[x][y+1].b - image[x][y - 1].b;
        Yval = pow(blue,2) + pow(red,2) + pow(green,2);
    }
    tot = Xval + Yval;
    
    return(tot);
}










////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// implement for part 2


//This function will traverse through an image starting at the first row at the given start_col. See “Loading a vertical seam” below for how the traversal works. See “Seam Representation” below for how seams are represented.
//The function returns the total energy of the seam
//The first parameter is a 2d array of Pixels (structs) that hold a color value
//The second parameter is the column to start the seam.
//The third parameter is the width of the array (i.e. the number of columns) needed for traversing the array
//The fourth parameter is the height of the array (i.e. the number of rows) needed for traversing the array.
//The fifth parameter is an array to be loaded with column values for each row.
//Pseudocode
//Set seam for the first row to the starting column
//Initialize total energy to the energy for pixel (start_col, 0)
//For each subsequent row
//Calculate the energy of each possible next column
//Set the seam for current row to the column with the minimal energy
//Add the minimal energy to the total energy
//Return total energy

int loadVerticalSeam(Pixel** image, int start_col, int width, int height, int* seam)
{
   // int* newary = new int [height-1];
    
    int runningtotale = 0;
    int xcord = 0;
    int ycord = start_col ;
    
    int left = 0;
    int middle = 0;
    int right = 0;
    
    int rc = 0;
    int lc = 0;
    
    
    
    runningtotale += energy(image, ycord, xcord, width, height);
    
    seam[0] = start_col;
    //newary [0] = 0;
    
    
    for(int i = 1; i < height; i++)
    {
        
        
        lc = (ycord+(width+1))%width;
        rc = (ycord+(width-1))%width;//this will keep i in bounds i thionk
        //xcord=i;
        
        
        
          middle = energy(image, ycord, i, width, height);
        if(lc <0)
        {
            left = 1000000;
        }
        else
        {
             left = energy(image, lc, i, width, height);
        }
        if(rc>=width)
        {
            right =1000000;
        }
        else
        {
            right = energy(image, rc, i, width, height);

        }
    
        
        //right = energy(image, ycord-1, xcord, width, height);
        
      //  middle = energy(image, ycord, i, width, height);
        
        
        
        
       
        /*
        
        
        if(left < middle && left <right)//if two are equal
        {
            runningtotale+=left;
            ycord = lc;
        }
        else if(middle < left && middle < right) ////the pov is upsidedown and from the toop
        {
            runningtotale+=middle;
            //ycord =i;
        }
        else if(right <middle && right< left)
        {
            runningtotale+=right;
            ycord = rc;
        }
        else if(left == right && left <middle)
        {
            runningtotale+=left;
            ycord = lc;
        }
        else
        {
            runningtotale+=middle;
            //ycord = i;
        }
         
         */
        
        
        /////////////////////
        if(middle<=right && middle<=left)
        {
            runningtotale+=middle;
            //ycord =i;
        }//when everything is == go down && when middle == min go down
        else if(left<=right)//(left is min)
        {
            runningtotale+=left;
            ycord = lc;
        }
        else//(right is min)
        {
            runningtotale+=right;
            ycord = rc;
        }
        
        
        
        
        seam[i] = ycord;
        
        //runningtotal +=1;
    }
    
    
   // delete [] seam;
   // seam = newary;
    
    
    
    
    
    
  return runningtotale;
    
    

    
    
}


//This function will traverse through each row, loading its seam in order to find the seam with lowest energy. See “Finding a Minimal Vertical Seam” below for how this works.
//The function returns a pointer to a seam that is the seam with minimal energy.
//The first parameter is a 2d array of Pixels (structs) that hold a color value
//The second parameter is the width of the array (i.e. the number of columns) needed for traversing the array
//The third parameter is the height of the array (i.e. the number of rows) needed for traversing the array.
//Pseudocode
//Set minimal energy to the result of loading the seam for the first column
//Note minimal seam was loaded by function that returned minimal energy
//For each column
//Get energy for the column and load candidate seam
//If the energy is less than minimal energy
//Set minimal energy to energy
//Update minimal seam to be the candidate seam
//Note: you will have to create seams to pass to loadVerticalSeam
//You cannot have a memory leak.

int* findMinVerticalSeam(Pixel** image, int width, int height)// return pointer to seam array
{
    
    int* seamtopassin = new int [height];//this is the seam i will pass in
   
    
    int min = 100000;//   we are going to use to keep track of the min and max energy values // set this to the energy of the 0 column
    //int max = -1000000;//
    int currentenergy = 0;
    int count = 0;
    
    for(int i  = 0; i < width; i++)//we will pass in i as the 'start_col int'
    {
        
        currentenergy = loadVerticalSeam(image, i, width, height, seamtopassin);//this is return the energy for a given column
        
        if(currentenergy<min)
        {
            min=currentenergy;
            count = i;
        }
        
        
    }
    
    
    currentenergy = loadVerticalSeam(image, count, width, height, seamtopassin);//after i fing the min energy i will update the seam array
    
    
    return seamtopassin;
}



//This function remove the pixels from the image corresponding the the vertical seam. See “Removing a Vertical seam” below for how the removal works. See “Seam Representation” below for how seams are represented.
//The first parameter is a 2d array of Pixels (structs) that hold a color value
//The second parameter is the column to start the seam.
//The third parameter is the width of the array (i.e. the number of columns) needed for traversing the array
//The fourth parameter is the height of the array (i.e. the number of rows) needed for traversing the array.
//The fifth parameter is an array indicating which pixels should be removed.
//Pseudocode
//For each row
//Remove pixel (seam[row], row) - note that seam[row] will be the column.
//Implement

void removeVerticalSeam(Pixel** image, int width, int height, int* verticalSeam) //
{
    
    //Pixel** newimage = createImage(width-1, height);
    //int index = 0;
    
    for(int row =0; row<height; row++)
    {
        
        for(int col = verticalSeam[row]; col<width-1; col++)//the is the collumn part ///// j is column
        {
            
           
            
                image[col][row] = image[col+1][row];
                //image[col+1][row] = image[col+2][row];

            //image col row
        }
    }
    delete [] verticalSeam;
//    for(int col =0; col<height; col++)
//    {
//        for(int row =0; row<width; row++)
//        {
//
//
//
//        }
//    }
//
    
    
    
//
//    for(int row = 0; row<height; row++)
//    {
//        for(int col =0; col<width-1;col++)
//        {
//            newimage[col][row] = image[col][row];
//        }
//    }
//
//
//
//
//    delete [] image;
//    image = newimage;
//
//
//
//
//    for(int j = 0; j<width;j++)
//            {
//                for(int i = 0; i<height; i++)
//                {
//                    if(image[j][i] == image[j][horizontalSeam[i]])
//                }
//            }
    
    
    
    
    
    
    
    
    
}


//This function will traverse through an image starting at the first column at the given start_row. See “Loading a Horizontal Seam” below for how the traversal works. See “Seam Representation” below for how seams are represented.
//The function returns the total energy of the seam
//The first parameter is a 2d array of Pixels (structs) that hold a color value
//The second parameter is the column to start the seam.
//The third parameter is the width of the array (i.e. the number of columns) needed for traversing the array
//The fourth parameter is the height of the array (i.e. the number of rows) needed for traversing the array.
//The fifth parameter is an array to be loaded with column values for each row.
//Pseudocode
//Analogous to loadVerticalSeam

int loadHorizontalSeam(Pixel** image, int start_row, int width, int height, int* seam)
{
    int runningtotale = 0;
    int xcord = 0;
    int ycord = start_row ;
    
    int left = 0;
    int middle = 0;
    int right = 0;
    
    int rc = 0;
    int lc = 0;
    
    
    
    runningtotale += energy(image, xcord, ycord, width, height);
    
    seam[0] = start_row;
    //newary [0] = 0;
    
    
    for(int i = 1; i < width; i++)
    {
        
        
        lc = (ycord+(height-1))%height;
        rc = (ycord+(height+1))%height;//this will keep i in bounds i thionk
        //xcord=i;
        
        
        
        middle = energy(image, i, ycord, width, height);
        if(lc <0)
        {
            left = 1000000;
        }
        else
        {
            left = energy(image, i, lc, width, height);
        }
        if(rc>=width)
        {
            right =1000000;
        }
        else
        {
            right = energy(image, i, rc, width, height);
            
        }
        
        
        //right = energy(image, ycord-1, xcord, width, height);
        
        //  middle = energy(image, ycord, i, width, height);
        
        
        
        
        
        /*
         
         
         if(left < middle && left <right)//if two are equal
         {
         runningtotale+=left;
         ycord = lc;
         }
         else if(middle < left && middle < right) ////the pov is upsidedown and from the toop
         {
         runningtotale+=middle;
         //ycord =i;
         }
         else if(right <middle && right< left)
         {
         runningtotale+=right;
         ycord = rc;
         }
         else if(left == right && left <middle)
         {
         runningtotale+=left;
         ycord = lc;
         }
         else
         {
         runningtotale+=middle;
         //ycord = i;
         }
         
         */
        
        
        /////////////////////
        if(middle<=right && middle<=left)
        {
            runningtotale+=middle;
            //ycord =i;
        }//when everything is == go down && when middle == min go down
        else if(left<=right)//(left is min)
        {
            runningtotale+=left;
            ycord = lc;
        }
        else//(right is min)
        {
            runningtotale+=right;
            ycord = rc;
        }
        
        
        
        
        seam[i] = ycord;
        
        //runningtotal +=1;
    }
    
    
    // delete [] seam;
    // seam = newary;
    
    
    
    
    
    
    return runningtotale;
    
    
  //return 0;
}





//This function will traverse through each column, loading its seam in order to find the seam with lowest energy. See “Finding a Minimal Horizontal Seam” below for how this works.
//The function returns a pointer to a seam that is the seam with minimal energy.
//The first parameter is a 2d array of Pixels (structs) that hold a color value
//The second parameter is the width of the array (i.e. the number of columns) needed for traversing the array
//The third parameter is the height of the array (i.e. the number of rows) needed for traversing the array.
//Pseudocode
//Analogous to findMinVerticalSeam
//Note: you will have to create seams to pass to loadHorizontalSeam
//You cannot have a memory leak.


int* findMinHorizontalSeam(Pixel** image, int width, int height)
{
    
    int* seamtopassin = new int [width];//this is the seam i will pass in
    
    
    int min = 100000;//   we are going to use to keep track of the min and max energy values // set this to the energy of the 0 column
    //int max = -1000000;//
    int currentenergy = 0;
    int count = 0;
    
    for(int i  = 0; i < height; i++)//we will pass in i as the 'start_col int'
    {
        
        currentenergy = loadHorizontalSeam(image, i, width, height, seamtopassin);//this is return the energy for a given column
        
        if(currentenergy<min)
        {
            min=currentenergy;
            count = i;
        }
        
        
    }
    
    
    currentenergy = loadHorizontalSeam(image, count, width, height, seamtopassin);//after i fing the min energy i will update the seam array
    
    
    return seamtopassin;
    
    
    
  //return nullptr;
}




//This function remove the pixels from the image corresponding the the horizontal seam. See “Removing a Horizontal seam” below for how the removal works. See “Seam Representation” below for how seams are represented.
//The first parameter is a 2d array of Pixels (structs) that hold a color value
//The second parameter is the width of the array (i.e. the number of columns) needed for traversing the array
//The third parameter is the height of the array (i.e. the number of rows) needed for traversing the array.
//The fourth parameter is an array indicating which pixels should be removed.
//Pseudocode
//Analogous to removeVerticalSeam


void removeHorizontalSeam(Pixel** image, int width, int height, int* horizontalSeam)
{
//
//    int somthing = image[0][0].r;
//    int w = width;
//    int h = height;
    //horizontalSeam[0] = 0;
    
    
//
//    for(int j = 0; j<width;j++)
//    {
//        for(int i = 0; i<height; i++)
//        {
//            if(image[j][i] == image[j][horizontalSeam[i]])
//        }
//    }
    
    
    
    
    for(int row =0; row<width; row++)
    {
        for(int col = horizontalSeam[row]; col<height-1; col++)//the is the collumn part ///// j is column
        {
            
            
            
            image[row][col] = image[row][col+1];
            //image[col+1][row] = image[col+2][row];
            
            //image col row
        }
    }
    delete [] horizontalSeam;
}



