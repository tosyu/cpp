#include "hash-table.h"
#include <iostream>

using namespace std;
using namespace example;

int main() {
    HashTable<int>* h = new HashTable<int>(4);

    cout << "hash table size is " << h->size() << endl;
    cout << "hash table length is " << h->length() << endl;

    cout << "adding few keys/values" << endl;
    h->set("test1", 12);
    h->set("test2", 22);
    h->set("test3", 34);
    h->set("test4", 56);
    h->set("test5", 88);
    h->set("test6", 82);

    cout << "hash table size is " << h->size() << endl;
    cout << "hash table length is " << h->length() << endl;
    
    cout << "test1 " << h->get("test1") << endl;
    cout << "test2 " << h->get("test2") << endl;
    cout << "test3 " << h->get("test3") << endl;
    cout << "test4 " << h->get("test4") << endl;
    cout << "test5 " << h->get("test5") << endl;
    cout << "test6 " << h->get("test6") << endl;

    cout << "removing test1 and test2" << endl;

    h->remove("test1");
    h->remove("test2");

    cout << "hash table size is " << h->size() << endl;
    cout << "hash table length is " << h->length() << endl;
    
    cout << "test1 " << h->get("test1") << endl;
    cout << "test2 " << h->get("test2") << endl;
    cout << "test3 " << h->get("test3") << endl;
    cout << "test4 " << h->get("test4") << endl;
    cout << "test5 " << h->get("test5") << endl;
    cout << "test6 " << h->get("test6") << endl;
    
    return  0;
}
