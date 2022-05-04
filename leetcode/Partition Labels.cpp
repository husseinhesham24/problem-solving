class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int>h;
        unordered_map<char, int>vis;
        int n = s.size();
        for(int i=0;i<n;i++)
        {
            h[s[i]]++;
        }
        int cnt=0;
        int sum=0;
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            h[s[i]]--;
            sum++;
            if(!vis[s[i]])
            {
                vis[s[i]] = 1;
                cnt += h[s[i]];
            }
            else
            {
                if(cnt>0)
                {
                    cnt--;
                }
            }
            if(cnt==0)
            {
                ans.push_back(sum);
                sum = 0;
            }
        }
        return ans;
    }
};