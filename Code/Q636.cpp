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
    
    Log(string str) {
        int idIndex = str.find_first_of(":");
        id = stoi(str.substr(0, idIndex));
        int timeIndex = str.find_last_of(":");
        time = stoi(str.substr(timeIndex + 1, string::npos));
        isBegin = str[idIndex + 1] == 's';
        subDuration = 0;
    }
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
