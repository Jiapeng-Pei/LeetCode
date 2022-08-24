#include <vector>
#include <string>

using namespace std;

class Solution {
    vector<int> flipBinaryString(vector<string>& requests, string binaryString) {
        int oneCount = 0;
        for (char c : binaryString) {
            if (c == '1') oneCount++;
        }
        vector<int> ret;
        for (string& req : requests) {
            if (req[0] == 'c') ret.push_back(oneCount);
            else {
                if (!oneCount) {
                    ret.push_back(-1);
                    continue;
                }
                signed i = 0;
                for (; i < binaryString.size() && binaryString[i] != '1'; i++) {}
                for (; i >= 0; i--) {
                    if (binaryString[i] == '1') {
                        binaryString[i] = '0';
                        oneCount--;
                    }
                    else {
                        binaryString[i] = '1';
                        oneCount++;
                    }
                }

                ret.push_back(i);
            }
        }

        return ret;
    }
};