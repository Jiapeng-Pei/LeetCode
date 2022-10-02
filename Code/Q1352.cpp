#include <vector>

using namespace std;

class ProductOfNumbers {
public:
    // preProduct.size() - 1 denotes #valid numbers. 
    vector<int> preProduct{1};
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        if (!num) preProduct = {1};
        else preProduct.push_back(preProduct.back() * num);
    }
    
    int getProduct(int k) {
        if (k > preProduct.size() - 1) return 0;
        return preProduct.back() / preProduct[preProduct.size() - k - 1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */