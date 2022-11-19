class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        map<string, int>h;
        for(auto it:words)
        {
            h[it]++;
        }
        
        map<string, int>vis;
        int ans=0;
        bool flag = false;
        for(auto it:words)
        {
            if(!vis[it])
            {
                vis[it] = 1;
                string temp = "";
                temp+=it[1];
                temp+=it[0];
                vis[temp] = 1;

                if(it==temp)
                {
                    if(h[it]&1)
                    {
                        flag = true;
                        h[it]--;
                    }
                    
                    ans+=(h[it]*2);
                }
                else
                {
                    ans+=(min(h[it]*2,h[temp]*2)*2);
                }
            }
        }
        
        if(flag)
        {
            ans+=2;
        }
        return ans;
    }
};