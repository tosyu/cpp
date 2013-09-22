#include "linkedList.h"
#include <stddef.h>
#include <iostream>
using namespace std;

ListItem::ListItem() {
    data = NULL;
    next = NULL;
    prev = NULL;
}

LinkedList::LinkedList() {
    current = NULL;
    tail = NULL;
    head = NULL;
    items = 0;
}

LinkedList::~LinkedList() {
    clear();
}

void LinkedList::add(void * data) {
    ListItem* item = new ListItem();

    item->data = data;
    if (head == NULL) {
        head = item;
    }

    if (current == NULL) {
        current = item;
    }

    if (tail != NULL) {
        tail->next = item;
        item->prev = tail;
    }
    
    tail = item;
    ++items;
}

void LinkedList::remove(ListItem* item) {
    ListItem* cr = head;
    while (cr != NULL) {
        if (cr == item) {
            if (cr->prev != NULL) {
                if (cr->next != NULL) {
                    cr->next->prev = cr->prev;
                }
            } else {
                head = cr->next;
            }

            if (cr->next != NULL) {
                if (cr->prev != NULL) {
                    cr->prev->next = cr->next;
                }
            } else {
                tail = cr->prev;
            }

            --items;
            delete cr;
            break;
        }
        cr = cr->next;
    }
}

void LinkedList::remove(void* data) {
    ListItem* cr = head;
    while (cr != NULL) {
        if (cr->data == data) {
            remove(cr);
            break;
        }
        cr = cr->next;
    }
}

void LinkedList::clear() {
    ListItem* cr = head;
    ListItem* tmp;
    while (cr != NULL) {
        tmp = cr->next;
        delete cr;
        cr = tmp;
    }
    current = NULL;
    head = NULL;
    tail = NULL;
    items = 0;
}

int LinkedList::length() {
    return items;
}

void LinkedList::rewind() {
    current = head;
}

ListItem * LinkedList::nextItem() {
    ListItem* item = current;
    if (current != NULL) {
        current = current->next;
    }
    return item;
}

ListItem * LinkedList::prevItem() {
    ListItem* item = current;
    if (current != NULL) {
        current = current->prev;
    }
    return item;
}


