#include <iostream>
#include "insertion-sort-2.h"

using namespace std;

int compareIntegers(const void *a, const void *b) {
    if (*((int *) a) >= *((int *) b)) {
        return 1;
    }
    return 0;
}

int main(int, char**) {

    int data[] = {55, 23, 0, 23, 0, 2, 45, 22, 1, 10, 19};
    int length = 11;
    int i;

    cout << "dump starting array\n";
    for (i = 0; i < length; ++i) {
        cout << "data[" << i << "] = " << data[i] << "\n";
    }

    cout << "sorting\n";
    issort2(&data, length, sizeof(int), &compareIntegers);

    cout << "dump after sort\n";
    for (i = 0; i < length; ++i) {
        cout << "data[" << i << "] = " << data[i] << "\n";
    }
    
    cout << endl;
    return 0;
}
