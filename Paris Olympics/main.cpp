/******************************************************************************

File: main.cpp
Author: Prof. Lupoli & Andrew Nemec
Date: 2/16/2021
Section: 
E-mail: slupoli@tamu.edu
Description:
This file contains C++  code that will simulate data collected from a track 
event with 9 lanes. The code will sort the order, then display the results

Updates
Author: J. Michael Moore & Paul Taele
Author: J. Michael Moore

Input information format
<Time (double)> <Abbreviated Country (String)> <Uniform number (int)> <Lastname (String)>
32.7 USA 12 Moore
36.5 RUS 35 Polsley
45.8 ENG 73 Teale
52.34 CHN 14 Nemec
76.45 ITY 23 Lupoli     

*******************************************************************************/

#include <iostream>
#include "parallel_tracks.h"

using std::cin; using std::cout; using std::endl;
using std::string;

int main()
{
    // TODO: create arrays needed
	
    // TOTO: prep all arrays
	
    // TODO: load the runner's data into the array

    // if unable to load runner data
    //   1) output "Bad input" to standard out
    //   2) exit program by returning 1

    // TODO: determine ranking, notice the rank array receives the results

    // TODO: Output results

    // this is not required in C++ but many people still explitly add it
    
    double timings[SIZE];
    string countries[SIZE];
    unsigned int jnum[SIZE];
    string lastnames[SIZE];
    unsigned int ranking[SIZE];
	
    prep_double_array(timings);
    prep_string_array(countries);
    prep_string_array(lastnames);
    prep_unsigned_int_array(jnum);
    
    if(!(get_runner_data(timings, countries, jnum, lastnames))) {
        cout << "Bad input" << endl;
        return 1;
    }get_ranking(timings, ranking);
    print_results(timings, countries, lastnames, ranking);
    return 0; 
}

