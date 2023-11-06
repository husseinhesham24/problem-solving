class SeatManager {
public:

    priority_queue<int, vector<int>, greater<>>pq;
    vector<int>v;
    int cnt;
    SeatManager(int n) {
        v.resize(n+1,0);
        cnt = 1;
    }
    
    int reserve() {
        if(!pq.empty())
        {
            int temp = pq.top();
            pq.pop();
            return temp;
        }

        int temp = cnt++;
        v[temp] = 1;
        return temp;
    }
    
    void unreserve(int seatNumber) {
        pq.push(seatNumber);
        v[seatNumber] = 0;
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */