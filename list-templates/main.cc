#include <iostream>
#include <stddef.h>

#include "list-template.h"

using namespace std;

int main(int argc, char **argv) {
    LinkedList<int>* list = new LinkedList<int>();
    int i;

    list->add(1);
    list->add(2);
    list->add(3);

    for (i = 0; i < list->length(); ++i) {
        cout << "item " << (i + 1) << ": " << list->next() << endl;
    }

    return 0;
}
