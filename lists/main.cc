#include <iostream>
#include <stddef.h>
#include "linkedList.h"

using namespace std;

void dumpList(LinkedList* list) {
    ListItem * item;
    cout << "dumping total items: " << list->length() << endl;
    while ((item = list->nextItem()) != NULL) {
        cout << "item " << *((int *) item->data) << endl;
    }
}

int main(int argc, char **argv) {
    LinkedList* list = new LinkedList();
    int i, a = 5, b = 6, c = 7;

    list->add(&a);
    list->add(&b);
    list->add(&c);

    list->rewind();

    dumpList(list);

    list->remove(&b);
    list->rewind();

    dumpList(list);

    list->clear();
    list->rewind();

    dumpList(list);

    delete list;

    return  0;
}
