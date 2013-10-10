#include <iostream>
#include "quick-sort.h"

using namespace std;

int compareIntegers(const void *a, const void *b) {
    if (*(const int*) a > *(const int*) b) {
        return 1;
    } else if (*(const int*) a < *(const int*) b) {
        return -1;
    }
    return 0;
}

int main(int, char**) {
    int data[] = {10, 25, 44, 100, 0, 3, -1, 200, 3, 34, 6, 8};
    int length = 12;
    int i;

    cout << "dump initial\n";
    for (i = 0; i < length; ++i) {
        cout << "data[" << i << "] = " << data[i] << "\n";
    }
    
    cout << "sorting\n";
    quicksort(&data, 0, length - 1, sizeof(int), &compareIntegers);

    cout << "dump sorted\n";
    for (i = 0; i < length; ++i) {
        cout << "data[" << i << "] = " << data[i] << "\n";
    }

    cout << endl;
    return 0;
}
