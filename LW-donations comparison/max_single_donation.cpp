#include <iostream>
#include <sstream>
#include <fstream>
using std::cin, std::cout, std::endl, std::string, std::getline,
      std::ifstream, std::istringstream;

int main() {
  string filename;
  cout << "Enter donation filename: ";
  cin >> filename;
  ifstream ifs(filename);
  if (!ifs.is_open()) {
    cout << "Failed to open file " << filename << "." << endl;
    return 1;
  }
  
  double maxTotalDonation = 0;
  int maxTotalCollector = 0;
  double maxsingle =0;
  int maxsinglecollector = 0;
  // read data
  string line;
  while(getline(ifs, line)){
    double donation = 0;
    double num = 0;
    int donor;
    int count =0;
    string tmp;
    istringstream money(line);
    money >> donor;
    while(money >> tmp){ 
        num = stod(tmp);
        if(num > maxsingle ){
          maxsingle = num;
          maxsinglecollector = donor;
        }
        donation += num;
        count++;
    }
    if(donation > maxTotalDonation && count >1){
      maxTotalDonation = donation;
      maxTotalCollector = donor;
    }

  }
  if(maxTotalDonation == 0){
    cout << "No donations.";
    return 0;
  }
  cout << "Highest donation total: " << maxTotalDonation << endl;
  cout << "-- collected by id: " << maxTotalCollector << endl;
  cout << "Highest single donation: " << maxsingle << endl;
  cout << "-- collected by id: " << maxsinglecollector << endl;
}
