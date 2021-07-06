#include <bits/stdc++.h>
using namespace std;


/*EnQueue(x)
  1) Push x to stack1 (assuming size of stacks is unlimited).

  DeQueue(x)
  1) If both stacks are empty then error.
  2) If stack2 is empty
       While stack1 is not empty, push everything from stack1 to stack2.
  3) Pop the element from stack2 and return it.
*/

class Queue {
private:
    stack<int> stack1, stack2;
public:
    void EnQueue(int data) {
        stack1.push(data);
    }
    int DeQueue() {
        if (stack1.empty() && stack2.empty()) {
            printf("Queue is empty!");
            getchar();
            exit(0);
        }
        if (stack2.empty()) {
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        int temp = stack2.top();
        stack2.pop();
        return temp;
    }
    int size() {
        return stack1.size() + stack2.size();
    }

};

int main(void) {
    Queue q;
    for (int i = 0; i < 10; i++) {
        cout << "EnQueue :" << i << '\n';
        q.EnQueue(i);
    }
    cout << "DeQueue :" << q.DeQueue() << '\n';
    cout << "DeQueue :" << q.DeQueue() << '\n';
    for (int i = 10; i < 20; i++) {
        cout << "EnQueue :" << i << '\n';
        q.EnQueue(i);
    }
    cout << "DeQueue :" << q.DeQueue() << '\n';
    cout << "DeQueue :" << q.DeQueue() << '\n';
}