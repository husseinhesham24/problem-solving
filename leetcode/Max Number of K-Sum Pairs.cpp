class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int,int>h;
        int n = nums.size();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            h[nums[i]]++;
        }
        
        for(int i=0;i<n;i++)
        {
            if(nums[i]<k && h[nums[i]]>0 && h[k-nums[i]]>0)
            {
                int mini = min(h[nums[i]], h[k-nums[i]]);
                if(nums[i]==k-nums[i])
                {
                    mini/=2;
                    h[nums[i]]-=(mini*2);
                }
                else
                {
                    h[nums[i]]-=mini;
                    h[k-nums[i]]-=mini;
                }
                
                ans +=mini;
            }
        }
        
        return ans;
    }
};