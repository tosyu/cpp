#include <iostream>
#include <stddef.h>
#include "linkedList.h"

using namespace std;

int main(int argc, char **argv) {
    LinkedList list = LinkedList();
    ListItem * item;
    int i, a = 5, b = 6, c = 7;

    list.add(&a);
    list.add(&b);
    list.add(&c);

    while ((item = list.nextItem()) != NULL) {
        cout << "item " << item->content << endl;
    }

    return  0;
}
