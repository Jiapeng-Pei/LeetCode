#include <vector>

using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        vector<int> seq;
        for (int n : nums) {
            if (!seq.size() || n > seq.back()) {
                seq.push_back(n);
            }
            else if (n <= seq[0]) {
                seq[0] = n;
            }
            else {
                seq[1] = n;
            }

            if (seq.size() == 3) return true;
        }

        return false;
    }
};