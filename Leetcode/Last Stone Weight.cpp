class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq;
        int n = stones.size();
        for(int i=0;i<n;i++)
        {
            pq.push(stones[i]);
        }
        
        while(pq.size()>1)
        {
            int x = pq.top();
            pq.pop();
            
            int y = pq.top();
            pq.pop();
            
            if(x==y)
            {
                continue;
            }
            else if(x<y)
            {
                y-=x;
                pq.push(y);
            }
            else
            {
                x-=y;
                pq.push(x);
            }
        }
        
        if(pq.empty())
        {
            return 0;
        }
        
        return pq.top();
    }
};