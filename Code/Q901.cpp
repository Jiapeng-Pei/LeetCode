#include <list>

using namespace std;

class StockSpanner {
public:
    list<pair<int, int>> stack;
    int today = 0;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int index = today++;
        while (stack.size() && stack.back().first <= price) {
            stack.pop_back();
        }
        int ret = stack.size() ? index - stack.back().second : index + 1;
        stack.push_back({price, index});
        
        return ret;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */