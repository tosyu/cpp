#include <stddef.h>
#include <iostream>
#include "list-template.h"

using namespace std;

template <class T>
Node<T>::Node() {
    next = NULL;
    prev = NULL;
}

template <class T>
Node<T>::Node(T* nodeData) {
    data = nodeData;
}

template <class T>
LinkedList<T>::LinkedList() {
    current = NULL;
    head = NULL;
    tail = NULL;
    items = 0;
}

template <class T>
LinkedList<T>::~LinkedList() {
    clear();
}

template <class T>
Node<T>* LinkedList<T>::add(T* data) {
    Node<T>* node = new Node<T>(data);

    if (head == NULL) {
        head = node;
    }

    if (current == NULL) {
        current = node;
    }

    if (tail != NULL) {
        tail->next = node;
        node->prev = tail;
    }
    
    tail = node;
    ++items;
    return node;
}

template <class T>
bool LinkedList<T>::remove(T* data) {
    Node<T>* node = head;
    while (node != NULL) {
        if (*node->data == *data) {
            if (node->prev != NULL) {
                if (node->next != NULL) {
                    node->next->prev = node->prev;
                } else {
                    node->prev = NULL;
                }
            } else {
                head = node->next;
            }

            if (node->next != NULL) {
                if (node->prev != NULL) {
                    node->prev->next = node->next;
                } else {
                    node->next = NULL;
                }
            } else {
                tail = node;
            }

            if (current == node) {
                current = head;
            }

            delete node;
            --items;

            return true;
        }
        node = node->next;
    }
    return false;
}

template <class T>
void LinkedList<T>::rewind() {
    current = head;
}

template <class T>
T LinkedList<T>::next() {
    Node<T>* node = current;
    if (node->next != NULL) {
        current = node->next;
    }
    return *node->data;
}

template <class T>
T LinkedList<T>::prev() {
    Node<T>* node = current;
    if (node->prev != NULL) {
        current = node->prev;
    }
    return *node->data;
}

template <class T>
int LinkedList<T>::length() {
    return items;
}

template <class T>
void LinkedList<T>::clear() {
    Node<T>* node = head;
    Node<T>* tmp;
    while (node != NULL) {
        tmp = node->next;
        delete node;
        node = tmp;
    }
    current = NULL;
    head = NULL;
    tail = NULL;
    items = 0;
}

//excplicit
template class Node<int>;
template class LinkedList<int>;
