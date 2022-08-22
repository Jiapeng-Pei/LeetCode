#include <map>
#include <unordered_map>

using namespace std;

class StockPrice {
public:
    unordered_map<int, int> stockPrice;
    map<int, int> priceFrequency;
    int latest = 0;
    
    StockPrice() {
        
    }
    
    void update(int timestamp, int price) {
        if (stockPrice[timestamp]) {
            int cur = stockPrice[timestamp];
            if (!--priceFrequency[cur]) priceFrequency.erase(cur);
        }
        latest = max(latest, timestamp);
        stockPrice[timestamp] = price;
        priceFrequency[price]++;
    }
    
    int current() {
        return stockPrice[latest];
    }
    
    int maximum() {
        return priceFrequency.rbegin()->first;
    }
    
    int minimum() {
        return priceFrequency.begin()->first;
    }
};
