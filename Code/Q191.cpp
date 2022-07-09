#include <stdio.h>

using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int bits = 0;
        unsigned int mask = 1;
        for (int i = 0; i < 32; i++) {
            if (n & mask) bits++;
            mask <<= 1;
        }

        return bits;
    }
};

