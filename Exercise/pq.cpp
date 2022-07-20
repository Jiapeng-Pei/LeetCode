#include <queue>
#include <vector>
#include <iostream>

using namespace std;

// 只需要记住一点，在优先队列中，默认的元素顺序为按 less 比较器的大顶堆。这也是默认情况。
// 为了方便记忆，可以简单理解为比较器的大小关系与最后弹出结果的大小方向相反。
// less的话大的先出，greater的话小的先出。
 
// 下面的struct等价于less<int>
struct cmp {
    bool operator()(const int& lhs, const int& rhs) const {
        return lhs < rhs;
    }
};

int main() {
    priority_queue<int, vector<int>, greater<int>> pq1;
    priority_queue<int, vector<int>, less<int>> pq2;
        priority_queue<int, vector<int>, cmp> pq3;

    for (int i = 1; i <= 5; i++) {
        pq1.push(i);
        pq2.push(i);
        pq3.push(i);
    }

    cout << "pq1 greater<int>: ";
    while (pq1.size()) cout << pq1.top() << " ", pq1.pop();
    cout << endl;
    cout << "pq2 less<int>: ";
    while (pq2.size()) cout << pq2.top() << " ", pq2.pop();
    cout << endl;
    cout << "pq3 cmp: ";
    while (pq3.size()) cout << pq3.top() << " ", pq3.pop();
    cout << endl;
}