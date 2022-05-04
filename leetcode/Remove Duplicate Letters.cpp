class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char, int>cnt;
        unordered_map<char, int>vis;
        string ans = "";
        for(auto it:s)
        {
            cnt[it]++;
        }
        
        for(auto it:s)
        {
            cnt[it]--;
            if(!vis[it])
            {
                while(ans.size()>0 && ans.back()>it && cnt[ans.back()]>0)
                {
                    vis[ans.back()] = 0;
                    ans.pop_back();
                }
                ans+=it;
                vis[it] = 1;
            }
        }
        
        return ans;
    }
};