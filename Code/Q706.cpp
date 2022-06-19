#include <vector>
#include <stdio.h>
#include <iostream>

using namespace::std;

class Node {
public:
    int key;
    int value;
    Node* next;

    Node (int _key, int _value) : key(_key), value(_value), next(nullptr) {}
};

class MyHashMap {
public:
    int size = 10713;
    vector<Node*> array; 

    MyHashMap() {
        array = vector<Node*>(size, nullptr);
    }
    
    void put(int key, int value) {
        int pos = key % size;
        if (array[pos]) {
            Node* ptr = array[pos];
            for (; ptr->next; ptr = ptr->next) {
                if (ptr->key == key) break;
            }
            // 1. ptr.key == key; 2. ptr move to the last pointer.
            if (ptr->key == key) {
                ptr->value = value;
            }
            else {
                ptr->next = new Node(key, value);
            }
        }
        else {
            array[pos] = new Node(key, value);;
        }
    }
    
    int get(int key) {
        int pos = key % size;
        if (!array[pos]) return -1;
        for (Node* ptr = array[pos]; ptr; ptr = ptr->next) {
            if (ptr->key == key) return ptr->value;
        }
        return -1;
    }
    
    void remove(int key) {
        int pos = key % size;
        if (!array[pos]) return;
        Node tmp(-1, -1);
        Node* dummy = &tmp;
        dummy->next = array[pos];
        for (;dummy->next; dummy = dummy->next) {
            if (dummy->next->key == key) break; 
        }
        if (!dummy->next) return;
        if (dummy->next == array[pos]) {
            Node* head = array[pos];
            array[pos] = array[pos]->next;
            delete head;
        }
        else {
            Node* del = dummy->next;
            dummy->next = dummy->next->next;
            delete del;
        }
    }
};
/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */

// 怎么删除呢？我想想...如果找到key，那么说明能删。可以先找key，找不到直接返回。
// 如果对应找到的元素是第一个元素，好删；如果找到的元素不是第一个元素，那么就需要找到他之前的一个元素。

int main() {
    MyHashMap map;
    map.put(1, 1);
    map.put(2, 2);
    map.put(2, 1);
    cout << map.get(2) << endl;
    map.remove(2);
    map.get(2);
}