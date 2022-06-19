#include <vector>
#include <unordered_map>
#include <cstdlib>

using namespace std;

class RandomizedSet {
public:
    vector<int> nums;
    unordered_map<int, int> numToIndex;

    RandomizedSet() {

    }
    
    bool insert(int val) {
        if (numToIndex.count(val)) return false;
        numToIndex.insert(make_pair(val, nums.size()));
        nums.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        if (!nums.size() || !numToIndex.count(val)) return false;
        int index = numToIndex[val];
        numToIndex[nums.back()] = index;
        numToIndex.erase(val);
        swap(nums[index], nums.back());
        nums.pop_back();

        return true;
    }
    
    int getRandom() {
        int randIndex = rand() % nums.size();
        return nums[randIndex];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */