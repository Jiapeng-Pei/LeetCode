#include <string>
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

vector<string> split(const string& str, char delim) {
    istringstream iss(str);
    string buffer;
    vector<string> ret;
    while (getline(iss, buffer, delim)) {
        if (buffer.size()) ret.push_back(buffer);
    }

    return ret;
}

class Solution {
public: 
    vector<string> textFormat(string text, int width) {
        vector<string> words = split(text, ' ');
        bool newLine = true;
        string buffer = "*  ";
        vector<string> ret;
        for (int i = 0; i < words.size();) {
            string& word = words[i];
            int left = width - buffer.size() + 1;

            if (word.size() > left) {
                // start a new line.
                addStringEnding(buffer, left);
                ret.push_back(buffer);
                buffer = "*";
            }
            else {
                // add the word to current line.
                buffer.append(word);
                left -= word.size();
                if (word.back() == '.' || word.back() == '!' || word.back() == '?') {
                    // start a new line.
                    addStringEnding(buffer, left);
                    ret.push_back(buffer);
                    buffer = "*  ";
                }
                else if (left) {
                    // add a white space after the word.
                    buffer.push_back(' ');
                }
                i++;
            }
        }

        return ret;
    }

private:
    void addStringEnding(string& str, int left) {
        for (int i = 0; i < left; i++) str.push_back(' ');
        str.push_back('*');
    }
};

int main() {
    Solution s;
    for (string& str : s.textFormat("Hello! Could you give me  some rices? I will appreciate it if you do so.", 10)) {
        cout << str << endl;
    }
}