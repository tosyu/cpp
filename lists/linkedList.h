#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_

struct ListItem {
    void * content;
    ListItem * next;
    ListItem * prev;
};

class LinkedList {
    private:
        ListItem * current;
        ListItem * first;
        ListItem * last;
        int items;
    public:
        LinkedList();
        ~LinkedList();
        void add(void *);
        void remove(ListItem *);
        void clear(void);
        ListItem * nextItem(void);
        ListItem * prevItem(void);
        void rewind(void);
        int length(void);
};

#endif
