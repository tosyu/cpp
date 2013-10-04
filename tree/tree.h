#ifndef _TREE_H_
#define _TREE_H_

#include <stddef.h>

namespace example {

    const int PRE_ORDER_TR = 0;
    const int POST_ORDER_TR = 1;
    const int IN_ORDER_TR = 2;

    template <class T>
    int basicCompare(const T a, const T b) {
        if (a > b) {
            return 1;
        }
        
        if (a < b) {
            return -a;
        }

        return 0;
    };

    template <class T>
    struct Node {
        T data;
        Node<T>* left;
        Node<T>* right;
        Node<T>* parent;
        public:
            Node()
                : data()
                , left(NULL)
                , right(NULL) {};
    };

    template <class T>
    class Tree {
        private:
            Node<T>* root;
            int itemsNumber;
            T* iteratorPtr;
            int (*compare)(const T, const T);
        public:
            Tree()
                : root(NULL)
                , iteratorPtr(NULL)
                , itemsNumber() {};
            
            Tree(int (*compareFunction)(const T, const T))
                : root(NULL)
                , iteratorPtr(NULL)
                , itemsNumber() {
                compare = compareFunction;
            };

            ~Tree() {
                clear();
            };

            void clear(void);

            Node<T>* add(T item);

            bool remove(T item);

            bool remove(Node<T>* item);

            T* iterator(void);

            void traverse(int order, void (*traverseCallback)(const T));
    };

} // namespace example

#endif
