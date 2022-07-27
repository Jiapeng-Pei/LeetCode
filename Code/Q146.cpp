#include <stdio.h>
#include <list>
#include <iostream>
#include <unordered_map>

using namespace ::std;

class LRUCache
{
public:
    list<pair<int, int>> myList;
    unordered_map<int, list<pair<int, int>>::iterator> myMap;  
    int capacity;

    LRUCache(int capacity)
    {
        this->capacity = capacity;
    }

    int get(int key)
    {
        if (!myMap.count(key)) return -1;

        auto it = myMap[key];
        // The first argument specifies the position where the elements are to be transferred.
        // The second argument specifies the elements to be transferred.
        // The third element (and 4th) argement specifies the start (and end) of elements to be transferred. 
        myList.splice(myList.begin(), myList, it);
        return it->second;
    }

    void put(int key, int value)
    {
        if (myMap.count(key)) {
            auto it = myMap[key];
            // the first parameter is the position to add new element, the second and third element denotes elements to be added.
            myList.splice(myList.begin(), myList, it);
            it->second = value;
            return;
        }

        if (myList.size() == capacity) popLast();
        myList.push_front({key, value});
        myMap.insert({key, myList.begin()});
    }

    void popLast() {
        int key = myList.back().first;
        myList.pop_back();
        myMap.erase(key);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */