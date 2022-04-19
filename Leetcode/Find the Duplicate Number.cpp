class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int sum=0;
        int n = nums.size();
        int ans;
        unordered_map<int ,int>mp;
        for(int i=0;i<n;i++)
        {
            mp[nums[i]]++;
            if(mp[nums[i]]==2)
            {
                ans = nums[i];
                break;
            }
        }
        return ans;
    }
};