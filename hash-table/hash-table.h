#ifndef _HASH_TABLE_H_
#define _HASH_TABLE_H_

#include <stddef.h>

namespace example {
    template <class T>
    struct Node {
        T data;
        const char* key;
        Node* next;
    };

    int compareKeys(const char* a, const char* b) {
        int res = 0;
        while(*a && *b) {
            if (*a != *b && res == 0) {
                res = -1;
                break;
            }
            ++a;
            ++b;
        }

        // check for same length after the loop
        if ((*a && !*b) || (!*a && *b)) {
            res = -1;
        }

        return res;
    }

    int hash(const char* key, int hashTableSize) {
        int res = 0;

        while (*key) {
            res += *key;
            ++key;
        }

        return res % hashTableSize;
    }

    template <class T>
    class HashTable {
        private:
            int tableSize;
            int items;
            struct Node<T>** table;
        public:
            HashTable() {
                tableSize = 1024;
                table = new Node<T>*[tableSize];
                items = 0;
            };

            HashTable(int size) {
                tableSize = size;
                items = 0;
                table = new Node<T>*[tableSize];
            };

            ~HashTable() {
                clear();
            };

            void set(const char* key, T value) {
                int index = hash(key, tableSize);
                Node<T>* node = table[index];
                int compareResult;
              
                if (node != NULL) {
                    while (node->next != NULL) {
                        compareResult = compareKeys(key, node->key);
                        if (compareResult == 0) {
                            break;
                        }
                        node = node->next;
                    }

                    if (compareResult == 0) {
                        node->data = value;
                    } else {
                        Node<T>* newNode = new Node<T>[1];
                        newNode->data = value;
                        newNode->key = key;
                        node->next = newNode;
                    }
                } else {
                    table[index] = new Node<T>[1];
                    table[index]->data = value;
                    table[index]->next = NULL;                
                    table[index]->key = key;
                }

                ++items;
            };

            T get(const char *key) {
                int index = hash(key, tableSize);
                Node<T>* node = table[index];

                while (node != NULL) {
                    if (compareKeys(key, node->key) == 0) {
                        return node->data;
                    }
                    node = node->next;
                }

                return (T) 0;
            };

            int size(void) {
                return tableSize;
            };

            int length(void) {
                return items;
            };

            bool remove(const char *key) {
                int index = hash(key, tableSize);
                Node<T>* node = table[index];
                Node<T>* prevNode;

                while (node->next != NULL) {
                    if (compareKeys(key, node->key) == 0) {
                        break;
                    }
                    prevNode = node;
                    node = node->next;
                }

                if (node != NULL) {
                    if (node == table[index]) {
                        table[index] = node->next;
                    } else {
                        prevNode->next = node->next;                        
                    }
                   
                    delete node;
                    --items;
                    return true;
                }

                return false;
            };

            void clear(void) {
                int i;
                Node<T>* tmp;
                Node<T>* node;
                for (i = 0; i < tableSize; ++i) {
                    node = table[i];
                    while (node != NULL) {
                        tmp = node->next;
                        delete node;
                        node = tmp;
                    }
                }
                delete[] table;
                items = 0;
            };
    };

}

#endif
