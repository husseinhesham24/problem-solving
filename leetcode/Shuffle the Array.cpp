class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int>ans;
        for(int i=0, j=n;j<nums.size();i++,j++)
        {
            ans.push_back(nums[i]);
            ans.push_back(nums[j]);
        }
        return ans;
    }
};