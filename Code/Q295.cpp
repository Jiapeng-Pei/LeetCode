#include <queue>

using namespace std;

class MedianFinder {
public:
    priority_queue<int, vector<int>, less<int>> left;
    priority_queue<int, vector<int>, greater<int>> right;
    MedianFinder() {
    }
    
    void addNum(int num) {
        if (!left.size()) {
            left.push(num);
            return;
        }

        if (left.size() == right.size()) {
            if (num <= left.top()) {
                left.push(num);
            }
            else {
                right.push(num);
                left.push(right.top());
                right.pop();
            }
        }
        else {
            if (num <= left.top()) {
                left.push(num);
                right.push(left.top());
                left.pop();
            }
            else {
                right.push(num);
            }
        }
    }
    
    double findMedian() {
        if (left.size() > right.size()) return left.top();
        else return (left.top() + right.top()) * 0.5;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */