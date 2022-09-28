#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    unordered_map<int, vector<int>> products;
    products[0] = {5, -1, 0};
    products[1].push_back(4);
    products[1].push_back(2);
    products[1].push_back(100);
    for (auto& p : products) {
        for (int n : p.second) cout << n << " ";
        cout << endl;
    }
}