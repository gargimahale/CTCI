#include <bits/stdc++.h>
using namespace std;

/*
Write a program to sort a stack such that the smallest items are on the top.
You can use an additional temporary stack, but you may not copy the elements into
any other data structure (such as an array). The stack supports the following
operations: push, pop, peek, and is Empty.
 */


void sortStack(stack<int> *st) {
    stack<int> sorted; //top contains largest element, an additional temporary stack
    while (!(*st).empty()) {
        int tmp = (*st).top();
        (*st).pop();
        while (!sorted.empty() && tmp < sorted.top()) {
            (*st).push(sorted.top());
            sorted.pop();
        }
        sorted.push(tmp);
    }
    while (!sorted.empty()) {
        (*st).push(sorted.top()); //this step reverse the sorted order to original stack
        sorted.pop();
    }
}

int main() {
    stack<int> mystack;
    int arr[] = {6, 4, 8, 9, 10, 99, 7, 1, 100};
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
        cout << "Push in element " << arr[i] << endl;
        mystack.push(arr[i]);
    }
    sortStack(&mystack);
    cout << "The sorted stack is: " << endl;
    while (!mystack.empty()) {
        cout << mystack.top() << '\n';
        mystack.pop();
    }
}