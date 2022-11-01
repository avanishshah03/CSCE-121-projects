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
    delete [] image; // delete array of pointers
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

void deleteImage(Pixel** image, int width) {
  cout << "Start deleteImage..." << endl;
  // avoid memory leak by deleting the array
  for (int i=0; i<width; ++i) {
    delete [] image[i]; // delete each individual array placed on the heap
  }
  delete [] image;
  image = nullptr;
}

// implement for part 1

int* createSeam(int length) {
  int * seam = new int[length];
  for(int i; i < length; i++){
    seam[i] = 0;
  }
  return seam;
}

void deleteSeam(int* seam) {
  delete [] seam;
}

bool loadImage(string filename, Pixel** image, int width, int height) {
  string str1;
  ifstream inFS;
  inFS.open(filename);
  if(!inFS.is_open()){
    cout << "Error: failed to open input file - " << filename << endl;
    return false;
  }
  inFS >> str1;
  if(str1 != "P3" && str1 != "p3"){
    cout << "Error: type is " << str1 << " instead of P3" << endl;
    return false;
  }
  int widthf;
  int heightf;
  inFS >>widthf;
  inFS >> heightf;
  if(inFS.fail()){
    cout << "Error: read non-integer value" << endl;
    return false;
  }
  if(height != heightf){
    cout << "Error: input height (" << height << ") does not match value in file ("<< heightf << ")" << endl;
    return false;
  }
  if(width != widthf){
    cout << "Error: input width (" << width << ") does not match value in file ("<< widthf << ")" << endl;
    return false;
  }
  int limit;
  inFS >> limit;
  int r;
  int g;
  int b;
  int buff;
  for (int rows = 0; rows < height; rows++){
    for(int cols = 0; cols < width; cols++){
      inFS >> r;
      if(r<0 || r>255){
        cout << "Error: invalid color value " << r << endl;
        return false;
      }
      inFS >> g;
      if(g<0 || g>255){
        cout << "Error: invalid color value " << g << endl;
        return false;
      }
      inFS >> b;
      if(b<0 || b>255){
        cout << "Error: invalid color value " << b << endl;
        return false;
      }
      if(inFS.fail() && inFS.eof()){
        cout << "Error: not enough color values" << endl;
        return false;
      }
      
      image[cols][rows] = {r,g,b};
    }
  }
  inFS >> buff;
  if(!inFS.eof()){
        cout << "Error: too many color values" << endl;
        return false;
      }
  
  
  
  
  
  return true;
}

bool outputImage(string filename, const Pixel*const* image, int width, int height) {
  ofstream outFS;
  outFS.open(filename);
  if(!outFS.is_open()){
    cout << "Error: failed to open output file - " << filename << endl;
    return false;
  }
  outFS << "P3" << endl;
  outFS << width << height << endl;
  outFS << "255" << endl;

  for(int rows; rows < height; rows++) {
    for(int cols = 0; cols < width ; cols++) {
      outFS << image[cols][rows].r << " " << image[cols][rows].g << " " << image[cols][rows].b << " ";
    }
    outFS << endl;
  }
  
  outFS.close();
  return true;
}

int energy(const Pixel*const* image, int x, int y, int width, int height) { 
  int cleft;
  int cright;
  int rup;
  int rdown;
  cleft = x-1;
  if (cleft == -1){
    cleft = width-1;
  }
  cright = x+1;
  if (cright >= width){
    cright = 0;
  }
  rup = y-1;
  if(rup == -1){
    rup = height-1;
  }
  rdown = y+1;
  if (rdown >= height){
    rdown = 0;
  }
  int deltx;
  int delty;
  int energytotal;
  deltx = pow((image[cleft][y].r - image[cright][y].r), 2) + pow((image[cleft][y].g - image[cright][y].g), 2) + pow((image[cleft][y].b - image[cright][y].b), 2);
  delty = pow((image[x][rup].r - image[x][rdown].r), 2) + pow((image[x][rup].g - image[x][rdown].g), 2) + pow((image[x][rup].b - image[x][rdown].b), 2);
  energytotal = deltx + delty;
  
  
  
  
  
  return energytotal;
}

// implement for part 2

// uncomment for part 2
 

int loadVerticalSeam(const Pixel*const* image, int start_col, int width, int height, int* seam) {
  int cl;   //cleft
  int cd;   //cdown
  int cr;   //cright
  int enrtotal = 0;
  int enr;
  cl = start_col - 1;
  cd = start_col;
  cr = start_col +1;
  int newcol;
  int enrl;
  int enrd;
  int enrr;
  
  for (int i=0;i<height;i++){ 
    if(i==0){
      enr = energy(image, start_col,i,width,height);
      newcol = start_col;
      enrtotal = enr;
      seam[i] = newcol;
    }
    else{
      cl = newcol - 1;
      cd = newcol;
      cr = newcol +1;
      if (width == 1){
        enrd = energy(image, cd,i,width,height);
        enr = enrd;
        enrtotal += enr;
        seam[i] = newcol;
      }
      else if(cl == -1){
        
        enrd = energy(image, cd,i,width,height);
        enrr = energy(image, cr,i,width,height);

        if (enrd <= enrr){
          enr = enrd;
          newcol = cd;
        }
        else if (enrr < enrd){
          enr = enrr;
          newcol = cr;
        }
        enrtotal += enr;
        seam[i] = newcol;
      }
      else if(cr >= width){
        enrl = energy(image, cl,i,width,height);
        enrd = energy(image, cd,i,width,height);
        

        if (enrd <= enrl){
          enr = enrd;
          newcol = cd;
        }
        else if (enrl < enrd){
          enr = enrl;
          newcol = cl;
        }
        enrtotal += enr;
        seam[i] = newcol;
      }

      else{
        enrl = energy(image, cl,i,width,height);
        enrd = energy(image, cd,i,width,height);
        enrr = energy(image, cr,i,width,height);
        if ((enrl < enrd) && (enrl < enrr)){
          enr = enrl;
          newcol = cl;
        }
        else if ((enrd < enrl) && (enrd < enrr)){
          enr = enrd;
          newcol = cd;
        }
        else if ((enrr < enrl) && (enrr < enrd)){
          enr = enrr;
          newcol = cr;
        }
        else if((enrd == enrl) || (enrd == enrr)){
          enr = enrd;
          newcol = cd;
        }
        else if(enrl == enrr){
          enr = enrr;
          newcol = cr;
        }
        enrtotal += enr;
        seam[i] = newcol;
      }
    }
  }

  return enrtotal;
}

/*
*/
int loadHorizontalSeam(const Pixel*const* image, int start_row, int width, int height, int* seam) {
    int cl;   //cleft
  int cd;   //cdown
  int cr;   //cright
  int enrtotal = 0;
  int enr;
  cl = start_row - 1;
  cd = start_row;
  cr = start_row +1;
  int newcol;
  int enrl;
  int enrd;
  int enrr;
  
  for (int i=0;i<width;i++){ 
    if(i==0){
      enr = energy(image, i,start_row,width,height);
      newcol = start_row;
      enrtotal = enr;
      seam[i] = newcol;
    }
    else{
      cl = newcol - 1;
      cd = newcol;
      cr = newcol +1;
      if (height == 1){
        enrd = energy(image, i,cd,width,height);
        enr = enrd;
        enrtotal += enr;
        seam[i] = newcol;
      }
      else if(cl == -1){
        
        enrd = energy(image, i,cd,width,height);
        enrr = energy(image, i,cr,width,height);

        if (enrd <= enrr){
          enr = enrd;
          newcol = cd;
        }
        else if (enrr < enrd){
          enr = enrr;
          newcol = cr;
        }
        enrtotal += enr;
        seam[i] = newcol;
      }
      else if(cr >= width){
        enrl = energy(image, i,cl,width,height);
        enrd = energy(image, i,cd,width,height);
        

        if (enrd <= enrl){
          enr = enrd;
          newcol = cd;
        }
        else if (enrl < enrd){
          enr = enrl;
          newcol = cl;
        }
        enrtotal += enr;
        seam[i] = newcol;
      }

      else{
        enrl = energy(image, i,cl,width,height);
        enrd = energy(image, i,cd,width,height);
        enrr = energy(image, i,cr,width,height);
        if ((enrl < enrd) && (enrl < enrr)){
          enr = enrl;
          newcol = cl;
        }
        else if ((enrd < enrl) && (enrd < enrr)){
          enr = enrd;
          newcol = cd;
        }
        else if ((enrr < enrl) && (enrr < enrd)){
          enr = enrr;
          newcol = cr;
        }
        else if((enrd == enrl) || (enrd == enrr)){
          enr = enrd;
          newcol = cd;
        }
        else if(enrl == enrr){
          enr = enrl;
          newcol = cl;
        }
        enrtotal += enr;
        seam[i] = newcol;
      }
    }
  }

  return enrtotal;
  
}


int* findMinVerticalSeam(const Pixel*const* image, int width, int height) {

  int* tempSeam = createSeam(height);
  int* seam = createSeam(height);
  int min = loadVerticalSeam(image, 0, width, height, seam);
  int temp =0;

  for (int i = 1; i < width; i++){
    temp = loadVerticalSeam(image, i, width, height, tempSeam);
    if(min > temp){
      min = temp;
      seam = tempSeam;
    }
  }
  
  deleteSeam(tempSeam);
  return seam;
}


int* findMinHorizontalSeam(const Pixel*const* image, int width, int height) {
  int* tempSeam = createSeam(width);
  int* seam = createSeam(width);
  int min = loadHorizontalSeam(image, 0, width, height, seam);
  int temp =0;

  for (int i = 1; i < height; i++){
    temp = loadHorizontalSeam(image, i, width, height, tempSeam);
    if(min > temp){
      min = temp;
      seam = tempSeam;
    }
  }
  
  deleteSeam(tempSeam);
  return seam;
}


void removeVerticalSeam(Pixel** image, int width, int height, int* verticalSeam) {
  Pixel temp;
  for (int i = 0;i < height; i++){
    temp = image[verticalSeam[i]][i];
    for (int x = verticalSeam[i]; x < width - 1;x++){
      image[x][i] = image[x+1][i];
    }
    image[width-1][i] = temp;
  }

}


void removeHorizontalSeam(Pixel** image, int width, int height, int* horizontalSeam) {
  Pixel temp;
  for (int i = 0;i < width; i++){
    temp = image[horizontalSeam[i]][i];
    for (int x = horizontalSeam[i]; x < height - 1;x++){
      image[x][i] = image[x+1][i];
    }
    image[height-1][i] = temp;
  }
}
