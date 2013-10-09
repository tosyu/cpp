#include <iostream>

using namespace std;

int compareIntegers(const int, const int);

void issort(int*, int, int (*)(const int, const int));

int main(int, char**) {
    int data[] = {15, 0, 30, 45, 0, 33, 0, 0, 1, 33};


    int i;
    for (i = 0; i < 10; ++i) {
        cout << "number " << data[i] << " at index " << i << endl;
    }

    cout << "sorting" << endl;

    issort(data, 10, &compareIntegers);

    for (i = 0; i < 10; ++i) {
        cout << "number " << data[i] << " at index " << i << endl;
    }

    return 0;
}

int compareIntegers(const int a, const int b) {
    if (a < b) {
        return -1;
    }

    return 1;
}

void issort(int* data, int length, int (*compare)(const int, const int)) {
    int j;
    int i;
    int tmp;
    for (j = 0; j < length; ++j) {
        tmp = data[j];
        i = j - 1;
        while (i >= 0 && compare(data[i], tmp) > 0) {
            data[i + 1] = data[i];
            --i;
        }
        data[i + 1] = tmp;
    }
}

