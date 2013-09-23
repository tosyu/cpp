#include <iostream>
#include <stddef.h>
#include "dynamic-array.h"

using namespace std;

int main(int argc, char **argv) {
    DynamicArray* list = new DynamicArray();
    int a = 1, b = 2, c = 3, i;

    list->add(&a);
    list->add(&b);
    list->add(&c);

    for (i = 0; i < list->length(); ++i) {
        cout << "item " << (i + 1) << ": " << *((int*) (*list)[i]) << endl;
    }

    *((int*)(*list)[1]) = 5;

    for (i = 0; i < list->length(); ++i) {
        cout << "item " << (i + 1) << ": " << *((int*) (*list)[i]) << endl;
    }

    return  0;
}
