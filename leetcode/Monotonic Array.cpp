class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int n = nums.size();
        if(n<=2)
        {
            return true;
        }

        int flag=-1;

        for(int i=1;i<n;i++)
        {
            if(nums[i-1]!=nums[i])
            {
                if(flag==-1)
                {
                    if(nums[i-1]<nums[i])
                    {
                        flag = 0;
                    }
                    else
                    {
                        flag = 1;
                    }
                }
                else if(flag==0)
                {
                    if(nums[i-1]>nums[i])
                    {
                        return false;
                    }
                }
                else
                {
                    if(nums[i-1]<nums[i])
                    {
                        return false;
                    }
                }

            }
        }

        return true;
    }
};