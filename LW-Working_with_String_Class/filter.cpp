#include <iostream>
#include <string>
using std::cin, std::cout, std::endl, std::string;

int main() {
/*
    string fishy;
    getline(cin,fishy);
    string filt;
    cin >> filt; 
    string replacer = "#";
    cout << filt << endl;
    for (unsigned int n=0; n<(filt.size() -1);n++){
        replacer.append("#");
    } 
    cout << replacer << endl;
    int finder = 0;
    for(unsigned int n=0; n<(fishy.size());n++){
        fishy.replace((fishy.find(filt,finder)),(filt.size()),replacer);
        finder += (fishy.find(filt,finder));
        
    }
    std::replace( fishy.begin(), fishy.end(), 'x', 'y');
    cout << fishy << endl;
*/
    cout << "Please enter the sentence: ";
    string fishy = "";
    cout << "Please enter the filter word: ";
    std::getline(cin, fishy);
    string filt = "";
    cin >> filt;
    int finder = 0;
    while(fishy.find(filt) != string::npos) {
        finder = fishy.find(filt);
        for(int n = 0; n < (filt.length()); n++) {
            fishy.replace(finder, 1, "#");
            finder++;
        }
    }

    cout << "Filtered sentence: " << fishy << endl;
    return 0;
}
