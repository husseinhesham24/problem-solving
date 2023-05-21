class Solution {
public:
    int compress(vector<char>& chars) {
        int cnt=0;
        string ans;
        int n = chars.size();
        char c = chars[0];
        cnt++;
        ans+=chars[0];

        for(int i=1;i<n;i++)
        {
            if(c!=chars[i])
            {
                if(cnt>1)
                {
                    ans+=to_string(cnt);
                }
                ans+=chars[i];
                cnt = 1;
                c = chars[i];
            }
            else
            {
                cnt++;
            }
        }
        
        if(n>1 && chars[n-1]==chars[n-2])
        {
            if(cnt>1)
            {
                ans+=to_string(cnt);
            }
        }

        for(int i=0;i<ans.size();i++)
        {
            chars[i] = ans[i];
        }
        return ans.size();
    }
};