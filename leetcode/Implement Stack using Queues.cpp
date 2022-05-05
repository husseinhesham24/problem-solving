class MyStack {
public:
    queue<int>q,tmp;
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
    }
    
    int pop() {
        int n=0;
        int last=0;
        while(!q.empty())
        {
            n++;
            last = q.front();
            tmp.push(last);
            q.pop();
        }
        
        int i=0;
        while(!tmp.empty())
        {
            i++;
            if(i<n)
            {
                q.push(tmp.front());
            }
            tmp.pop();
        }
        return last;
    }
    
    int top() {
        int n=0;
        int last=0;
        while(!q.empty())
        {
            n++;
            last = q.front();
            tmp.push(last);
            q.pop();
        }
        
        int i=0;
        while(!tmp.empty())
        {
            q.push(tmp.front());
            tmp.pop();
        }
        return last;
    }
    
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */