#include <list>
#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace::std;

void printList(list<int>);

int main() {
    list<int>::iterator it1, it2, it3; 
    list<int> l;
    for (int i = 1; i <= 10; i++) {
        l.push_back(i*10);
    }
    it1 = l.begin(), it2 = l.end(), it3 = it1;
    it2--;
    printList(l);
    l.push_front(1);
    cout << *it1 << endl;
    l.push_back(110);
    l.push_back(120);
    l.push_back(130);
    l.push_back(140);
    cout << *it2 << endl;
    printList(l);

    for (; it2 != l.end(); it2++) {
        cout << *it2 << " ";
    }

    cout << "before reverse: " << endl;
    printList(l);
    it1 = it2 = l.begin();
    it2++;
    it2++;
    it2++;
    it2++;
    cout << "it2: " << *it2 << endl;
    reverse(it1, it2);
    printList(l);

    // auto it4 = l.rbegin(), it5 = l.rend();
    // it4++;
    // cout << *it4 << endl;
    // reverse(it4, it5);
    // printList(l);
}

void printList(list<int> list) {
    cout << "Print elements in the list:" << endl;
    for (int i : list) {
        cout << i << " ";
    }
    cout << endl << endl;
}