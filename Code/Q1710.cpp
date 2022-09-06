#include "DataStructures.cpp"

class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), [](vector<int>& lhs, vector<int>& rhs){return lhs[1] > rhs[1]; });
        int index = 0, ret = 0;
        while (truckSize > 0 && index < boxTypes.size()) {
            int cur = min(truckSize, boxTypes[index][0]);
            ret += cur * boxTypes[index][1];
            truckSize -= cur;
            if (cur == boxTypes[index][0]) index++;
        }
        
        return ret;
    }
};