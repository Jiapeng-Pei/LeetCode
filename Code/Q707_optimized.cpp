using namespace std;

class node {
public:
    int val;
    node* next;
    node(int val) {
        this->val = val;
        next = nullptr;
    }
};

class MyLinkedList {
public:
    node* head;
    node* tail;
    int size;
    MyLinkedList() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    node* getNode(int index) {
        node* cur = head;
        for (int i = 0; i < index; i++) cur = cur->next;
        return cur;
    }
    
    int get(int index) {
        if (index >= size || index < 0) return -1;
        return getNode(index)->val;
    }
    
    void addAtHead(int val) {
        if (!head) {
            head = tail = new node(val);
        }
        else {
            node* tmp = new node(val);
            tmp->next = head;
            head = tmp;
        }
        size++;
    }
    
    void addAtTail(int val) {
        if (!tail) {
            head = tail = new node(val);
        }
        else {
            tail->next = new node(val);
            tail = tail->next;
        }
        size++;
    }
    
    void addAtIndex(int index, int val) {
        if (index < 0 || index > size) return;
        if (index == 0) {
            addAtHead(val);
        }
        else if (index == size) { 
            addAtTail(val);
        }
        else {
            node* target = new node(val);
            node* pre = getNode(index - 1);
            target->next = pre->next;
            pre->next = target;
            size++;
        }
    }
    
    void deleteAtIndex(int index) {
        if (index < 0 || index >= size) return;
        if (index == 0) {
            if (size == 1) head = tail = nullptr;
            else head = head->next;
        } 
        else {
            node* pre = getNode(index - 1);
            if (pre->next == tail) tail = pre;
            pre->next = pre->next->next;
        }

        size--;
    }
};
