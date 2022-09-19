#include <vector>

using namespace std;

class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        // time = 0 is a special case.
        int n = security.size();
        vector<int> ret;
        
        vector<int> forwardSlope(n, 0);
        vector<int> backwardSlope(n, 0);
        int slopeSize = 0;
        for (int i = 1; i < n - time; i++) {
            slopeSize += security[i] <= security[i-1] ? 1 : -slopeSize;
            forwardSlope[i] = slopeSize;
        }
        
        slopeSize = 0;
        for (int i = n-2; i >= time; i--) {
            slopeSize += security[i] <= security[i+1] ? 1 : -slopeSize;
            backwardSlope[i] = slopeSize;
        }
        
        for (int i = time; i < n-time; i++) {
            if (forwardSlope[i] >= time && backwardSlope[i] >= time) ret.push_back(i);
        }
        
        return ret;
    }
};