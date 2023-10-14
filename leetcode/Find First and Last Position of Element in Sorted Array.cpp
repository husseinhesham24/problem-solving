class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>ans(2);
        ans[0] = -1;
        ans[1] = -1;
        bool flag = true;
        for(int i=0;i<nums.size();i++)
        {
            if(flag && nums[i]==target)
            {
                ans[0] = i;
                ans[1] = i;
                flag = false;
            }
            else if(nums[i]==target)
            {
                ans[1] = i;
            }
            else
            {
                continue;
            }
        }

        return ans;
    }
};