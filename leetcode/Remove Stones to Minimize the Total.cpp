class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int>pq;
        int ans=0;
        for(auto it:piles)
        {
            pq.push(it);
            ans+=it;
        }
        
        while(k-- && pq.top()>0)
        {
            int temp = pq.top();
            pq.pop();
            ans -= floor(temp/2);
            pq.push(temp-floor(temp/2));
        }
        
        return ans;
    }
};