#include <string.h>
#include <stddef.h>
#include "insertion-sort-2.h"

void issort2(void *data, int size, int elementSize, int (*compareFunction)(const void*, const void*)) {

    char *source = (char *) data;
    void *tmp = new char;
    int i;
    int j;

    for (j = 1; j < size; ++j) {
        memcpy(tmp, &source[j * elementSize], elementSize);
        i = j - 1;
        while (i >= 0 && compareFunction(&source[i * elementSize], tmp) > 0) {
            memcpy(&source[(i + 1) * elementSize], &source[i*elementSize], elementSize);
            --i;
        }
        memcpy(&source[(i + 1) * elementSize], tmp, elementSize);
    }

    memset(tmp, 0, elementSize);
}
