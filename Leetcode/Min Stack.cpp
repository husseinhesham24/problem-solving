class MinStack {
public:
    stack<int>s;
    int mini = INT_MAX;
    MinStack() {
        
    }
    
    void push(int val) {
        if(mini>=val)
        {
            s.push(mini);
            mini = val;
        }
        s.push(val);
    }
    
    void pop() {
        if(mini==s.top())
        {
            s.pop();
            mini = s.top();
        }
        s.pop();
        
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return mini;
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