class Solution {
public:
    void sortColors(vector<int>& nums) {
        int num0=0, num1=0, num2=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
            {
                num0++;
            }
            else if(nums[i]==1)
            {
                num1++;
            }
            else
            {
                num2++;
            }
        }
        for(int i=0;i<nums.size();i++)
        {
            if(num0>0)
            {
                nums[i] = 0;
                num0--;
            }
            else if(num1>0)
            {
                nums[i] = 1;
                num1--;
            }
            else
            {
                nums[i] = 2;
                num2--;
            }
        }
    }
};