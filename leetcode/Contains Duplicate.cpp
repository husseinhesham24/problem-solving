class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int>h;
        for(auto i:nums)
        {
            h[i]++;
            if(h[i]==2)
            {
                return true;
            }
        }
        return false;
    }
};