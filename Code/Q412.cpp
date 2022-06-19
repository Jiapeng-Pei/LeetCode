#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ret(n);
        for (int i = 0; i < n; i++) {
            int j = i + 1;
            if (j % 15 == 0) ret[i] = "FizzBuzz";
            else if (j % 5 == 0) ret[i] = "Buzz";
            else if (j % 3 == 0) ret[i] = "Fizz";
            else ret[i] = to_string(j);
        }
        
        return ret;
    }
};