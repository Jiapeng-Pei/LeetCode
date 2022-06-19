#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int i = wordList.size();
        for (; i > -1 && wordList[i] != endWord; i--);
        if (i == -1) return 0;
                
    }   

    int checkDiff(unordered_map<int, char>& current, string& target) {
        int diffIndex = -1;
        for (int i = 0; i < target.size(); i++) {
            if (target[i] != current[i]) {
                if (diffIndex == -1) {
                    diffIndex = i;
                }
                else {
                    diffIndex = -1;
                    break;
                } 
            } 
        }

        return diffIndex;
    }
};