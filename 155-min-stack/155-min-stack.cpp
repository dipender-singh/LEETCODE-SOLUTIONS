class MinStack {
public:
    //Deque, Queue, Stack can be used here because all the function of push and pop uses O(1) Time Complexity
    MinStack() {}
    stack<pair<int,int>> s;
   int curr_min = INT_MAX;
   void push(int val) {
		if (!s.empty()) {
			s.push({val, min(val, s.top().second)});
		}
		else {
			s.push({val, val});
		}
	}

	void pop() {
		s.pop();
	}

	int top() {
		return s.top().first;
	}

	int getMin() {
		return s.top().second;
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