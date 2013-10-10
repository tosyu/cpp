#include "quick-sort.h"
#include <cstring>
#include <cstdlib>
#include <cstddef>
#include <ctime>

int partition(void *data, int l, int r, int elementSize, int (*compareFunction)(const void*, const void*)) {
    srand(time(NULL));
    int pivotIndex = rand() % (r - l) + l;
    char *source = (char *) data;
    void *tmp = new char;

    memcpy(tmp, &source[r * elementSize], elementSize);
    memcpy(&source[r * elementSize], &source[pivotIndex * elementSize], elementSize);
    memcpy(&source[pivotIndex * elementSize], tmp, elementSize);

    int i;
    int x = l;
    for (i = l; i < r; ++i) {
        if (compareFunction(&source[i * elementSize], &source[r * elementSize]) == -1) {
            memcpy(tmp, &source[x * elementSize], elementSize);
            memcpy(&source[x * elementSize], &source[i * elementSize], elementSize);
            memcpy(&source[i * elementSize], tmp, elementSize);
            ++x;
        }
    }
    
    memcpy(tmp, &source[x * elementSize], elementSize);
    memcpy(&source[x * elementSize], &source[r * elementSize], elementSize);
    memcpy(&source[r * elementSize], tmp, elementSize);
    memset(tmp, 0, elementSize);
    
    return x;
}

void quicksort(void *data, int l, int r, int elementSize, int (*compareFunction)(const void*, const void*)) {
    if (l < r) {
        int i = partition(data, l, r, elementSize, compareFunction);
        quicksort(data, l, i - 1, elementSize, compareFunction);
        quicksort(data, i + 1, r, elementSize, compareFunction);
    }
}

