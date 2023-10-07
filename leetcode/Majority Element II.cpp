class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int>h;
        vector<int>ans;
        int limit = (nums.size())/3;
        for(auto it:nums)
        {
            h[it]++;
        }

        for(auto it:h)
        {
            if(it.second>limit)
            {
                ans.push_back(it.first);
            }
        }

        return ans;
    }
};