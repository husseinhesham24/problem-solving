class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<long long  ,long long>h;
        int n = nums.size();
        long long ans=0;
        long long maxi=0;
        for(int i=0;i<n;i++)
        {
            h[nums[i]]++;
            if(maxi<h[nums[i]])
            {
                maxi = h[nums[i]];
                ans = nums[i];
            }
        }
        return ans;
    }
};