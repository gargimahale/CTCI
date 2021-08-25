#include <bits/stdc++.h>
using namespace std;

#define MAX 1000

class Stack {
    int top;
public:
    int arr[MAX];
    Stack() {
        top = -1;
    }

    bool push(int x);
    int pop();
    int peek();
    bool isEmpty();
};

bool Stack::push(int x) {
    if (top >= (MAX - 1)) {
        cout << "Stack Overflow\n";
        return false;
    }
    arr[++top] = x;
    cout << x << " pushed into stack\n";
    return true;
}

int Stack::pop() {
    if (top < 0) {
        cout << "Stack Underflow";
        return 0;
    }
    int x = arr[top--];
    return x;
}

int Stack::peek() {
    if (top < 0) {
        cout << "Stack is Empty\n";
        return 0;
    }
    return arr[top];
}

bool Stack::isEmpty() {
    return top < 0;
}

int main() {
    class Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout << s.pop() << " Popped from Stack\n";
    cout << "Elements present in Stack: ";
    while (!s.isEmpty()) {
        cout << s.peek() << " ";
        s.pop();
    }
    return 0;
}