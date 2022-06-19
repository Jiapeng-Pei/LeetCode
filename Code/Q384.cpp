#include <vector>
#include <cstdlib>

using namespace std;

class Solution {
public:
    // the original array stores the initial int array and it won't change.
    // array stores the shuffled array.
    vector<int> initial;
    vector<int> array;
    Solution(vector<int>& nums) {
        initial = nums;
        array = nums;
    }
    
    vector<int> reset() {
        array = initial;
        return array;
    }
    
    vector<int> shuffle() {
        for (int i = 0; i < array.size() - 1; i++) {
            int target = rand() % (array.size() - i) + i;
            swap(array[i], array[target]);
        }

        return array;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */