#ifndef _DYNAMIC_ARRAY_H_
#define _DYNAMIC_ARRAY_H_

class Node {
    public:
        void* data;
        Node* next;
        Node* prev;
        Node();
};

class DynamicArray {
    private:
        Node* head;
        Node* tail;
        int items;
    public:
        DynamicArray();
        ~DynamicArray();
        void add(void*);
        void remove(Node*);
        void remove(void*);
        void clear(void);
        int length(void);
        void* operator [] (int);
};

#endif
