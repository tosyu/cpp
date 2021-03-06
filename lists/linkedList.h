#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_

class ListItem {
    public:
        void* data;
        ListItem* next;
        ListItem* prev;
        ListItem();
};

class LinkedList {
    private:
        ListItem * current;
        ListItem * head;
        ListItem * tail;
        int items;
    public:
        LinkedList();
        ~LinkedList();
        void add(void *);
        void remove(ListItem *);
        void remove(void *);
        void clear(void);
        ListItem * nextItem(void);
        ListItem * prevItem(void);
        void rewind(void);
        int length(void);
};

#endif
