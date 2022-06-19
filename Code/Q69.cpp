#include <stdio.h>
#include <iostream>

using namespace::std;

class Solution {
public:
    int mySqrt(int x) {
        if (x < 4) return x ? 1 : 0; 
        int left = 1, right = x;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (mid < x / mid) left = mid + 1;
            else right = mid;
        }

        return left == x / left ? left : left - 1;
    }
};


int main() {
    cout << "test" << endl;
    int a = 50000;
    long b = 50000;
    double c = 50000.;
    cout << a * a << endl;
    auto a0 = a * a;
    cout << a0 << " " << typeid(a0).name() << endl;
    cout << a * b << endl;
    auto a1 = a * b;
    cout << a1 << " " << typeid(a1).name() << endl;

    cout << a * c << endl;
    auto a2 = a * c;
    cout << a2 << " " << typeid(a2).name() << endl;
}