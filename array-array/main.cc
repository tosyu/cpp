#include "dynamic-array.h"
#include <iostream>

using namespace std;

int main() {

    DynamicArray<int>* a = new DynamicArray<int>();
    int i;

    (*a)[0] = 1;
    (*a)[1] = 2;
    (*a)[2] = 3;
   
    for (i = 0; i < a->length(); ++i) {
        //cout << "item " << i << " :" << (string) a[i] << endl;
    }
    

    return  0;
}

