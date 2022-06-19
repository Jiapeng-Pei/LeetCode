class MyLinkedList {
public:
    class node {
    public: 
        int _val;
        node* _next;
        node* _prev;
        node(int val) : _val(val) {}
    };
    int size = 0;
    node* head = nullptr;
    node* tail = nullptr;
    MyLinkedList() {
        head = new node(0);
        tail = new node(0);
        head->_next = tail;
        head->_prev = nullptr;
        tail->_prev = head;
        tail->_next = nullptr;
    }

    ~MyLinkedList() {
        if (head) {
            node* ptr = head->_next;
            node* prevPtr = ptr->_prev;
            while (ptr) {
                delete prevPtr;
                prevPtr = ptr;
                ptr = ptr->_next;
            }
            delete prevPtr;
        }
    }

    node* locateNode(int index) {
        if (index  < 0 || index >= size)
            return nullptr;
        if (index <= size / 2) {
            node* ptr = head;
            for (int i = 0; i < index + 1; i++) ptr = ptr->_next;
            return ptr;
        }
        else {
            node *ptr = tail;
            for (int i = 0; i < size - index; i++) ptr = ptr->_prev;
            return ptr;
        }    
    }
    
    int get(int index) {
        node* target = locateNode(index);
        if (target) 
            return target->_val;
        else 
            return -1;
    }
    
    void addAtHead(int val) {
        size++;
        node* cur = new node(val);
        cur->_next = head->_next;
        head->_next->_prev = cur;
        cur->_prev = head;
        head->_next = cur; 
    }
    
    void addAtTail(int val) {
        size++;
        node* cur = new node(val);
        cur->_prev = tail->_prev;
        tail->_prev->_next = cur;
        cur->_next = tail;
        tail->_prev = cur;
    }
    
    void addAtIndex(int index, int val) {
        if (index < 0 || index > size)
            return;
        if (index == size) {
            addAtTail(val);
            return;
        }
        node* nextNode = locateNode(index);
        if (nextNode) {
            size++;
            node* cur = new node(val); 
            cur->_prev = nextNode->_prev;
            nextNode->_prev->_next = cur;
            cur->_next = nextNode;
            nextNode->_prev = cur;
        }
    }
    
    void deleteAtIndex(int index) {
        if (index < 0 || index >= size)
            return;
        node* target = locateNode(index);
        if (target) {
            size--;
            target->_next->_prev = target->_prev;
            target->_prev->_next = target->_next;
            delete target; 
        }
    }
};