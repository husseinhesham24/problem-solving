class Solution {
public:
    string smallestSubsequence(string s) {
        int cnt[30]={0}, vis[30]={0};
        
        for(auto c:s)
        {
            cnt[c-'a']++;
        }   

        string ans = "";

        for(auto c:s)
        {
            cnt[c-'a']--;
            if(!vis[c-'a'])
            {
                while(ans.size()>0 && ans.back()>c && cnt[ans.back()-'a']>0)
                {
                    vis[ans.back()-'a'] = 0;
                    ans.pop_back();
                }

                vis[c-'a'] = 1;
                ans+=c;
            }
        }

        return ans;
    }
};