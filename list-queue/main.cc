#include "queue.h"
#include <iostream>

using namespace std;
using namespace example;

int main() {

    Queue<int>* q = new Queue<int>();

    cout << "initial length " << q->length() << endl;

    int i, value;
    for (i = 0; i < 10; ++i) {
        value = i + 1;
        cout << "adding " << value << " to queue" << endl;
        q->enqueque(value);
    }
    cout << "queue length " << q->length() << endl;
    cout << "print and dequeue" << endl;

    while (q->length() > 0) {
        cout << "dequequed value " << q->dequeque() << endl;
    }
    cout << "queue length " << q->length() << endl;

    delete q;

    int list[] = {5, 6, 7, 8};
    q = new Queue<int>(list, 4);

    cout << "initialized new queue with values 5, 6, 7, 8" << endl;

    cout << "queue length " << q->length() << endl;
    cout << "print and dequeue" << endl;

    while (q->length() > 0) {
        cout << "dequequed value " << q->dequeque() << endl;
    }
    cout << "queue length " << q->length() << endl;

    delete q;

    return 0;
}
