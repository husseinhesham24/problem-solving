class FreqStack {
public:
    #define tu tuple<int ,int, int>
    priority_queue<tu>pq;
    unordered_map<int ,int>mp;
    int pos=0;
    FreqStack() {
        
    }
    
    void push(int val) {
        mp[val]++;
        pq.emplace(mp[val], pos++ ,val);
    }
    
    int pop() {
        auto [first,second,third] = pq.top();
        pq.pop();
        mp[third]--;
        return third;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */895. Maximum Frequency Stack
