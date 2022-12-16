class MyQueue {
public:
    MyQueue() {
        
    }
    //We will use two stacks
    
    stack<int> so;
    stack<int> st;
    
    void push(int x) {
        so.push(x);
    }
    
    int pop() {
        while(so.size()!=0){
            int x = so.top();
            st.push(x);
            so.pop();
        }
        int y = st.top();
        st.pop();
        while(st.size()!=0){
            int x = st.top();
            so.push(x);
            st.pop();
        }
        return y;
    }
    
    int peek() {
         while(so.size()!=0){
            int x = so.top();
            st.push(x);
            so.pop();
        }
        int y = st.top();
        while(st.size()!=0){
            int x = st.top();
            so.push(x);
            st.pop();
        }
        return y;
    }
    
    bool empty() {
        return (so.size()==0);
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */