class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int,int>h;
        for(auto it:nums)
        {
            h[it]++;
        }

        int ans=0;

        for(auto it:h)
        {
            if(it.second>1)
            {
                int n = it.second-1;
                ans+=(((1+n)/2.0)*n);
            }
        }

        return ans;
    }
};