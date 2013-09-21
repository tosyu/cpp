#include "linkedList.h"
#include <stddef.h>

LinkedList::LinkedList() {
    items = 0;
}

LinkedList::~LinkedList() {
    clear();
}

void LinkedList::add(void * content) {
    ListItem item;

    if (first == NULL) {
        first = &item;
    }

    if (current == NULL) {
        current = &item;
    }

    item.content = content;
    ++items;

    last = &item;
}

void LinkedList::remove(ListItem * item) {
    --items;
}

void LinkedList::clear() {
    items = 0;
}

int LinkedList::length() {
    return items;
}

void LinkedList::rewind() {
    current = first;
}

ListItem * LinkedList::nextItem() {
    if (current != NULL) {
        current = current->next;
    }
    return current;
}

ListItem * LinkedList::prevItem() {
    if (current != NULL) {
        current = current->prev;
    }
    return current;
}


