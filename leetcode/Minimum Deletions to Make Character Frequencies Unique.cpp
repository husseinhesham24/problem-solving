class Solution {
public:
    int minDeletions(string s) {
        int ans=0;
        int n = s.size();
        unordered_map<char, int>h;
        vector<pair<int, char>>x;
        sort(s.begin(), s.end());
        x.push_back({1,s[0]});
        h[s[0]]++;
        int j=0;
        for(int i=1;i<n;i++)
        {
            h[s[i]]++;
            if(s[i]!=s[i-1])
            {
                x[j].first = h[s[i-1]];
                x.push_back({1,s[i]});
                j++;
            }
            else if(i==n-1)
            {
                x[j].first = h[s[i-1]];
            }
        }


        sort(x.rbegin(), x.rend());
        // for(auto it:x)
        // {
        //     cout<<it.first<<" "<<it.second<<endl;
        // }

        
        int maxi = x[0].first;
        for(int i=1;i<x.size();i++)
        {
            if(x[i].first>=maxi)
            {
                maxi = maxi>=1?maxi-1:0;
                ans += x[i].first-maxi;
            }
            else
            {
                maxi = x[i].first;
            }
        }

        
        return ans;
    }
};