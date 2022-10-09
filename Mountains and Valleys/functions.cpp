#include <iostream>
#include "functions.h"

using std::cout, std::endl , std::cin;

bool is_valid_range(int a, int b) {
	// TODO(student): validate input range
	if ((10 <= a) && ( b < 10000) && (a<=b)){
		return true;
	}else{
		return false;
	}
}

char classify_mv_range_type(int number) {
	// TODO(student): return 'M' if number has /\/\... pattern,
	// return 'V' if number has \/\/ pattern, and return 'N' otherwise
	int reversenum = 0;
    int temp = number;
	int d1 = 0;
	int d2 = 0;
	char movnorn;
	int counter=0;
	int n = number;
	while(n != 0 ){
		n /= 10;
		counter++;
	}
	int x;
	for (x = 0;x < (counter - 1); x++){
		d1 = number % 10;
		number = number / 10;
		d2 = number % 10;
		if (x == 0){
			if (d1<d2){
				movnorn = 'V';
			}else if (d1>d2){
				movnorn = 'M';
			}else {
				movnorn = 'N';
			}
		}else if (x != 0){
			if(movnorn == 'M'){
				if (d1<d2){
					movnorn = 'V';
				}else {
					movnorn = 'N';
				}
			}else if (movnorn == 'V'){
				if (d1>d2){
					movnorn = 'M';
				}else{
					movnorn = 'N';
				}
			}else {
				movnorn = 'N';
			}
		}
		
	}return movnorn;






	
}


void count_valid_mv_numbers(int a, int b) {
	// TODO(student): count the number of valid mountain ranges and valley
	// ranges in the range [a, b] and print out to console using the format
	// in Requirement 4 of the homework prompt
	int mcounter = 0;
	int vcounter = 0;
	int i;
	char out;

	for(i = a; i <= b; i++ ){
		char out = classify_mv_range_type(i);
		if (out == 'M'){
			mcounter += 1;
		}else if (out == 'V'){
			vcounter += 1;
		}
	}cout << "There are " << mcounter << " mountain ranges and " << vcounter << " valley ranges between " << a << " and " << b << "." << endl;
	
}