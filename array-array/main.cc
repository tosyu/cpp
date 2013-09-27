#include "dynamic-array.h"
#include <iostream>

using namespace std;

int main() {

    int start[3] = {1, 2, 3};// = DynamicArray<int>();
    DynamicArray<int> arr = DynamicArray<int>(start, 3);

    int i;

    for (i = 0; i < 3; ++i) {
        cout << "index " << i << " value " << arr[i] << endl;
    }

    cout << "change the array" << endl;

    for (i = 0; i < 10; ++i) {
        arr[i] = (i + 1);
        cout << "changing index " << i << ", length is: " << arr.length() << endl;
    }

    for (i = 0; i < 3; ++i) {
        cout << "index " << i << " value " << arr[i] << endl;
    }

    cout << "remove indexes 0 and 4" << endl;
    arr.remove(0);
    arr.remove(4);

    for (i = 0; i < arr.length(); ++i) {
        cout << "index " << i << " value " << arr[i] << endl;
    }
    
    return  0;
}


