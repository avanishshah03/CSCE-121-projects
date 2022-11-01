#include <iostream>
#include <string>
using std::cin, std::cout, std::endl, std::string;

int main() {
    string stri = "";
    cout << "Please enter obfuscated sentence: ";
    std::getline(cin, stri);
    string nums = "";
    cout << "Please enter deobfuscation details: ";
    cin >> nums;
    string Deobfuscatedsent = "";
    for(unsigned int n = 0; n < nums.length(); n++) {
        Deobfuscatedsent += stri.substr(0, ((int)nums[n]) - 48);
        if(n != nums.length() - 1) {
            Deobfuscatedsent += " ";
            stri = stri.substr((int)nums[n] - 48);
        }
    }cout << "Deobfuscated sentence: " << Deobfuscatedsent << endl;
    return 0;
}
