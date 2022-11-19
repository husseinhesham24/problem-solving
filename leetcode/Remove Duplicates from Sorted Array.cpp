class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int ans = 1;
        int last = nums[0];
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]!=last)
            {
                last = nums[i];
                nums[ans++] = last; 
            }
        }
        return ans;
    }
};