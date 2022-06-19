#include "stdio.h"
#include <list>
#include <queue>

using namespace std;

class MyStack {
public:
    queue<int> que;
    
    MyStack() {  
    }
    
    void push(int x) {
        que.push(x);
        for (int i = 0; i < que.size() - 1; ++i) {
            que.push(que.front());
            que.pop();
        }
    }
    
    int pop() {
        int ret = que.front();
        que.pop();
        return ret;
    }
    
    int top() {
        return que.front();
    }
    
    bool empty() {
        return !que.size();
    }
};