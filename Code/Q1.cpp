#include <stdio.h>
#include <vector>
#include <map>
#include <iostream>

using namespace ::std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> my_map;
        vector<int> ret(2, 0);
        for (int i = 0; i < nums.size(); i++) {
            if (my_map.count(target - nums[i])) {
                ret[0] = my_map[target - nums[i]];
                ret[1] = i;
                return ret;
            }
            else {
                my_map[nums[i]] = i;
            }
        }

        return ret;
    }
};

int main() {
    cout << "This is an example build info." << endl;
}

