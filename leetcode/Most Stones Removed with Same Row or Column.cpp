class Solution {
public:
    
    unordered_map<int,int>f;
    int island=0;
    
    int find(int x)
    {
        if(!f.count(x))
        {
            f[x] = x;
            island++;
        }
        
        if(f[x]!=x)
        {
            f[x] = find(f[x]);
        }
        
        return f[x];
    }
    
    void uni(int x, int y)
    {
        x = find(x);
        y = find(y);
        
        if(x!=y)
        {
            f[x] = y;
            island--;
        }
    }
    
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        for(int i=0;i<n;i++)
        {
            uni(stones[i][0], ~stones[i][1]);
        }
        
        return n-island;
    }
};