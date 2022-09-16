#include <iostream>
#include <vector>

using namespace std;

int main() {
    int k;
    cin >> k;
    vector<int> nums;
    for (int i = 0; i < k; i++) {
        int tmp;
        cin >> tmp;
        nums.push_back(tmp);
    }

    for (int n : nums) {
        cout << n << ",";
    }

    cout << endl;
}