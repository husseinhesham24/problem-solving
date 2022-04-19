class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        set<vector<int>>ss;
        sort(nums.begin(), nums.end());
        for(int i=0;i<n;i++)
        {
            int j=i+1;
            int k=n-1;
            while(j<k)
            {
                
                if(nums[i]+nums[j]+nums[k]==0)
                {
                    vector<int>temp = {nums[i],nums[j],nums[k]};
                    ss.insert(temp);
                    j++;
                    k--;
                }
                else if(nums[i]+nums[j]+nums[k]>0)
                {
                    k--;
                }
                else
                {
                    j++;
                }
            }
        }
        
        for(auto it:ss)
        {
            ans.push_back(it);
        }
        return ans;
    }
};