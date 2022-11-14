// input1 = "cat"
// input2 = "tac"

// => return true

// input1 = "caT"
// input2 = "tac"

// => return false


// input1 = "aac*"
// input2 = "*aca"

// => return true

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool checkStrings(string str1, string str2) {
        if (str1.size() != str2.size()) return false;
        unordered_map<char, int> charFrequencyMap;
        for (char c : str1) 
            charFrequencyMap[c]++;
        // store the number of distince chars
        int sz = charFrequencyMap.size();
        int distincts = sz;
        for (char c : str2) {
            charFrequencyMap[c]--;
            if (charFrequencyMap[c] == 0) {
                distincts--;   
            }
            else if (charFrequencyMap[c] < 0) {
                return false;
            }
        }
        
        return distincts == 0;
    }
    
    vector<vector<string>> clutsterStrings(vector<string>& inputStrs) {
        unordered_map<string, vector<string>> stringMap;
        string tmp = "";
        
        // get the key for input strings
        for (string& str : inputStrs) {
            // bat, tab will be the same
            tmp = str;
            // change this sort to bucket sort.
            // sort(tmp.begin(), tmp.end());
            busketSort(tmp);
            stringMap[tmp].push_back(str);
        }
        
        // push them back to return
        vector<vector<string>> ret;
        for (auto& pair : stringMap) {
            ret.push_back(pair.second);
        }
        
        return ret;
    }
    
    // without busket sort, the complexity is O(N*Mlog(M))
    // with busket sort, the complexity is O(N*M)
    void busketSort(string& s) {
        vector<int> charFrequency(26, 0);
        // push the char input busket and store their frequency
        for (char c : s) 
            charFrequency[c - 'a']++;
            
        int index = 0;
        for (int i = 0; i < 26; i++) {
            if (!charFrequency[i]) continue;
            for (int j = 0; j < charFrequency[j]; j++) 
                s[index++] = char('a' + i);
        }
    }
};

int main() {
// input2 = "tac"
    Solution s;    
    cout << s.checkStrings("cat", "tac") << endl;
    cout << s.checkStrings("caT", "tac") << endl;
    cout << s.checkStrings("aac*", "*aca") << endl;
    
    vector<string> strs = {"bat", "cat", "tac", "tab", "car"};
    for (auto& vec : s.clutsterStrings(strs)) {
        for (string& s : vec) {
            cout << s << " ";
        }
        cout << endl;
    }
   
    return 0;
}

// the size of input is N, the max length of input string is m
// the time to sort each input string is mlogm
// the time to sort all is n*mlogm + n*logn


// bat, cat, tac, tab, car

// bat, tab 
// cat, tac
// car
