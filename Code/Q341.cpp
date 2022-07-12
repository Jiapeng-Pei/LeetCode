#include <vector>
#include <list>

using namespace std;

// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation
class NestedInteger {
public:
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};


class NestedIterator {
public:
    list<pair<const vector<NestedInteger>&, int>> stack;
    NestedIterator(vector<NestedInteger> &nestedList) {
        stack.push_back({nestedList, 0});
    }
    
    int next() {
        if (!hasNext()) throw new exception();
        const vector<NestedInteger>& list = stack.back().first;
        int& index = stack.back().second;
        int ret = list[index].getInteger();
        index++;
        return ret;
    }
    
    bool hasNext() {
        while (stack.size()) {
            const vector<NestedInteger>& list = stack.back().first;
            int& index = stack.back().second;
            if (index == list.size()) {
                stack.pop_back();
                continue;
            }

            if (list[index].isInteger()) { 
                return true;
            }
            else {
                const vector<NestedInteger>& l = list[index].getList();
                stack.push_back({l, 0});
                index++;
            }
        }

        return false;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */