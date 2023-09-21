class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int sum=0;
        for(auto it:nums)
        {
            sum+=it;
        }

        int target = sum-x;

        if(target==0)
        {
            return n;
        }

        int l=0, maxi=0, cur_sum=0;
        for(int r=0;r<n;r++)
        {
            cur_sum+=nums[r];
            while(l<=r && cur_sum>target)
            {
                cur_sum-=nums[l++];
            }
            if(cur_sum==target)
            {
                maxi = max(maxi, r-l+1);
            }
        }

        return maxi?n-maxi:-1;
    }
};