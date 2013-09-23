#include "dynamic-array.h"
#include <stddef.h>
#include <iostream>
using namespace std;

Node::Node() {
    data = NULL;
    next = NULL;
    prev = NULL;
}

DynamicArray::DynamicArray() {
    tail = NULL;
    head = NULL;
    items = 0;
}

DynamicArray::~DynamicArray() {
    clear();
}

void DynamicArray::add(void * data) {
    Node* item = new Node();

    item->data = data;
    if (head == NULL) {
        head = item;
    }

    if (tail != NULL) {
        tail->next = item;
        item->prev = tail;
    }
    
    tail = item;
    ++items;
}

void DynamicArray::remove(Node* item) {
    Node* cr = head;
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

void DynamicArray::remove(void* data) {
    Node* cr = head;
    while (cr != NULL) {
        if (cr->data == data) {
            remove(cr);
            break;
        }
        cr = cr->next;
    }
}

void DynamicArray::clear() {
    Node* cr = head;
    Node* tmp;
    while (cr != NULL) {
        tmp = cr->next;
        delete cr;
        cr = tmp;
    }
    head = NULL;
    tail = NULL;
    items = 0;
}

int DynamicArray::length() {
    return items;
}

void* DynamicArray::operator[] (int index) {
    Node *item = head;
    int currentIndex = 0;
    if (index >= items) {
        return NULL;
    }

    while (item != NULL) {
        if (currentIndex == index) {
            return item->data;
        }
        item = item->next;
        ++currentIndex;
    }

    return NULL;
}

