class Solution {
public:
    
    int solve(string st, string en, map<string, int>vis, vector<string> bank)
    {
        if(st==en)
        {
            return 0;
        }
        
        if(vis[st]==1)
        {
            return 100;
        }
        
        vis[st] = 1;
        int ans = 100;
        
        for(auto it:bank)
        {
            int cnt=0;
            for(int i=0;i<8;i++)
            {
                if(st[i]!=it[i])
                {
                    cnt++;
                }
            }
            
            if(cnt==1)
            {
                ans = min(ans, solve(it, en, vis, bank));
            }
        }
        
        if(ans!=100)
        {
            ans++;
        }
        return ans;
    }
    
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        
        map<string, int>vis;
        int ans = solve(startGene, endGene, vis, bank);
        
        if(ans==100)
        {
            return -1;
        }
        
        return ans;
    }
};