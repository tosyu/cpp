#include "dynamic-array.h"
#include <iostream>

using namespace std;

int main() {

    DynamicArray<int> arr = DynamicArray<int>();

    int i;

    cout << "printing the array, length " << arr.length() << endl;
    
    for (i = 0; i < arr.length(); ++i) {
        cout << "index " << i << " value " << arr[i] << endl;
    }

    cout << "change the array" << endl;

    for (i = 0; i < 10; ++i) {
        arr[i] = (i + 1);
        cout << "changing index " << i << " to value " << arr[i] << " length is: " << arr.length() << endl;
    }

    cout << "printing the array, length " << arr.length() << endl;

    for (i = 0; i < arr.length(); ++i) {
        cout << "index " << i << " value " << arr[i] << endl;
    }

    cout << "remove indexes 0 and 4" << endl;
    arr.remove(0);
    arr.remove(4);

    cout << "printing the array, length " << arr.length() << endl;
    
    for (i = 0; i < arr.length(); ++i) {
        cout << "index " << i << " value " << arr[i] << endl;
    }
    
    return  0;
}


