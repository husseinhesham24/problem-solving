class Solution {
public:

    static bool cmp(pair<int,int>&a, pair<int,int>&b)
    {
        if(a.first==b.first)
        {
            return a.second<b.second;
        }
        return a.first<b.first;
    }

    vector<int> sortByBits(vector<int>& arr) {
        vector<pair<int,int>>x;
        for(auto it:arr)
        {
            x.push_back({__builtin_popcount(it),it});
        }
        
        sort(x.begin(),x.end(),cmp);
        vector<int>ans;
        for(auto it:x)
        {
            ans.push_back(it.second);
        }
        
        return ans;
    }
};