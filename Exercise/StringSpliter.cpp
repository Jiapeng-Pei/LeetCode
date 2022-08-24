#include <string>
#include <sstream>
#include <vector>
#include <iostream>

using namespace std;

vector<string> split(const string& str, char delim) {
    istringstream iss(str);
    string word;
    vector<string> ret;
    while (getline(iss, word, delim)) {
        if (word.size()) ret.push_back(word);
    }

    return ret;
}

int main() {
    string str = "  Hello!   Could you give me some rices?";
    vector<string> words = split(str, ' ');
    for (string& w : words) cout << w << "|" << endl; 
}