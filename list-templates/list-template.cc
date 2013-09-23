#include <stddef.h>
#include "list-template.h"

template <class T>
Node<T>::Node() {
    next = NULL;
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
Node<T>* LinkedList<T>::add(T data) {
    Node<T>* node = new Node<T>(&data);

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
bool LinkedList<T>::remove(T data) {
    // @TODO implementation
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
    return node->data;
}

template <class T>
T LinkedList<T>::prev() {
    Node<T>* node = current;
    if (node->prev != NULL) {
        current = node->prev;
    }
    return node->data;
}

template <class T>
int LinkedList<T>::length() {
    return items;
}

template <class T>
void LinkedList<T>::clear() {
    //@TODO implementation
}

