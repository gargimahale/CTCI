#include <bits/stdc++.h>
using namespace std;

class Queue {
public:
    int front, back, size;
    unsigned cap;
    int *arr;
};

Queue* createQueue(unsigned cap) {
    Queue* Q = new Queue();
    Q->cap = cap;
    Q->front = Q->size = 0;

    Q->back = cap - 1;
    Q->arr = new int[Q->cap];
    return Q;
}

bool isFull(Queue* Q) {
    return (Q->size == Q->cap);
}

bool isEmpty(Queue* Q) {
    return (Q->size == 0);
}

void enQueue(Queue* Q, int x) {
    if (isFull(Q)) {
        cout << "Queue Full\n";
        return;
    }

    Q->back = (Q->back + 1) % Q->cap;
    Q->arr[Q->back] = x;
    Q->size = Q->size + 1;
    cout << x << " enqueued to queue\n";
}

int deQueue(Queue* Q) {
    if (isEmpty(Q))
        return INT_MIN;

    int x = Q->arr[Q->front];
    Q->front = (Q->front + 1) % Q->cap;
    Q->size = Q->size - 1;
    return x;
}

int front(Queue* Q) {
    if (isEmpty(Q))
        return INT_MIN;
    return Q->arr[Q->front];
}

int rear(Queue* Q) {
    if (isEmpty(Q))
        return INT_MIN;
    return Q->arr[Q->back];
}

int main() {
    Queue* Q = createQueue(1000);
    enQueue(Q, 10);
    enQueue(Q, 20);
    enQueue(Q, 30);
    enQueue(Q, 40);
    enQueue(Q, 50);
    cout << deQueue(Q) << " dequeued from Queue\n";
    cout << "Front item is " << front(Q) << "\n";
    cout << "Rear item is " << rear(Q) << "\n";
    return 0;
}