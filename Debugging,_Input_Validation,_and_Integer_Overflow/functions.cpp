int Largest(int a, int b, int c) {
  int d = -9999999;
  if (a > d) {
    d = a;
  }if (b > d) {
    d = b;
  }if (c > d) {
    d = c;
  }
  return d;
}



bool SumIsEven(int a, int b) {
  if((a+b)%2){
    return false;
  }
  else{
    return true;
  }
}



int BoxesNeeded(int apples) {
  if (apples%20 == 0){
    if((apples>0)){
      return (apples/20);
    }
    else{
      return 0;
    }
  }
  else{
    if((apples>0)){
      return (1+apples/20);
    }
    else{
      return 0;
    }
  }
}

#include <stdexcept>
bool SmarterSection(int A_correct, int A_total, int B_corect, int B_total) {
  double AA = A_correct;
  double BB = A_total;
  double CC = B_corect;
  double DD = B_total;
  if((AA>=0.0)&&(BB>0.0)&&(CC>=0.0)&&(DD>0.0)&&(AA<=BB)&&(CC<=DD)){
    return AA/BB > CC/DD;
  }else{
    throw std::invalid_argument("");
  }
}

bool GoodDinner(int pizzas, bool is_weekend) {
  if (! is_weekend){
    if (pizzas >= 10 && pizzas <= 20) {
    return true;
    }else{
      return false;
    }
  }else{
    if (pizzas >= 10) {
      return true;
    }else{
      return false;
    }
  }
}

/*
int SumBetween(int low, int high) {
  int value = 0;
  if (low<0 && high>0){
    if (abs(low) > abs(high)){
      for (int n = low; n < (high*-1); n++){
        value += n;
      }
    }
    else if (abs(low) < abs(high)){
      for (int n = (abs(low)+1); n <= high; n++){
        value += n;
      }
    }
  }
  else{
    for (int n = low; n <= high; n++) {
      value += n;
    }
  
  }
  return value;
}
*/




int SumBetween(int low, int high) {
  int value = 0;
  int n;
  if (low == INT32_MIN && high == INT32_MAX) {
    return low;
  }
  if (low > high ) {
    throw std::invalid_argument("");
  }
  if (low < 0 && high >0) {
    if (low > (-1*high)) {
      low =  -1*(low) + 1;
    }
    else if ((low) < (-1*high)) {
      high = -(high) - 1;
    }
    else {
      return 0;
    }

  }
  for (n = low; n <= high; n++) {
    if (n>0 && n>INT32_MAX- value) {
      throw std::overflow_error("");
    }
    else if (n<0 && n< INT32_MIN - value) {
      throw std::overflow_error("");
    }
    value += n; 
    if (n == INT32_MAX) {
      break;
    }   
  }
  return value;
}






/*
int SumBetween(int low, int high) {
  int value = 0;
  int i = 0;
  if(high<low){
      throw std::invalid_argument("");
  }
  else{
    for (int n = low; n <= high; n++){
      if((n>0 &&INT32_MAX-n<value) || (n<0 && INT32_MIN-n> value)){
        throw std::overflow_error("");
      }
      else{
        i +=n;
      }
    }
    if (low<0 && high>0){
      if (abs(low) > abs(high)){
        for (int n = low; n < (high*-1); n++){
          value += n;
        }
      }
      else if (abs(low) < abs(high)){
        for (int n = (abs(low)+1); n <= high; n++){
          value += n;
        }
      }
    }
    else{
      for (int n = low; n <= high; n++) {
        value += n;
      }
    
    }
  }
  return value;
}
*/


/*
int SumBetween(int low, int high) {
  int value = 0;
  if(high<low){
    throw std::invalid_argument("");
  }
  for (int n = low; n <= high; n++) {
    if((n>0 &&INT32_MAX-n<value) || (n<0 && INT32_MIN-n> value)){
        throw std::overflow_error("");
    }
    value += n;
  }
  return value;
}
*/



/*
int Product(int a, int b) {
  int prod = a*b;
  if ((a==-1)&&(b==INT32_MIN)){
    throw std::overflow_error("hi");
  }
  else if ((b==-1)&&(a==INT32_MIN)){
    throw std::overflow_error("hi");
  }
  else if (a==0 || b==0){
    return 0;
  }
  else if (prod == a*b){
    return prod;
  }
  else{
    throw std::overflow_error("hi");
  }
}
*/
int Product(int a, int b) {
  int prod = a*b;
  if((a ==(-1)) && b== INT32_MIN){
    throw std::overflow_error("");
  }
  else if(b ==-1 && a== INT32_MIN){
    throw std::overflow_error("");
  }
  else if(a==0||b==0){
    return 0;
  }
  else if((prod/a)==b){
    return a*b;
  } 
  else{
    throw std::overflow_error("");
  }
}