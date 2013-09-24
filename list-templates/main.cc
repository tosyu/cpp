#include <iostream>
#include <stddef.h>

#include "list-template.h"

using namespace std;

int main(int argc, char **argv) {
    LinkedList<int>* list = new LinkedList<int>();
    int i, a = 5, b = 6, c = 7;

    list->add(a);
    list->add(b);
    list->add(c);

    for (i = 0; i < list->length(); ++i) {
        cout << "item " << (i + 1) << ": " << list->next() << endl;
    }

    return 0;
}
