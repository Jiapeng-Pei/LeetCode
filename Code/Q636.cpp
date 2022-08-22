#include <stdio.h>
#include <string>
#include <vector>
#include <list>

using namespace std;

class Log {
public:
    bool isBegin;
    int time;
    int id;
    int subDuration;
};

class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> ret(n, 0);
        list<Log> stack;
        for (int i = 0; i < logs.size(); i++) {
            Log curLog(logs[i]);          
            if (curLog.isBegin) {
                stack.push_back(curLog);
            }
            else {
                Log start = stack.back();
                stack.pop_back();
                ret[curLog.id] += (curLog.time - start.time + 1 - start.subDuration);
                if (stack.size()) {
                    Log& father = stack.back();
                    father.subDuration += (curLog.time - start.time + 1);
                }
            }
        }

        return ret;
    }
};  

int main() {
    Solution s;
    vector<string> logs{"0:start:0","1:start:2","1:end:5","0:end:6"};
    s.exclusiveTime(2, logs);
}
