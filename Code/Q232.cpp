#include "list"

using namespace ::std;

class MyQueue
{
public:
    list<int> in;
    list<int> out;

    MyQueue()
    {
    }

    void push(int x)
    {
        in.push_back(x);
    }

    int pop()
    {
        int ret = peek();
        out.pop_back();
        return ret;
    }

    int peek()
    {   
        if (out.empty()) {
            while (in.size()) {
                out.push_back(in.back());
                in.pop_back();
            }
        }
        return out.back();
    }

    bool empty()
    {
        return !in.size() && !out.size();
    }
};