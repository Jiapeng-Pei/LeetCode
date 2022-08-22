#include <vector>

using namespace std;

class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        vector<long long> ret;
        if (finalSum % 2) return ret;
        long long sum = 0;
        long long cur = 2;
        for (;; cur += 2) {
            if (sum + cur <= finalSum) {
                ret.push_back(cur);
                sum += cur;
            }
            else break;
        }
        
        ret[ret.size() - 1] += finalSum - sum;
        return ret;
    }
};