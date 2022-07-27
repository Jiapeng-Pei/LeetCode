#include <unordered_map>

using namespace std;

class Logger {
public:
    unordered_map<string, int> map;        

    Logger() {
    }
    
    bool shouldPrintMessage(int timestamp, string message) {
        if (!map.count(message) || map[message] <= timestamp) {
            map[message] = timestamp + 10;
            return true;
        }
        else {
            return false;
        }
    }
};
