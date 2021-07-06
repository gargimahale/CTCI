#include <bits/stdc++.h>
using namespace std;

class MinStack {
public:
	/** initialize your data structure here. */
	vector<int> stk, min_stk;
	MinStack() {
		stk.clear();
		min_stk.clear();
	}

	void push(int val) {
		if (stk.size() > 0) {
			if (min_stk[min_stk.size() - 1] > val) {
				min_stk.push_back(val);
			}
			else {
				min_stk.push_back(min_stk[min_stk.size() - 1]);
			}
		}
		else {
			min_stk.push_back(val);
		}
		stk.push_back(val);
	}

	void pop() {
		min_stk.pop_back();
		stk.pop_back();
	}

	int top() {
		return stk[stk.size() - 1];
	}

	int getMin() {
		return min_stk[min_stk.size() - 1];
	}
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */