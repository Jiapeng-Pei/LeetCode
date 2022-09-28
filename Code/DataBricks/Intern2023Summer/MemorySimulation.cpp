#include <vector>
#include <string>

using namespace std;

class Solution {
    int counter = 1;
    vector<int> memorySimulation(vector<string> queries) {
        int n = queries.size();
        vector<int> memory(0, 300);
        vector<int> ret;
        for (int i = 0; i < n; i++) {
            if (queries[i][0] == 'E') {
                int id = 123;
                int j = 0;
                while (j < 300 && memory[j] != id) j++;
                int sz = 0;
                while (j < 300 && memory[j] == id) {
                    sz++;
                    memory[j] = 0;
                }
                ret.push_back(sz);
            }
            else {
                int space = 32;
                int id = counter++;
                int startIndex = 0;
                while (startIndex < 300) {
                    if (memory[startIndex]) {
                        startIndex++;
                        continue;
                    }
                    int next = startIndex + 1;
                    while (next < 300 && !memory[next]) {
                        next++;
                    }
                    if (next - startIndex >= space) {
                        // allocate the space and return start index.
                    }
                }
            }
        }

        return ret;
    }
};