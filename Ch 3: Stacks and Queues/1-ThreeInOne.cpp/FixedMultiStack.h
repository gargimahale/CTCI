#include <bits/stdc++.h>
using namespace std;

class FixedMultiStack {
public:
    FixedMultiStack(int stackCap);
    virtual ~FixedMultiStack();

    void push(int stackIdx, int val);
    void pop(int stackIdx);

    int top(int stackIdx) const;
    bool isEmpty(int stackIdx) const;
    bool isFull(int stackIdx) const;

private:
    int numOfStack = 3;
    int stackCap;
    int *stackArr;
    int *stackCapUsed;

    int indexOfTop(int stackIdx) const;
};