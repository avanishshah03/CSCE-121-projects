#include <iostream>
#include "cstring.h"

unsigned int length(char str[]) {
  // returns the length of the string including zero (0)
  int len = 0;
  int i=0;
  while(str[i]){
    len++;
    i++;
  }

  return len;
}

unsigned int find(char str[], char character) {
  // returns 
  //  - the index of the first occurence of character in str
  //  - the size if the character is not found
  int num = 0;
  int i=0;
  int len = 0;
  int count = 9999999;
  while(str[i]){
    len++;
    i++;
  }
  i = 0;
  count = len-1;
  num = len;
  while(str[i]){
    
    if (str[i] == character){
      if(count == (len-1) ){
        num = i ;
        count++;
      }
    }
    i++;
  }



  //unsigned int temp;
  //temp = s.find(character);
  
  return num;
}

bool equalStr(char str1[], char str2[]) {
  // returns true if they are equal and false if they are not

  int len1 = 0;
  int i=0;
  while(str1[i]){
    len1++;
    i++;
  }
  int len2 = 0;
  i=0;
  while(str2[i]){
    len2++;
    i++;
  }
  i = 0;
  bool result = true;
  int count = 0;
  if(len1 == len2){
      while(i<len1){
        if(str1[i] != str2[i]){
          if (count == 0){
            result = false;
            count++;
          }
        }i++;
      
      }
      
   }else{
       result = false;
   }
  
  
  return result;
}