#include <list>

using namespace std;

class HitCounter {
public:
    list<pair<int, int>> hits;
    int total;
    
    HitCounter() {
        total = 0;
    }
    
    void hit(int timestamp) {
        if (!hits.size() || timestamp > hits.back().first) {
            hits.push_back({timestamp, 1});
        }
        else {
            hits.back().second++;
        }
        this->total++;
    }
    
    int getHits(int timestamp) {
        int start = timestamp - 300 + 1;
        for (auto it = hits.begin(); it != hits.end() && it->first < start;) {
            this->total -= it->second;
            it = hits.erase(it);
        }
        
        return this->total;
    }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */