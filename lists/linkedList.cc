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
    last = NULL;
    first = NULL;
    items = 0;
}

LinkedList::~LinkedList() {
    clear();
}

void LinkedList::add(void * data) {
    ListItem* item = new ListItem();

    item->data = data;
    if (first == NULL) {
        first = item;
    }

    if (current == NULL) {
        current = item;
    }

    if (last != NULL) {
        last->next = item;
        item->prev = last;
    }
    
    last = item;
    ++items;
}

void LinkedList::remove(ListItem* item) {
    ListItem* cr = first;
    while (cr != NULL) {
        if (cr == item) {
            if (cr->prev != NULL) {
                if (cr->next != NULL) {
                    cr->next->prev = cr->prev;
                }
            } else {
                first = cr->next;
            }

            if (cr->next != NULL) {
                if (cr->prev != NULL) {
                    cr->prev->next = cr->next;
                }
            } else {
                last = cr->prev;
            }

            --items;
            delete cr;
            break;
        }
        cr = cr->next;
    }
}

void LinkedList::remove(void* data) {
    ListItem* cr = first;
    while (cr != NULL) {
        if (cr->data == data) {
            remove(cr);
            break;
        }
        cr = cr->next;
    }
}

void LinkedList::clear() {
    ListItem* cr = first;
    ListItem* tmp;
    while (cr != NULL) {
        tmp = cr->next;
        delete cr;
        cr = tmp;
    }
    current = NULL;
    first = NULL;
    last = NULL;
    items = 0;
}

int LinkedList::length() {
    return items;
}

void LinkedList::rewind() {
    current = first;
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


