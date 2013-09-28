#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <stddef.h>

namespace example {

    template <class T>
    class Node {
        public:
            T data;
            Node<T>* prev;
            Node() {
                prev = NULL;
            }
    };

    template <class T>
    class Queue {
        private:
            Node<T>* head;
            Node<T>* tail;
            int items;
        public:
            Queue() {
                head = NULL;
                tail = NULL;
                items = 0;
            };
            
            Queue(T* data, int dataLength) {
                head = NULL;
                tail = NULL;
                items = 0;
                int i;
                for (i = 0; i < dataLength; ++i) {
                    enqueque(data[i]);
                }
            };

            ~Queue() {
                Node<T>* node = tail;
                Node<T>* tmp;
                while (node != NULL) {
                    tmp = node->prev;
                    delete node;
                    node = tmp;
                }
                items = 0;
            };

            Node<T>* enqueque(const T data) {
                Node<T>* node = new Node<T>();
                node->data = data;                
                
                if (head != NULL) {
                    head->prev = node;
                    head = node;
                }
               
                if (tail == NULL && head == NULL) {
                    tail = head = node;
                }
                ++items;

                return node;
            };

            const T dequeque(void) {
                const T data = tail->data;
                if (tail->prev != NULL) {
                    tail = tail->prev;
                }
                --items;
                return data;
            };

            int length(void) {
                return items;
            };
    };

}

#endif
